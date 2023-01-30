// Copyright (C) Microsoft Corporation. All rights reserved.
//
// NOTE: This header is generated by stubwork.  Please make any 
//       modifications to the corresponding template files 
//       (.x or .y) and use stubwork to regenerate the header
//

#ifndef _WIFICX_H_
#define _WIFICX_H_

#ifndef WDF_EXTERN_C
  #ifdef __cplusplus
    #define WDF_EXTERN_C       extern "C"
    #define WDF_EXTERN_C_START extern "C" {
    #define WDF_EXTERN_C_END   }
  #else
    #define WDF_EXTERN_C
    #define WDF_EXTERN_C_START
    #define WDF_EXTERN_C_END
  #endif
#endif

WDF_EXTERN_C_START


typedef enum _WIFI_WAKE_REASON_TYPE {
    WifiWakeReasonTypeNloDiscovery = 1,
    WifiWakeReasonTypeApAssociationlost,
    WifiWakeReasonTypeGtkHandshakeError,
    WifiWakeReasonTypeFourWayHandshakeRequest,
} WIFI_WAKE_REASON_TYPE;

typedef enum _WIFI_ADAPTER_TX_DEMUX_TYPE {
    WifiAdapterTxDemuxTypePeerAddress = 2,
    WifiAdapterTxDemuxTypeWmmInfo = 3,
} WIFI_ADAPTER_TX_DEMUX_TYPE;




#include <wificxtypes.h>
#include <wififuncenum.h>
#include <dot11wificxtypes.hpp>
#include <dot11wificxintf.h>

typedef
_Function_class_(EVT_WIFI_DEVICE_SEND_COMMAND)
_IRQL_requires_same_
_IRQL_requires_max_(DISPATCH_LEVEL)
VOID
NTAPI
EVT_WIFI_DEVICE_SEND_COMMAND(
    _In_
    WDFDEVICE Device,
    _In_
    WIFIREQUEST SendRequest
);

typedef EVT_WIFI_DEVICE_SEND_COMMAND *PFN_WIFI_DEVICE_SEND_COMMAND;

typedef
_Function_class_(EVT_WIFI_DEVICE_CREATE_ADAPTER)
_IRQL_requires_same_
_IRQL_requires_max_(PASSIVE_LEVEL)
NTSTATUS
NTAPI
EVT_WIFI_DEVICE_CREATE_ADAPTER(
    _In_
    WDFDEVICE  Device,
    _Inout_
    NETADAPTER_INIT * AdapterInit
);

typedef EVT_WIFI_DEVICE_CREATE_ADAPTER *PFN_WIFI_DEVICE_CREATE_ADAPTER;

typedef
_Function_class_(EVT_WIFI_DEVICE_CREATE_WIFIDIRECTDEVICE)
_IRQL_requires_same_
_IRQL_requires_max_(PASSIVE_LEVEL)
NTSTATUS
NTAPI
EVT_WIFI_DEVICE_CREATE_WIFIDIRECTDEVICE(
    _In_
    WDFDEVICE  Device,
    _Inout_
    WIFIDIRECT_DEVICE_INIT * WifiDirectDeviceInit
);

typedef EVT_WIFI_DEVICE_CREATE_WIFIDIRECTDEVICE *PFN_WIFI_DEVICE_CREATE_WIFIDIRECTDEVICE;

typedef struct _WIFI_DEVICE_CONFIG
{
    ULONG Size;
    
    ULONG WdiVersion;
    PFN_WIFI_DEVICE_SEND_COMMAND SendCommand;
    PFN_WIFI_DEVICE_CREATE_ADAPTER CreateAdapter;
    PFN_WIFI_DEVICE_CREATE_WIFIDIRECTDEVICE CreateWifiDirectDevice;
} WIFI_DEVICE_CONFIG;

FORCEINLINE
VOID
WIFI_DEVICE_CONFIG_INIT(
    _Out_ WIFI_DEVICE_CONFIG * Config,
    _In_ ULONG WdiVersion,
    _In_ PFN_WIFI_DEVICE_SEND_COMMAND SendCommand,
    _In_ PFN_WIFI_DEVICE_CREATE_ADAPTER CreateAdapter,
    _In_ PFN_WIFI_DEVICE_CREATE_WIFIDIRECTDEVICE CreateWifiDirectDevice
)
{
    RtlZeroMemory(Config, sizeof(*Config));
    Config->Size = sizeof(*Config);
    Config->WdiVersion = WdiVersion;
    Config->SendCommand = SendCommand;
    Config->CreateAdapter = CreateAdapter;
    Config->CreateWifiDirectDevice = CreateWifiDirectDevice;
}

#define MAX_FIRMWARE_VERSION_LENGTH 255

