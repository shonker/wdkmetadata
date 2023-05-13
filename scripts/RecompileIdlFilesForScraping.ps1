. "$PSScriptRoot\CommonUtils.ps1"

$cppPkgPath = Get-WinSdkCppPkgPath
$sdkBinDir = "$cppPkgPath\c\bin\$([System.IO.Path]::GetFileName($cppPkgPath) -replace "\d+$", "0")\x86"
$wdkIncludeDir = "$PSScriptRoot\..\generation\WDK\IdlHeaders"
$midl = Join-Path $sdkBinDir "midl.exe"
if (!(Test-Path $sdkBinDir)) {
    Write-Error "Couldn't find $sdkBinDir."
    exit -1
}
if (!(Test-Path $wdkIncludeDir)) {
    Write-Error "Couldn't find $wdkIncludeDir."
    exit -1
}

$vcDirPath = Get-VcDirPath -Arch x86 -HostArch x86
if (!$env:Path.Contains($vcDirPath)) {
    $env:Path += ";$vcDirPath"
}

Write-Host "Cleaning $recompiledIdlHeadersDir and $recompiledIdlHeadersScratchDir..."
Reset-Directory $recompiledIdlHeadersDir
Reset-Directory $recompiledIdlHeadersScratchDir

Write-Host "Copying WDK headers from $wdkIncludeDir to $recompiledIdlHeadersDir..."
Copy-Item "$wdkIncludeDir\um" "$recompiledIdlHeadersDir" -Recurse
Copy-Item "$wdkIncludeDir\km" "$recompiledIdlHeadersDir" -Recurse
Copy-Item "$wdkIncludeDir\shared" "$recompiledIdlHeadersDir" -Recurse
Copy-Item "$wdkIncludeDir\winrt" "$recompiledIdlHeadersDir" -Recurse
Copy-Item "$wdkIncludeDir\ucrt" "$recompiledIdlHeadersDir" -Recurse

Write-Host "Converting MIDL attributes to SAL annotations..."
$idlFilesToRecompile = [System.Collections.ArrayList]@()
$idlFilesToExclude = "cellularapi_oem", "certbcli", "dxgicommon", "dxgitype", "microsoft.diagnostics.appanalysis", "PortableDeviceConnectImports", "wincrypt" | ForEach-Object { "$_.idl" }
Get-ChildItem "$recompiledIdlHeadersDir\um\*.idl", "$recompiledIdlHeadersDir\km\*.idl", "$recompiledIdlHeadersDir\shared\*.idl" -Exclude $idlFilesToExclude | ForEach-Object {
    # Convert MIDL attributes to SAL annotations in all IDL files. Some IDL files are included in others like strmif.idl.
    & $PSScriptRoot\ConvertMidlAttributesToSalAnnotations.ps1 $_.FullName (Join-Path $recompiledIdlHeadersScratchDir $_.Name)

    # Queue IDL files for recompilation only if they have corresponding headers that were generated by MIDL.
    $idlHeader = [System.IO.Path]::ChangeExtension($_.FullName, "h")
    if ((Test-Path $idlHeader) -and (Select-String "File created by MIDL compiler" $idlHeader -Quiet -SimpleMatch)) {
        $idlFilesToRecompile.Add($_) | Out-Null
    }
}

$ErrorActionPreference = "Continue"

Write-Host "Recompiling MIDL headers with SAL annotations into $recompiledIdlHeadersDir..."
$idlFilesToRecompile | ForEach-Object -ThrottleLimit ([System.Math]::Max([System.Environment]::ProcessorCount / 2, 2)) -Parallel {
    $inputFileName = (Join-Path $using:recompiledIdlHeadersScratchDir $_.Name).ToLowerInvariant()
    $outputHeader = [System.IO.Path]::ChangeExtension($inputFileName, "h")
    $outputLog = [System.IO.Path]::ChangeExtension($inputFileName, "txt")

    & $using:midl $inputFileName /out $using:recompiledIdlHeadersScratchDir /header $outputHeader /no_warn /DUNICODE /D_UNICODE /DWINVER=0x0A00 -D_APISET_MINWIN_VERSION=0x010F /DNTDDI_VERSION=0x0A00000C /DBUILD_UMS_ENABLED=0 /DBUILD_WOW64_ENABLED=0 /DBUILD_ARM64X_ENABLED=0 /DEXECUTABLE_WRITES_SUPPORT=0 -D_USE_DECLSPECS_FOR_SAL=1 -D_CONTROL_FLOW_GUARD_SVCTAB=1 -DMIDL_PASS=1 /Di386 /D_X86_ /D_WCHAR_T_DEFINED /no_stamp /nologo /no_settings_comment /lcid 1033 /sal /win32 /target NT100 /Zp8 /I$using:recompiledIdlHeadersScratchDir /I$using:wdkIncludeDir\um /I$using:wdkIncludeDir\km /I$using:wdkIncludeDir\shared /I$using:wdkIncludeDir\winrt /I"$using:PSScriptRoot\inc" 3>&1 2>&1 > $outputLog
    
    if ($LASTEXITCODE -ne 0) {
        Write-Error "Failed for $($_.FullName)`n$(Get-Content $outputLog -Raw)"
    } else {
        Write-Host "Compiled $($_.Name)"

        # This line gets pulled out in the Windows build of the header otherwise it won't compile.
        if ($_.BaseName -eq "d3d10_1") {
            (Get-Content $outputHeader -Raw).Replace("#include ""d3d10.h""`r`n", "") | Set-Content $outputHeader
        }

        Copy-Item $outputHeader ([System.IO.Path]::ChangeExtension($_.FullName, "h"))
    }
}

$ErrorActionPreference = "Stop"