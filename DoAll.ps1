#Requires -Version 7.0

param
(
    [switch]$Clean,

    [switch]$ExcludePackages,

    [switch]$ExcludeSamples,

    [switch]$ExcludeTests,

    [switch]$SkipInstallTools,

    [ValidateSet("crossarch", "x64", "x86", "arm64")]
    [string]
    $arch = "crossarch"
)

# Run this script so it throws if VS isn't installed with the required workloads.
& "$PSScriptRoot\scripts\Get-VSPath.ps1" | Out-Null

if ($Clean.IsPresent)
{
    .\scripts\CleanOutputs.ps1
}

if (!$SkipInstallTools.IsPresent)
{
    . .\scripts\CommonUtils.ps1

    Install-BuildTools -Clean:$Clean.IsPresent
}

dotnet build generation/WDK

if (!$ExcludePackages)
{
    .\scripts\DoPackages.ps1 -SkipInstallTools
}