typedef struct _WIFI_DEVICE_CAPABILITIES
{
    ULONG Size;

    BOOLEAN HardwareRadioState; // Whether or not the radio is enabled by hardware
    BOOLEAN SoftwareRadioState; // Whether or not the radio is enabled by software
    UCHAR FirmwareVersion[MAX_FIRMWARE_VERSION_LENGTH];
    BOOLEAN ActionFramesSupported; // {0,1} If sending and receiving actions frames is supported. Yes = 1.
    UINT8 NumRxStreams; // Number of RX spatial streams supported
    UINT8 NumTxStreams; // Number of TX spatial streams supported
    BOOLEAN Support_eCSA; // Whether the adapter supports eCSA
    BOOLEAN MACAddressRandomization; // Whether the adapter supports MAC Address Randomization. Yes = 1.
    WDI_MAC_ADDRESS MACAddressRandomizationMask; // MAC Address Randomization contraints for some hardware.
    WDI_BLUETOOTH_COEXISTENCE_SUPPORT BluetoothCoexistenceSupport; // Bluetooth Coexistence support.
    BOOLEAN SupportsNonWdiOidRequests; // Whether the adapter can handle non-WDI OIDs
    BOOLEAN FastTransitionSupported; // Whether the adapter can do Fast-Transition association
    BOOLEAN MU_MIMOSupported; // Whether the adapter supports MU_MIMO
    BOOLEAN BSSTransitionSupported; // True if the device supports BSS Transition frames
    BOOLEAN SAEAuthenticationSupported; // True if the device supports SAE Authentication Capability
    BOOLEAN MBOSupported; // True if the device supports MBO
    BOOLEAN BeaconReportsImplemented; // True if the device handles beacon report measurement
} WIFI_DEVICE_CAPABILITIES;

#define MAX_SIMULTANEOUS_BAND_CONNECTIONS_ALLOWED 4

typedef struct
{
    UINT8 NumStaBands;
    WDI_BAND_ID BandIDs[MAX_SIMULTANEOUS_BAND_CONNECTIONS_ALLOWED];
} WIFI_STA_BANDS_COMBINATION;

typedef struct _WIFI_STATION_CAPABILITIES
{
    ULONG Size;

    UINT32 ScanSSIDListSize; // Scan SSID List size
    UINT32 DesiredSSIDListSize; // Desired SSID List size
    UINT32 PrivacyExemptionListSize; // Privacy Exemption List size
    UINT32 KeyMappingTableSize; // Key Mapping List size
    UINT32 DefaultKeyTableSize; // Default Key table size
    UINT32 WEPKeyValueMaxLength; // WEP Key value Max length
    UINT32 MaxNumPerSTA; // Max num per STA Default key tables
    UINT8 SupportedQOSFlags; // Whether or not WMM QOS is supported
    UINT8 HostFIPSModeImplemented; // Whether or not host FIPS mode is supported
    UINT8 MFPCapable; // Whether or not MFP is supported
    BOOLEAN AutoPowerSaveMode; // {0,1} if Auto Power Save is supported. Yes = 1.
    BOOLEAN BSSListCachemanagement; // {0,1} If the adapter would maintain the Station BSS List cache. Yes = 1
    BOOLEAN ConnectBSSSelectionOverride; // {0,1} If on a Station connect the adapter may attempt association to a BSSID that is not specified in the Preferred BSSID list. Yes = 1
    UINT32 MaxNetworkOffloadListSize; // Support number of Network Offload entries
    BOOLEAN HESSIDConnectionSupported; // {0,1} If ability to connect to HESSIDs is supported. Yes = 1.
    BOOLEAN FTMAsInitiatorSupport; // {0,1} If FTM procedures as Initiator are supported. Yes = 1.
    UINT32 FTMNumberOfSupportedTargets; // Number of target STAs supported per FTM request task.
    BOOLEAN HostWPA3FIPSModeEnabled; // Host-FIPS mode for WPA3 is enabled or not
    ULONG NumSupportedUnicastAlgorithms;
    PDOT11_AUTH_CIPHER_PAIR UnicastAlgorithmsList;
    ULONG NumSupportedMulticastDataAlgorithms;
    PDOT11_AUTH_CIPHER_PAIR MulticastDataAlgorithmsList;
    ULONG NumSupportedMulticastMgmtAlgorithms;
    PDOT11_AUTH_CIPHER_PAIR MulticastMgmtAlgorithmsList;
    ULONG NumSecondaryStaBandCombinations;
    WIFI_STA_BANDS_COMBINATION * SecondaryStaBandsCombinations;
} WIFI_STATION_CAPABILITIES;

typedef struct _WIFI_WIFIDIRECT_CAPABILITIES
{
    ULONG Size;

    UINT8 WFDRoleCount; // Number of supported Wi-Fi Direct Role Ports
    UINT8 ConcurrentGOCount; // Concurrent GO Count
    UINT8 ConcurrentClientCount; // Concurrent Client Count
    BOOLEAN ServiceDiscoverySupported; // Service Discovery Supported
    BOOLEAN ServiceNameDiscoverySupported; // Service Name Discovery Supported
    BOOLEAN ServiceInformationDiscoverySupported; // {0,1} If ability to probe for P2P Service information using GAS protocol is supported. Yes = 1.
    UINT32 ServiceNameAdvertisementsMaxBytesSupported; // Maximum bytes of Service Name Advertisements using GAS protocol supported. If not supported, 0.
    UINT32 ServiceInformationAdvertisementsMaxBytesSupported; // Maximum bytes of Service Information Advertisements using GAS protocol supported. If not supported, 0.
    BOOLEAN BackgroundDiscoverySupported; // {0,1} If ability to discover P2P Services in the background is supported. Yes = 1.
    BOOLEAN ClientDiscoverabilitySupported; // Client Discoverability Supported
    BOOLEAN InfrastructureManagementSupported; // Infrastructure Management Supported
    UINT8 DeviceAddress[6]; // Device address
    UINT32 DiscoveryFilterListSize; // Discovery Filter List Size
    UINT8 GOClientTableSize; // GO Client Table Size
    UINT32 MaxVendorSpecificExtensionIESize; // Max bytes of Vendor specific IEs that can be added to WFD management frames
    BOOLEAN PassiveAvailabilityListenStateSupported; // {0,1} If ability to listen for P2P Services in the background is supported. Yes = 1.
    BOOLEAN OperatingChannelUpdatesSupported; // Whether the adapter supported indicating updates to the GO operating channel(s). No = 0
    BOOLEAN GOon5GHzBandSupported; // Whether the adapter supports operating a GO on 5GHz band. No = 0
    UINT32 ScanSSIDListSize; // Scan SSID List size
    UINT32 DesiredSSIDListSize; // Desired SSID List size
    UINT32 PrivacyExemptionListSize; // Privacy Exemption List size
    UINT32 AssociationTableSize; // Association Table Size
    UINT32 DefaultKeyTableSize; // Default Key table size
    UINT32 WEPKeyValueMaxLength; // WEP Key value Max length
    UINT32 NumSupportedUnicastAlgorithms;
    PDOT11_AUTH_CIPHER_PAIR UnicastAlgorithms;
    UINT32 NumSupportedMulticastDataAlgorithms;
    PDOT11_AUTH_CIPHER_PAIR MulticastDataAlgorithms;
    UINT32 NumInterfaceAddresses;
    WDI_MAC_ADDRESS * InterfaceAddressList;
} WIFI_WIFIDIRECT_CAPABILITIES;

typedef struct _WIFI_BAND_INFO
{
    WDI_BAND_ID BandID;
    BOOLEAN BandState;
    ULONG NumValidPhyTypes;
    WDI_PHY_TYPE * ValidPhyTypeList;
    ULONG NumValidChannelTypes;
    WDI_CHANNEL_MAPPING_ENTRY * ValidChannelTypes;
    ULONG NumChannelWidths;
    UINT32 * ChannelWidthList;
} WIFI_BAND_INFO;

typedef struct _WIFI_BAND_CAPABILITIES
{
    ULONG Size;

    ULONG NumBands;
    WIFI_BAND_INFO * BandInfoList;
} WIFI_BAND_CAPABILITIES;

typedef struct _WIFI_PHY_INFO
{
    WDI_PHY_TYPE PhyType;
    SIZE_T NumberDataRateEntries;
    WDI_DATA_RATE_ENTRY DataRateList[WDI_MAX_DATA_RATE_ENTRIES];
} WIFI_PHY_INFO;

typedef struct _WIFI_PHY_CAPABILITIES
{
    ULONG Size;

    ULONG NumPhyTypes;
    WIFI_PHY_INFO * PhyInfoList;
} WIFI_PHY_CAPABILITIES;

typedef struct _WIFI_ADAPTER_POWER_OFFLOAD_RSN_REKEY_CAPABILITIES
{
    ULONG Size;
    BOOLEAN Enabled;
} WIFI_ADAPTER_POWER_OFFLOAD_RSN_REKEY_CAPABILITIES;

typedef enum _WIFI_ADAPTER_TYPE
{
    WIFI_ADAPTER_EXTENSIBLE_STATION = 1,
    WIFI_ADAPTER_WIFI_DIRECT_ROLE,
    WIFI_ADAPTER_SECONDARY_STATION,
} WIFI_ADAPTER_TYPE;

FORCEINLINE
void
WIFI_ADAPTER_POWER_OFFLOAD_RSN_REKEY_CAPABILITIES_INIT(
    _Out_ WIFI_ADAPTER_POWER_OFFLOAD_RSN_REKEY_CAPABILITIES * Capabilities
)
{
    RtlZeroMemory(Capabilities, sizeof(*Capabilities));
    Capabilities->Size = sizeof(*Capabilities);
    Capabilities->Enabled = TRUE;
}

typedef struct _WIFI_ADAPTER_WAKE_CAPABILITIES
{
    ULONG Size;
    BOOLEAN NloDiscovery;
    BOOLEAN ApAssociationLost;
    BOOLEAN GtkHandshakeError;
    BOOLEAN FourWayHandshakeRequest;
} WIFI_ADAPTER_WAKE_CAPABILITIES;

inline
void
WIFI_ADAPTER_WAKE_CAPABILITIES_INIT(
    _Out_ WIFI_ADAPTER_WAKE_CAPABILITIES * Capabilities
)
{
    RtlZeroMemory(Capabilities, sizeof(*Capabilities));
    Capabilities->Size = sizeof(*Capabilities);
}

typedef struct _WIFI_ADAPTER_TX_DEMUX
{
    ULONG
        Size;

    WIFI_ADAPTER_TX_DEMUX_TYPE
        Type;

    UINT8
        Range;

} WIFI_ADAPTER_TX_DEMUX;

inline
void
WIFI_ADAPTER_TX_PEER_ADDRESS_DEMUX_INIT(
    _Out_ WIFI_ADAPTER_TX_DEMUX * Demux,
    _In_ UINT8 Range
)
{
    RtlZeroMemory(Demux, sizeof(*Demux));
    Demux->Size = sizeof(*Demux);
    Demux->Type = WifiAdapterTxDemuxTypePeerAddress;
    Demux->Range = Range;
}

inline
void
WIFI_ADAPTER_TX_WMMINFO_DEMUX_INIT(
    _Out_ WIFI_ADAPTER_TX_DEMUX * Demux
)
{
    RtlZeroMemory(Demux, sizeof(*Demux));
    Demux->Size = sizeof(*Demux);
    Demux->Type = WifiAdapterTxDemuxTypeWmmInfo;
    Demux->Range = 8;
}


//
// WIFI Function: WifiDeviceInitConfig
//
typedef
_IRQL_requires_max_(PASSIVE_LEVEL)
WDFAPI
NTSTATUS
(NTAPI *PFN_WIFIDEVICEINITCONFIG)(
    _In_
    PWIFI_DRIVER_GLOBALS DriverGlobals,
    _Inout_
    PWDFDEVICE_INIT DeviceInit
    );

_IRQL_requires_max_(PASSIVE_LEVEL)
FORCEINLINE
NTSTATUS
WifiDeviceInitConfig(
    _Inout_
    PWDFDEVICE_INIT DeviceInit
    )
{
    return ((PFN_WIFIDEVICEINITCONFIG) WifiFunctions[WifiDeviceInitConfigTableIndex])(WifiDriverGlobals, DeviceInit);
}

//
// WIFI Function: WifiDeviceGetOsWdiVersion
//
typedef
_IRQL_requires_max_(PASSIVE_LEVEL)
WDFAPI
ULONG
(NTAPI *PFN_WIFIDEVICEGETOSWDIVERSION)(
    _In_
    PWIFI_DRIVER_GLOBALS DriverGlobals,
    _In_
    WDFDEVICE Device
    );

_IRQL_requires_max_(PASSIVE_LEVEL)
FORCEINLINE
ULONG
WifiDeviceGetOsWdiVersion(
    _In_
    WDFDEVICE Device
    )
{
    return ((PFN_WIFIDEVICEGETOSWDIVERSION) WifiFunctions[WifiDeviceGetOsWdiVersionTableIndex])(WifiDriverGlobals, Device);
}

//
// WIFI Function: WifiDeviceSetDeviceCapabilities
//
typedef
_IRQL_requires_max_(PASSIVE_LEVEL)
WDFAPI
NTSTATUS
(NTAPI *PFN_WIFIDEVICESETDEVICECAPABILITIES)(
    _In_
    PWIFI_DRIVER_GLOBALS DriverGlobals,
    _In_
    WDFDEVICE Device,
    _In_
    CONST WIFI_DEVICE_CAPABILITIES* DeviceCapabilities
    );

_IRQL_requires_max_(PASSIVE_LEVEL)
FORCEINLINE
NTSTATUS
WifiDeviceSetDeviceCapabilities(
    _In_
    WDFDEVICE Device,
    _In_
    CONST WIFI_DEVICE_CAPABILITIES* DeviceCapabilities
    )
{
    return ((PFN_WIFIDEVICESETDEVICECAPABILITIES) WifiFunctions[WifiDeviceSetDeviceCapabilitiesTableIndex])(WifiDriverGlobals, Device, DeviceCapabilities);
}

//
// WIFI Function: WifiDeviceSetStationCapabilities
//
typedef
_IRQL_requires_max_(PASSIVE_LEVEL)
WDFAPI
NTSTATUS
(NTAPI *PFN_WIFIDEVICESETSTATIONCAPABILITIES)(
    _In_
    PWIFI_DRIVER_GLOBALS DriverGlobals,
    _In_
    WDFDEVICE Device,
    _In_
    CONST WIFI_STATION_CAPABILITIES* StationCapabilities
    );

_IRQL_requires_max_(PASSIVE_LEVEL)
FORCEINLINE
NTSTATUS
WifiDeviceSetStationCapabilities(
    _In_
    WDFDEVICE Device,
    _In_
    CONST WIFI_STATION_CAPABILITIES* StationCapabilities
    )
{
    return ((PFN_WIFIDEVICESETSTATIONCAPABILITIES) WifiFunctions[WifiDeviceSetStationCapabilitiesTableIndex])(WifiDriverGlobals, Device, StationCapabilities);
}

//
// WIFI Function: WifiDeviceSetWiFiDirectCapabilities
//
typedef
_IRQL_requires_max_(PASSIVE_LEVEL)
WDFAPI
NTSTATUS
(NTAPI *PFN_WIFIDEVICESETWIFIDIRECTCAPABILITIES)(
    _In_
    PWIFI_DRIVER_GLOBALS DriverGlobals,
    _In_
    WDFDEVICE Device,
    _In_
    CONST WIFI_WIFIDIRECT_CAPABILITIES* WiFiDirectCapabilities
    );

_IRQL_requires_max_(PASSIVE_LEVEL)
FORCEINLINE
NTSTATUS
WifiDeviceSetWiFiDirectCapabilities(
    _In_
    WDFDEVICE Device,
    _In_
    CONST WIFI_WIFIDIRECT_CAPABILITIES* WiFiDirectCapabilities
    )
{
    return ((PFN_WIFIDEVICESETWIFIDIRECTCAPABILITIES) WifiFunctions[WifiDeviceSetWiFiDirectCapabilitiesTableIndex])(WifiDriverGlobals, Device, WiFiDirectCapabilities);
}

//
// WIFI Function: WifiDeviceSetBandCapabilities
//
typedef
_IRQL_requires_max_(PASSIVE_LEVEL)
WDFAPI
NTSTATUS
(NTAPI *PFN_WIFIDEVICESETBANDCAPABILITIES)(
    _In_
    PWIFI_DRIVER_GLOBALS DriverGlobals,
    _In_
    WDFDEVICE Device,
    _In_
    CONST WIFI_BAND_CAPABILITIES* BandCapabilities
    );

_IRQL_requires_max_(PASSIVE_LEVEL)
FORCEINLINE
NTSTATUS
WifiDeviceSetBandCapabilities(
    _In_
    WDFDEVICE Device,
    _In_
    CONST WIFI_BAND_CAPABILITIES* BandCapabilities
    )
{
    return ((PFN_WIFIDEVICESETBANDCAPABILITIES) WifiFunctions[WifiDeviceSetBandCapabilitiesTableIndex])(WifiDriverGlobals, Device, BandCapabilities);
}

//
// WIFI Function: WifiDeviceSetPhyCapabilities
//
typedef
_IRQL_requires_max_(PASSIVE_LEVEL)
WDFAPI
NTSTATUS
(NTAPI *PFN_WIFIDEVICESETPHYCAPABILITIES)(
    _In_
    PWIFI_DRIVER_GLOBALS DriverGlobals,
    _In_
    WDFDEVICE Device,
    _In_
    CONST WIFI_PHY_CAPABILITIES* PhyCapabilities
    );

_IRQL_requires_max_(PASSIVE_LEVEL)
FORCEINLINE
NTSTATUS
WifiDeviceSetPhyCapabilities(
    _In_
    WDFDEVICE Device,
    _In_
    CONST WIFI_PHY_CAPABILITIES* PhyCapabilities
    )
{
    return ((PFN_WIFIDEVICESETPHYCAPABILITIES) WifiFunctions[WifiDeviceSetPhyCapabilitiesTableIndex])(WifiDriverGlobals, Device, PhyCapabilities);
}

//
// WIFI Function: WifiDeviceInitialize
//
typedef
_IRQL_requires_max_(PASSIVE_LEVEL)
WDFAPI
NTSTATUS
(NTAPI *PFN_WIFIDEVICEINITIALIZE)(
    _In_
    PWIFI_DRIVER_GLOBALS DriverGlobals,
    _In_
    WDFDEVICE Device,
    _In_
    WIFI_DEVICE_CONFIG* Config
    );

_IRQL_requires_max_(PASSIVE_LEVEL)
FORCEINLINE
NTSTATUS
WifiDeviceInitialize(
    _In_
    WDFDEVICE Device,
    _In_
    WIFI_DEVICE_CONFIG* Config
    )
{
    return ((PFN_WIFIDEVICEINITIALIZE) WifiFunctions[WifiDeviceInitializeTableIndex])(WifiDriverGlobals, Device, Config);
}

//
// WIFI Function: WifiDeviceReceiveIndication
//
typedef
_IRQL_requires_max_(DISPATCH_LEVEL)
WDFAPI
VOID
(NTAPI *PFN_WIFIDEVICERECEIVEINDICATION)(
    _In_
    PWIFI_DRIVER_GLOBALS DriverGlobals,
    _In_
    WDFDEVICE Device,
    _In_
    UINT16 MessageId,
    _In_
    WDFMEMORY Data
    );

_IRQL_requires_max_(DISPATCH_LEVEL)
FORCEINLINE
VOID
WifiDeviceReceiveIndication(
    _In_
    WDFDEVICE Device,
    _In_
    UINT16 MessageId,
    _In_
    WDFMEMORY Data
    )
{
    ((PFN_WIFIDEVICERECEIVEINDICATION) WifiFunctions[WifiDeviceReceiveIndicationTableIndex])(WifiDriverGlobals, Device, MessageId, Data);
}

//
// WIFI Function: WifiAdapterInitialize
//
typedef
_IRQL_requires_max_(PASSIVE_LEVEL)
WDFAPI
NTSTATUS
(NTAPI *PFN_WIFIADAPTERINITIALIZE)(
    _In_
    PWIFI_DRIVER_GLOBALS DriverGlobals,
    _In_
    NETADAPTER Adapter
    );

_IRQL_requires_max_(PASSIVE_LEVEL)
FORCEINLINE
NTSTATUS
WifiAdapterInitialize(
    _In_
    NETADAPTER Adapter
    )
{
    return ((PFN_WIFIADAPTERINITIALIZE) WifiFunctions[WifiAdapterInitializeTableIndex])(WifiDriverGlobals, Adapter);
}

//
// WIFI Function: WifiRequestGetInOutBuffer
//
typedef
_IRQL_requires_max_(DISPATCH_LEVEL)
WDFAPI
PVOID
(NTAPI *PFN_WIFIREQUESTGETINOUTBUFFER)(
    _In_
    PWIFI_DRIVER_GLOBALS DriverGlobals,
    _In_
    WIFIREQUEST Request,
    _Out_opt_
    UINT* InputBufferLength,
    _Out_opt_
    UINT* OutBufferLength
    );

_IRQL_requires_max_(DISPATCH_LEVEL)
FORCEINLINE
PVOID
WifiRequestGetInOutBuffer(
    _In_
    WIFIREQUEST Request,
    _Out_opt_
    UINT* InputBufferLength,
    _Out_opt_
    UINT* OutBufferLength
    )
{
    return ((PFN_WIFIREQUESTGETINOUTBUFFER) WifiFunctions[WifiRequestGetInOutBufferTableIndex])(WifiDriverGlobals, Request, InputBufferLength, OutBufferLength);
}

//
// WIFI Function: WifiRequestGetMessageId
//
typedef
_IRQL_requires_max_(DISPATCH_LEVEL)
WDFAPI
UINT16
(NTAPI *PFN_WIFIREQUESTGETMESSAGEID)(
    _In_
    PWIFI_DRIVER_GLOBALS DriverGlobals,
    _In_
    WIFIREQUEST Request
    );

_IRQL_requires_max_(DISPATCH_LEVEL)
FORCEINLINE
UINT16
WifiRequestGetMessageId(
    _In_
    WIFIREQUEST Request
    )
{
    return ((PFN_WIFIREQUESTGETMESSAGEID) WifiFunctions[WifiRequestGetMessageIdTableIndex])(WifiDriverGlobals, Request);
}

//
// WIFI Function: WifiRequestSetBytesNeeded
//
typedef
_IRQL_requires_max_(DISPATCH_LEVEL)
WDFAPI
VOID
(NTAPI *PFN_WIFIREQUESTSETBYTESNEEDED)(
    _In_
    PWIFI_DRIVER_GLOBALS DriverGlobals,
    _In_
    WIFIREQUEST Request,
    _In_
    UINT BytesNeeded
    );

_IRQL_requires_max_(DISPATCH_LEVEL)
FORCEINLINE
VOID
WifiRequestSetBytesNeeded(
    _In_
    WIFIREQUEST Request,
    _In_
    UINT BytesNeeded
    )
{
    ((PFN_WIFIREQUESTSETBYTESNEEDED) WifiFunctions[WifiRequestSetBytesNeededTableIndex])(WifiDriverGlobals, Request, BytesNeeded);
}

//
// WIFI Function: WifiRequestComplete
//
typedef
_IRQL_requires_max_(DISPATCH_LEVEL)
WDFAPI
VOID
(NTAPI *PFN_WIFIREQUESTCOMPLETE)(
    _In_
    PWIFI_DRIVER_GLOBALS DriverGlobals,
    _In_
    WIFIREQUEST Request,
    _In_
    NTSTATUS NtStatus,
    _In_
    UINT BytesWritten
    );

_IRQL_requires_max_(DISPATCH_LEVEL)
FORCEINLINE
VOID
WifiRequestComplete(
    _In_
    WIFIREQUEST Request,
    _In_
    NTSTATUS NtStatus,
    _In_
    UINT BytesWritten
    )
{
    ((PFN_WIFIREQUESTCOMPLETE) WifiFunctions[WifiRequestCompleteTableIndex])(WifiDriverGlobals, Request, NtStatus, BytesWritten);
}

//
// WIFI Function: WifiAdapterPowerOffloadSetRsnRekeyCapabilities
//
typedef
_IRQL_requires_(PASSIVE_LEVEL)
WDFAPI
VOID
(NTAPI *PFN_WIFIADAPTERPOWEROFFLOADSETRSNREKEYCAPABILITIES)(
    _In_
    PWIFI_DRIVER_GLOBALS DriverGlobals,
    _In_
    NETADAPTER Adapter,
    _In_
    CONST WIFI_ADAPTER_POWER_OFFLOAD_RSN_REKEY_CAPABILITIES* Capabilities
    );

_IRQL_requires_(PASSIVE_LEVEL)
FORCEINLINE
VOID
WifiAdapterPowerOffloadSetRsnRekeyCapabilities(
    _In_
    NETADAPTER Adapter,
    _In_
    CONST WIFI_ADAPTER_POWER_OFFLOAD_RSN_REKEY_CAPABILITIES* Capabilities
    )
{
    ((PFN_WIFIADAPTERPOWEROFFLOADSETRSNREKEYCAPABILITIES) WifiFunctions[WifiAdapterPowerOffloadSetRsnRekeyCapabilitiesTableIndex])(WifiDriverGlobals, Adapter, Capabilities);
}

//
// WIFI Function: WifiAdapterSetWakeCapabilities
//
typedef
_IRQL_requires_(PASSIVE_LEVEL)
WDFAPI
VOID
(NTAPI *PFN_WIFIADAPTERSETWAKECAPABILITIES)(
    _In_
    PWIFI_DRIVER_GLOBALS DriverGlobals,
    _In_
    NETADAPTER Adapter,
    _In_
    CONST WIFI_ADAPTER_WAKE_CAPABILITIES* Capabilities
    );

_IRQL_requires_(PASSIVE_LEVEL)
FORCEINLINE
VOID
WifiAdapterSetWakeCapabilities(
    _In_
    NETADAPTER Adapter,
    _In_
    CONST WIFI_ADAPTER_WAKE_CAPABILITIES* Capabilities
    )
{
    ((PFN_WIFIADAPTERSETWAKECAPABILITIES) WifiFunctions[WifiAdapterSetWakeCapabilitiesTableIndex])(WifiDriverGlobals, Adapter, Capabilities);
}

//
// WIFI Function: WifiAdapterReportWakeReason
//
typedef
_IRQL_requires_max_(PASSIVE_LEVEL)
WDFAPI
VOID
(NTAPI *PFN_WIFIADAPTERREPORTWAKEREASON)(
    _In_
    PWIFI_DRIVER_GLOBALS DriverGlobals,
    _In_
    NETADAPTER Adapter,
    _In_
    WIFI_WAKE_REASON_TYPE Reason
    );

_IRQL_requires_max_(PASSIVE_LEVEL)
FORCEINLINE
VOID
WifiAdapterReportWakeReason(
    _In_
    NETADAPTER Adapter,
    _In_
    WIFI_WAKE_REASON_TYPE Reason
    )
{
    ((PFN_WIFIADAPTERREPORTWAKEREASON) WifiFunctions[WifiAdapterReportWakeReasonTableIndex])(WifiDriverGlobals, Adapter, Reason);
}

//
// WIFI Function: WifiDirectDeviceCreate
//
typedef
_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
WDFAPI
NTSTATUS
(NTAPI *PFN_WIFIDIRECTDEVICECREATE)(
    _In_
    PWIFI_DRIVER_GLOBALS DriverGlobals,
    _In_
    WIFIDIRECT_DEVICE_INIT* WifiDirectDeviceInit,
    _In_opt_
    WDF_OBJECT_ATTRIBUTES* WifiDirectDeviceAttributes,
    _Out_
    WIFIDIRECTDEVICE* WifiDirectDevice
    );

_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
FORCEINLINE
NTSTATUS
WifiDirectDeviceCreate(
    _In_
    WIFIDIRECT_DEVICE_INIT* WifiDirectDeviceInit,
    _In_opt_
    WDF_OBJECT_ATTRIBUTES* WifiDirectDeviceAttributes,
    _Out_
    WIFIDIRECTDEVICE* WifiDirectDevice
    )
{
    return ((PFN_WIFIDIRECTDEVICECREATE) WifiFunctions[WifiDirectDeviceCreateTableIndex])(WifiDriverGlobals, WifiDirectDeviceInit, WifiDirectDeviceAttributes, WifiDirectDevice);
}

//
// WIFI Function: WifiDirectDeviceInitialize
//
typedef
_IRQL_requires_max_(PASSIVE_LEVEL)
WDFAPI
NTSTATUS
(NTAPI *PFN_WIFIDIRECTDEVICEINITIALIZE)(
    _In_
    PWIFI_DRIVER_GLOBALS DriverGlobals,
    _In_
    WIFIDIRECTDEVICE WifiDirectDevice
    );

_IRQL_requires_max_(PASSIVE_LEVEL)
FORCEINLINE
NTSTATUS
WifiDirectDeviceInitialize(
    _In_
    WIFIDIRECTDEVICE WifiDirectDevice
    )
{
    return ((PFN_WIFIDIRECTDEVICEINITIALIZE) WifiFunctions[WifiDirectDeviceInitializeTableIndex])(WifiDriverGlobals, WifiDirectDevice);
}

//
// WIFI Function: WifiAdapterGetPortId
//
typedef
_IRQL_requires_max_(PASSIVE_LEVEL)
WDFAPI
ULONG
(NTAPI *PFN_WIFIADAPTERGETPORTID)(
    _In_
    PWIFI_DRIVER_GLOBALS DriverGlobals,
    _In_
    NETADAPTER Adapter
    );

_IRQL_requires_max_(PASSIVE_LEVEL)
FORCEINLINE
ULONG
WifiAdapterGetPortId(
    _In_
    NETADAPTER Adapter
    )
{
    return ((PFN_WIFIADAPTERGETPORTID) WifiFunctions[WifiAdapterGetPortIdTableIndex])(WifiDriverGlobals, Adapter);
}

//
// WIFI Function: WifiAdapterInitGetType
//
typedef
_IRQL_requires_max_(PASSIVE_LEVEL)
WDFAPI
WIFI_ADAPTER_TYPE
(NTAPI *PFN_WIFIADAPTERINITGETTYPE)(
    _In_
    PWIFI_DRIVER_GLOBALS DriverGlobals,
    _In_
    NETADAPTER_INIT* AdapterInit
    );

_IRQL_requires_max_(PASSIVE_LEVEL)
FORCEINLINE
WIFI_ADAPTER_TYPE
WifiAdapterInitGetType(
    _In_
    NETADAPTER_INIT* AdapterInit
    )
{
    return ((PFN_WIFIADAPTERINITGETTYPE) WifiFunctions[WifiAdapterInitGetTypeTableIndex])(WifiDriverGlobals, AdapterInit);
}

//
// WIFI Function: WifiAdapterGetType
//
typedef
_IRQL_requires_max_(PASSIVE_LEVEL)
WDFAPI
WIFI_ADAPTER_TYPE
(NTAPI *PFN_WIFIADAPTERGETTYPE)(
    _In_
    PWIFI_DRIVER_GLOBALS DriverGlobals,
    _In_
    NETADAPTER Adapter
    );

_IRQL_requires_max_(PASSIVE_LEVEL)
FORCEINLINE
WIFI_ADAPTER_TYPE
WifiAdapterGetType(
    _In_
    NETADAPTER Adapter
    )
{
    return ((PFN_WIFIADAPTERGETTYPE) WifiFunctions[WifiAdapterGetTypeTableIndex])(WifiDriverGlobals, Adapter);
}

//
// WIFI Function: WifiDirectDeviceGetPortId
//
typedef
_IRQL_requires_max_(PASSIVE_LEVEL)
WDFAPI
ULONG
(NTAPI *PFN_WIFIDIRECTDEVICEGETPORTID)(
    _In_
    PWIFI_DRIVER_GLOBALS DriverGlobals,
    _In_
    WIFIDIRECTDEVICE WifiDirectDevice
    );

_IRQL_requires_max_(PASSIVE_LEVEL)
FORCEINLINE
ULONG
WifiDirectDeviceGetPortId(
    _In_
    WIFIDIRECTDEVICE WifiDirectDevice
    )
{
    return ((PFN_WIFIDIRECTDEVICEGETPORTID) WifiFunctions[WifiDirectDeviceGetPortIdTableIndex])(WifiDriverGlobals, WifiDirectDevice);
}

//
// WIFI Function: WifiAdapterInitAddTxDemux
//
typedef
_IRQL_requires_(PASSIVE_LEVEL)
WDFAPI
void
(NTAPI *PFN_WIFIADAPTERINITADDTXDEMUX)(
    _In_
    PWIFI_DRIVER_GLOBALS DriverGlobals,
    _In_
    NETADAPTER_INIT* Adapter,
    _In_
    CONST WIFI_ADAPTER_TX_DEMUX* Demux
    );

_IRQL_requires_(PASSIVE_LEVEL)
FORCEINLINE
void
WifiAdapterInitAddTxDemux(
    _In_
    NETADAPTER_INIT* Adapter,
    _In_
    CONST WIFI_ADAPTER_TX_DEMUX* Demux
    )
{
    ((PFN_WIFIADAPTERINITADDTXDEMUX) WifiFunctions[WifiAdapterInitAddTxDemuxTableIndex])(WifiDriverGlobals, Adapter, Demux);
}

//
// WIFI Function: WifiTxQueueGetDemuxPeerAddress
//
typedef
_IRQL_requires_(PASSIVE_LEVEL)
WDFAPI
NET_EUI48_ADDRESS
(NTAPI *PFN_WIFITXQUEUEGETDEMUXPEERADDRESS)(
    _In_
    PWIFI_DRIVER_GLOBALS DriverGlobals,
    _In_
    NETPACKETQUEUE Queue
    );

_IRQL_requires_(PASSIVE_LEVEL)
FORCEINLINE
NET_EUI48_ADDRESS
WifiTxQueueGetDemuxPeerAddress(
    _In_
    NETPACKETQUEUE Queue
    )
{
    return ((PFN_WIFITXQUEUEGETDEMUXPEERADDRESS) WifiFunctions[WifiTxQueueGetDemuxPeerAddressTableIndex])(WifiDriverGlobals, Queue);
}

//
// WIFI Function: WifiTxQueueGetDemuxWmmInfo
//
typedef
_IRQL_requires_(PASSIVE_LEVEL)
WDFAPI
UINT8
(NTAPI *PFN_WIFITXQUEUEGETDEMUXWMMINFO)(
    _In_
    PWIFI_DRIVER_GLOBALS DriverGlobals,
    _In_
    NETPACKETQUEUE Queue
    );

_IRQL_requires_(PASSIVE_LEVEL)
FORCEINLINE
UINT8
WifiTxQueueGetDemuxWmmInfo(
    _In_
    NETPACKETQUEUE Queue
    )
{
    return ((PFN_WIFITXQUEUEGETDEMUXWMMINFO) WifiFunctions[WifiTxQueueGetDemuxWmmInfoTableIndex])(WifiDriverGlobals, Queue);
}

//
// WIFI Function: WifiAdapterAddPeer
//
typedef
_IRQL_requires_(PASSIVE_LEVEL)
WDFAPI
void
(NTAPI *PFN_WIFIADAPTERADDPEER)(
    _In_
    PWIFI_DRIVER_GLOBALS DriverGlobals,
    _In_
    NETADAPTER Adapter,
    _In_
    CONST NET_EUI48_ADDRESS* Address
    );

_IRQL_requires_(PASSIVE_LEVEL)
FORCEINLINE
void
WifiAdapterAddPeer(
    _In_
    NETADAPTER Adapter,
    _In_
    CONST NET_EUI48_ADDRESS* Address
    )
{
    ((PFN_WIFIADAPTERADDPEER) WifiFunctions[WifiAdapterAddPeerTableIndex])(WifiDriverGlobals, Adapter, Address);
}

//
// WIFI Function: WifiAdapterRemovePeer
//
typedef
_IRQL_requires_(PASSIVE_LEVEL)
WDFAPI
void
(NTAPI *PFN_WIFIADAPTERREMOVEPEER)(
    _In_
    PWIFI_DRIVER_GLOBALS DriverGlobals,
    _In_
    NETADAPTER Adapter,
    _In_
    CONST NET_EUI48_ADDRESS* Address
    );

_IRQL_requires_(PASSIVE_LEVEL)
FORCEINLINE
void
WifiAdapterRemovePeer(
    _In_
    NETADAPTER Adapter,
    _In_
    CONST NET_EUI48_ADDRESS* Address
    )
{
    ((PFN_WIFIADAPTERREMOVEPEER) WifiFunctions[WifiAdapterRemovePeerTableIndex])(WifiDriverGlobals, Adapter, Address);
}



WDF_EXTERN_C_END

#endif // _WIFICX_H_

