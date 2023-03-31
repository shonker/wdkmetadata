/*++

Copyright (c) Microsoft Corporation.  All rights reserved.

Module Name:

    AcxStreams.h

Abstract:

    This is the interfaces for the Audio Class eXtension stream objects

Environment:

    Kernel-mode.

Revision History:

--*/

//
// NOTE: This header is generated by stubwork.  Please make any 
//       modifications to the corresponding template files 
//       (.x or .y) and use stubwork to regenerate the header
//

#ifndef _ACXSTREAMS_H_
#define _ACXSTREAMS_H_

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



#if (NTDDI_VERSION >= NTDDI_WIN2K)




//
// NTSTATUS
// AcxStreamStopIo(
//     _In_ ACXSTREAM Stream,
//     _In_ ULONG Flags
//     );
//
// NTSTATUS
// AcxStreamStopIoWithTag(
//     _In_ ACXSTREAM Stream,
//     _In_ ULONG Flags,
//     _In_ PVOID Tag
//     );
//
// VOID
// AcxStreamResumeIo(
//     _In_ ACXSTREAM Stream,
//     );
//
// VOID
// AcxStreamResumeIoWithTag(
//     _In_ ACXSTREAM Stream,
//     _In_ PVOID Tag
//     );
//
#define AcxStreamStopIo(Stream, Flags) \
        AcxStreamStopIoWithTag(Stream, Flags, NULL)

#define AcxStreamStopIoWithTag(Stream, Flags, Tag) \
        AcxStreamStopIoActual(Stream, Flags, Tag, __LINE__, __FILE__)
        
#define AcxStreamResumeIo(Stream) \
        AcxStreamResumeIoWithTag(Stream, NULL)

#define AcxStreamResumeIoWithTag(Stream, Tag) \
        AcxStreamResumeIoActual(Stream, Tag, __LINE__, __FILE__)

typedef struct _ACX_RTPACKET {
    ULONG Size;
    WDF_MEMORY_DESCRIPTOR RtPacketBuffer;
    ULONG RtPacketOffset;
    ULONG RtPacketSize;
} ACX_RTPACKET, *PACX_RTPACKET;

VOID
FORCEINLINE
ACX_RTPACKET_INIT(
    _Out_ PACX_RTPACKET RtPacket
    )
{
    RtlZeroMemory(RtPacket, sizeof(ACX_RTPACKET));
    RtPacket->Size = ACX_STRUCTURE_SIZE(ACX_RTPACKET);
}

//
// DRM structs.
//
typedef struct _ACXDRMFORWARD {
    ULONG          Flags;
    PDEVICE_OBJECT DeviceObject;
    PFILE_OBJECT   FileObject;
    PVOID          Context;
} ACXDRMFORWARD, *PACXDRMFORWARD;
typedef const ACXDRMFORWARD *PCACXDRMFORWARD;

typedef struct _ACXDRMRIGHTS {
    int  CopyProtect;   // BOOL
    ULONG Reserved;
    int  DigitalOutputDisable;  // BOOL
} ACXDRMRIGHTS , *PACXDRMRIGHTS;
typedef const ACXDRMRIGHTS *PCACXDRMRIGHTS;

#define DEFINE_ACXDRMRIGHTS_DEFAULT(DrmRights) const ACXDRMRIGHTS DrmRights = {FALSE, 0, FALSE}

//
// Placeholder Callbacks
//

typedef
_Function_class_(EVT_ACX_STREAM_ALLOCATE_RTPACKETS)
_IRQL_requires_same_
_IRQL_requires_max_(PASSIVE_LEVEL)
NTSTATUS
NTAPI
EVT_ACX_STREAM_ALLOCATE_RTPACKETS(
    _In_
    ACXSTREAM Stream,
    _In_
    ULONG PacketCount,
    _In_
    ULONG PacketSize,
    _Out_
    PACX_RTPACKET * Packets
    );

typedef EVT_ACX_STREAM_ALLOCATE_RTPACKETS *PFN_ACX_STREAM_ALLOCATE_RTPACKETS;

typedef
_Function_class_(EVT_ACX_STREAM_FREE_RTPACKETS)
_IRQL_requires_same_
_IRQL_requires_max_(PASSIVE_LEVEL)
VOID
NTAPI
EVT_ACX_STREAM_FREE_RTPACKETS(
    _In_
    ACXSTREAM Stream,
    _In_
    PACX_RTPACKET Packets,
    _In_
    ULONG PacketCount
    );

typedef EVT_ACX_STREAM_FREE_RTPACKETS *PFN_ACX_STREAM_FREE_RTPACKETS;

typedef
_Function_class_(EVT_ACX_STREAM_GET_HW_LATENCY)
_IRQL_requires_same_
_IRQL_requires_max_(PASSIVE_LEVEL)
NTSTATUS
NTAPI
EVT_ACX_STREAM_GET_HW_LATENCY(
    _In_
    ACXSTREAM Stream,
    _Out_
    ULONG * FifoSize,
    _Out_
    ULONG * Delay
    );

typedef EVT_ACX_STREAM_GET_HW_LATENCY *PFN_ACX_STREAM_GET_HW_LATENCY;

typedef
_Function_class_(EVT_ACX_STREAM_SET_RENDER_PACKET)
_IRQL_requires_same_
_IRQL_requires_max_(PASSIVE_LEVEL)
NTSTATUS
NTAPI
EVT_ACX_STREAM_SET_RENDER_PACKET(
    _In_
    ACXSTREAM Stream,
    _In_
    ULONG Packet,
    _In_
    ULONG Flags,
    _In_
    ULONG EosPacketLength
    );

typedef EVT_ACX_STREAM_SET_RENDER_PACKET *PFN_ACX_STREAM_SET_RENDER_PACKET;

typedef
_Function_class_(EVT_ACX_STREAM_GET_CURRENT_PACKET)
_IRQL_requires_same_
_IRQL_requires_max_(PASSIVE_LEVEL)
NTSTATUS
NTAPI
EVT_ACX_STREAM_GET_CURRENT_PACKET(
    _In_
    ACXSTREAM Stream,
    _Out_
    PULONG CurrentPacket
    );

typedef EVT_ACX_STREAM_GET_CURRENT_PACKET *PFN_ACX_STREAM_GET_CURRENT_PACKET;

typedef
_Function_class_(EVT_ACX_STREAM_GET_CAPTURE_PACKET)
_IRQL_requires_same_
_IRQL_requires_max_(PASSIVE_LEVEL)
NTSTATUS
NTAPI
EVT_ACX_STREAM_GET_CAPTURE_PACKET(
    _In_
    ACXSTREAM Stream,
    _Out_
    PULONG LastCapturePacket,
    _Out_
    PULONGLONG QPCPacketStart,
    _Out_
    PBOOLEAN MoreData
    );

typedef EVT_ACX_STREAM_GET_CAPTURE_PACKET *PFN_ACX_STREAM_GET_CAPTURE_PACKET;

typedef
_Function_class_(EVT_ACX_STREAM_GET_PRESENTATION_POSITION)
_IRQL_requires_same_
_IRQL_requires_max_(PASSIVE_LEVEL)
NTSTATUS
NTAPI
EVT_ACX_STREAM_GET_PRESENTATION_POSITION(
    _In_
    ACXSTREAM Stream,
    _Out_
    PULONGLONG PositionInBlocks,
    _Out_
    PULONGLONG QPCPosition
    );

typedef EVT_ACX_STREAM_GET_PRESENTATION_POSITION *PFN_ACX_STREAM_GET_PRESENTATION_POSITION;

typedef
_Function_class_(EVT_ACX_STREAM_ASSIGN_DRM_CONTENT_ID)
_IRQL_requires_same_
_IRQL_requires_max_(PASSIVE_LEVEL)
NTSTATUS
NTAPI
EVT_ACX_STREAM_ASSIGN_DRM_CONTENT_ID(
    _In_
    ACXSTREAM Stream,
    _In_
    ULONG ContentId,
    _In_
    PACXDRMRIGHTS DrmRights
    );

typedef EVT_ACX_STREAM_ASSIGN_DRM_CONTENT_ID *PFN_ACX_STREAM_ASSIGN_DRM_CONTENT_ID;

typedef
_Function_class_(EVT_ACX_STREAM_PREPARE_HARDWARE)
_IRQL_requires_same_
_IRQL_requires_max_(PASSIVE_LEVEL)
NTSTATUS
NTAPI
EVT_ACX_STREAM_PREPARE_HARDWARE(
    _In_
    ACXSTREAM Stream
    );

typedef EVT_ACX_STREAM_PREPARE_HARDWARE *PFN_ACX_STREAM_PREPARE_HARDWARE;

typedef
_Function_class_(EVT_ACX_STREAM_RELEASE_HARDWARE)
_IRQL_requires_same_
_IRQL_requires_max_(PASSIVE_LEVEL)
NTSTATUS
NTAPI
EVT_ACX_STREAM_RELEASE_HARDWARE(
    _In_
    ACXSTREAM Stream
    );

typedef EVT_ACX_STREAM_RELEASE_HARDWARE *PFN_ACX_STREAM_RELEASE_HARDWARE;

typedef
_Function_class_(EVT_ACX_STREAM_RUN)
_IRQL_requires_same_
_IRQL_requires_max_(PASSIVE_LEVEL)
NTSTATUS
NTAPI
EVT_ACX_STREAM_RUN(
    _In_
    ACXSTREAM Stream
    );

typedef EVT_ACX_STREAM_RUN *PFN_ACX_STREAM_RUN;

typedef
_Function_class_(EVT_ACX_STREAM_PAUSE)
_IRQL_requires_same_
_IRQL_requires_max_(PASSIVE_LEVEL)
NTSTATUS
NTAPI
EVT_ACX_STREAM_PAUSE(
    _In_
    ACXSTREAM Stream
    );

typedef EVT_ACX_STREAM_PAUSE *PFN_ACX_STREAM_PAUSE;

typedef enum _ACX_STREAM_STATE {
    AcxStreamStateStop    = 0,
    AcxStreamStateAcquire = 1,
    AcxStreamStatePause   = 2,
    AcxStreamStateRun     = 3,
    AcxStreamStateMaximum
} ACX_STREAM_STATE, *PACX_STREAM_STATE;

typedef struct _ACX_STREAM_CALLBACKS {
    ULONG                                      Size;
    PFN_ACX_STREAM_PREPARE_HARDWARE            EvtAcxStreamPrepareHardware;
    PFN_ACX_STREAM_RELEASE_HARDWARE            EvtAcxStreamReleaseHardware;
    PFN_ACX_STREAM_RUN                         EvtAcxStreamRun;
    PFN_ACX_STREAM_PAUSE                       EvtAcxStreamPause;
    PFN_ACX_STREAM_ASSIGN_DRM_CONTENT_ID       EvtAcxStreamAssignDrmContentId;
} ACX_STREAM_CALLBACKS, *PACX_STREAM_CALLBACKS;

VOID
FORCEINLINE
ACX_STREAM_CALLBACKS_INIT(
    _Out_ PACX_STREAM_CALLBACKS Callbacks
    )
{
    RtlZeroMemory(Callbacks, sizeof(ACX_STREAM_CALLBACKS));
    Callbacks->Size = ACX_STRUCTURE_SIZE(ACX_STREAM_CALLBACKS);
}

typedef struct _ACX_RT_STREAM_CALLBACKS {
    ULONG                                      Size;
    PFN_ACX_STREAM_GET_HW_LATENCY              EvtAcxStreamGetHwLatency;
    PFN_ACX_STREAM_ALLOCATE_RTPACKETS          EvtAcxStreamAllocateRtPackets;
    PFN_ACX_STREAM_FREE_RTPACKETS              EvtAcxStreamFreeRtPackets;
    PFN_ACX_STREAM_SET_RENDER_PACKET           EvtAcxStreamSetRenderPacket;
    PFN_ACX_STREAM_GET_CURRENT_PACKET          EvtAcxStreamGetCurrentPacket;
    PFN_ACX_STREAM_GET_CAPTURE_PACKET          EvtAcxStreamGetCapturePacket;
    PFN_ACX_STREAM_GET_PRESENTATION_POSITION   EvtAcxStreamGetPresentationPosition;
} ACX_RT_STREAM_CALLBACKS, *PACX_RT_STREAM_CALLBACKS;

VOID
FORCEINLINE
ACX_RT_STREAM_CALLBACKS_INIT(
    _Out_ PACX_RT_STREAM_CALLBACKS Callbacks
    )
{
    RtlZeroMemory(Callbacks, sizeof(ACX_RT_STREAM_CALLBACKS));
    Callbacks->Size = ACX_STRUCTURE_SIZE(ACX_RT_STREAM_CALLBACKS);
}



//
// ACX stream bridge defines and structures.
//
typedef enum _ACX_STREAM_BRIDGE_CONFIG_FLAGS {
    AcxStreamBridgeConfigNoFlags                = 0x00000000,
    AcxStreamBridgeInvertChangeStateSequence    = 0x00000001,
    AcxStreamBridgeForwardInStreamVarArguments  = 0x00000002,
    AcxStreamBridgeConfigValidFlags             = 0x00000003
} ACX_STREAM_BRIDGE_CONFIG_FLAGS;

typedef enum _ACX_STREAM_BRIDGE_TYPE {
    AcxStreamBridgeInvalidType          = 0x00000000,
    AcxStreamBridgeMux                  = 0x00000001,
    //AcxStreamBridgeDirect             = 0x00000002,
    AcxStreamBridgeMaximumType,
    AcxStreamBridgeDefaultType          = AcxStreamBridgeMux
} ACX_STREAM_BRIDGE_TYPE;

typedef struct _ACX_STREAM_BRIDGE_CONFIG {
    ULONG                           Size;
    ULONG                           Flags;
    ACX_STREAM_BRIDGE_TYPE          Type;
    ULONG                           InModesCount;
    PCGUID *                        InModes;
    PCGUID                          OutMode;
    ACXOBJECTBAG                    OutStreamVarArguments;
    WDF_OBJECT_ATTRIBUTES           TargetStreamAttributes; // optional
} ACX_STREAM_BRIDGE_CONFIG, *PACX_STREAM_BRIDGE_CONFIG;

VOID
FORCEINLINE
ACX_STREAM_BRIDGE_CONFIG_INIT(
    _Out_ PACX_STREAM_BRIDGE_CONFIG Config
    )
{
    RtlZeroMemory(Config, sizeof(ACX_STREAM_BRIDGE_CONFIG));
    Config->Size = ACX_STRUCTURE_SIZE(ACX_STREAM_BRIDGE_CONFIG);
    Config->Type = AcxStreamBridgeDefaultType;
}


//
// ACX Function: AcxStreamInitAssignProperties
//
typedef
_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
WDFAPI
NTSTATUS
(NTAPI *PFN_ACXSTREAMINITASSIGNPROPERTIES)(
    _In_
    PACX_DRIVER_GLOBALS DriverGlobals,
    _In_
    PACXSTREAM_INIT StreamInit,
    _In_reads_(PropertiesCount)
    PACX_PROPERTY_ITEM Properties,
    _In_
    ULONG PropertiesCount
    );

_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
FORCEINLINE
NTSTATUS
AcxStreamInitAssignProperties(
    _In_
    PACXSTREAM_INIT StreamInit,
    _In_reads_(PropertiesCount)
    PACX_PROPERTY_ITEM Properties,
    _In_
    ULONG PropertiesCount
    )
{
    return ((PFN_ACXSTREAMINITASSIGNPROPERTIES) AcxFunctions[AcxStreamInitAssignPropertiesTableIndex])(AcxDriverGlobals, StreamInit, Properties, PropertiesCount);
}

//
// ACX Function: AcxStreamInitAssignMethods
//
typedef
_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
WDFAPI
NTSTATUS
(NTAPI *PFN_ACXSTREAMINITASSIGNMETHODS)(
    _In_
    PACX_DRIVER_GLOBALS DriverGlobals,
    _In_
    PACXSTREAM_INIT StreamInit,
    _In_reads_(MethodsCount)
    PACX_METHOD_ITEM Methods,
    _In_
    ULONG MethodsCount
    );

_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
FORCEINLINE
NTSTATUS
AcxStreamInitAssignMethods(
    _In_
    PACXSTREAM_INIT StreamInit,
    _In_reads_(MethodsCount)
    PACX_METHOD_ITEM Methods,
    _In_
    ULONG MethodsCount
    )
{
    return ((PFN_ACXSTREAMINITASSIGNMETHODS) AcxFunctions[AcxStreamInitAssignMethodsTableIndex])(AcxDriverGlobals, StreamInit, Methods, MethodsCount);
}

//
// ACX Function: AcxStreamInitAssignAcxRequestPreprocessCallback
//
typedef
_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
WDFAPI
NTSTATUS
(NTAPI *PFN_ACXSTREAMINITASSIGNACXREQUESTPREPROCESSCALLBACK)(
    _In_
    PACX_DRIVER_GLOBALS DriverGlobals,
    _In_
    PACXSTREAM_INIT StreamInit,
    _In_
    EVT_ACX_OBJECT_PREPROCESS_REQUEST EvtObjectAcxRequestPreprocess,
    _In_opt_
    ACXCONTEXT DriverContext,
    _In_
    ACX_REQUEST_TYPE RequestType,
    _In_opt_
    CONST GUID* Set,
    _In_
    ULONG Id
    );

_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
FORCEINLINE
NTSTATUS
AcxStreamInitAssignAcxRequestPreprocessCallback(
    _In_
    PACXSTREAM_INIT StreamInit,
    _In_
    EVT_ACX_OBJECT_PREPROCESS_REQUEST EvtObjectAcxRequestPreprocess,
    _In_opt_
    ACXCONTEXT DriverContext,
    _In_
    ACX_REQUEST_TYPE RequestType,
    _In_opt_
    CONST GUID* Set,
    _In_
    ULONG Id
    )
{
    return ((PFN_ACXSTREAMINITASSIGNACXREQUESTPREPROCESSCALLBACK) AcxFunctions[AcxStreamInitAssignAcxRequestPreprocessCallbackTableIndex])(AcxDriverGlobals, StreamInit, EvtObjectAcxRequestPreprocess, DriverContext, RequestType, Set, Id);
}

//
// ACX Function: AcxStreamInitAssignAcxStreamCallbacks
//
typedef
_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
WDFAPI
NTSTATUS
(NTAPI *PFN_ACXSTREAMINITASSIGNACXSTREAMCALLBACKS)(
    _In_
    PACX_DRIVER_GLOBALS DriverGlobals,
    _In_
    PACXSTREAM_INIT StreamInit,
    _In_
    PACX_STREAM_CALLBACKS StreamCallbacks
    );

_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
FORCEINLINE
NTSTATUS
AcxStreamInitAssignAcxStreamCallbacks(
    _In_
    PACXSTREAM_INIT StreamInit,
    _In_
    PACX_STREAM_CALLBACKS StreamCallbacks
    )
{
    return ((PFN_ACXSTREAMINITASSIGNACXSTREAMCALLBACKS) AcxFunctions[AcxStreamInitAssignAcxStreamCallbacksTableIndex])(AcxDriverGlobals, StreamInit, StreamCallbacks);
}

//
// ACX Function: AcxStreamInitAssignAcxRtStreamCallbacks
//
typedef
_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
WDFAPI
NTSTATUS
(NTAPI *PFN_ACXSTREAMINITASSIGNACXRTSTREAMCALLBACKS)(
    _In_
    PACX_DRIVER_GLOBALS DriverGlobals,
    _In_
    PACXSTREAM_INIT StreamInit,
    _In_
    PACX_RT_STREAM_CALLBACKS RtStreamCallbacks
    );

_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
FORCEINLINE
NTSTATUS
AcxStreamInitAssignAcxRtStreamCallbacks(
    _In_
    PACXSTREAM_INIT StreamInit,
    _In_
    PACX_RT_STREAM_CALLBACKS RtStreamCallbacks
    )
{
    return ((PFN_ACXSTREAMINITASSIGNACXRTSTREAMCALLBACKS) AcxFunctions[AcxStreamInitAssignAcxRtStreamCallbacksTableIndex])(AcxDriverGlobals, StreamInit, RtStreamCallbacks);
}

//
// ACX Function: AcxStreamInitSetAcxRtStreamSupportsNotifications
//
typedef
_IRQL_requires_max_(PASSIVE_LEVEL)
WDFAPI
VOID
(NTAPI *PFN_ACXSTREAMINITSETACXRTSTREAMSUPPORTSNOTIFICATIONS)(
    _In_
    PACX_DRIVER_GLOBALS DriverGlobals,
    _In_
    PACXSTREAM_INIT StreamInit
    );

_IRQL_requires_max_(PASSIVE_LEVEL)
FORCEINLINE
VOID
AcxStreamInitSetAcxRtStreamSupportsNotifications(
    _In_
    PACXSTREAM_INIT StreamInit
    )
{
    ((PFN_ACXSTREAMINITSETACXRTSTREAMSUPPORTSNOTIFICATIONS) AcxFunctions[AcxStreamInitSetAcxRtStreamSupportsNotificationsTableIndex])(AcxDriverGlobals, StreamInit);
}

//
// ACX Function: AcxStreamCreate
//
typedef
_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
WDFAPI
NTSTATUS
(NTAPI *PFN_ACXSTREAMCREATE)(
    _In_
    PACX_DRIVER_GLOBALS DriverGlobals,
    _In_
    WDFDEVICE Device,
    _In_
    ACXCIRCUIT Circuit,
    _In_
    PWDF_OBJECT_ATTRIBUTES Attributes,
    _In_
    PACXSTREAM_INIT* Config,
    _Out_
    ACXSTREAM* Stream
    );

_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
FORCEINLINE
NTSTATUS
AcxStreamCreate(
    _In_
    WDFDEVICE Device,
    _In_
    ACXCIRCUIT Circuit,
    _In_
    PWDF_OBJECT_ATTRIBUTES Attributes,
    _In_
    PACXSTREAM_INIT* Config,
    _Out_
    ACXSTREAM* Stream
    )
{
    return ((PFN_ACXSTREAMCREATE) AcxFunctions[AcxStreamCreateTableIndex])(AcxDriverGlobals, Device, Circuit, Attributes, Config, Stream);
}

//
// ACX Function: AcxStreamAddEvents
//
typedef
_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
WDFAPI
NTSTATUS
(NTAPI *PFN_ACXSTREAMADDEVENTS)(
    _In_
    PACX_DRIVER_GLOBALS DriverGlobals,
    _In_
    ACXSTREAM Stream,
    _In_reads_(EventsCount)
    ACXEVENT* Events,
    _In_
    ULONG EventsCount
    );

_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
FORCEINLINE
NTSTATUS
AcxStreamAddEvents(
    _In_
    ACXSTREAM Stream,
    _In_reads_(EventsCount)
    ACXEVENT* Events,
    _In_
    ULONG EventsCount
    )
{
    return ((PFN_ACXSTREAMADDEVENTS) AcxFunctions[AcxStreamAddEventsTableIndex])(AcxDriverGlobals, Stream, Events, EventsCount);
}

//
// ACX Function: AcxStreamAddElements
//
typedef
_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
WDFAPI
NTSTATUS
(NTAPI *PFN_ACXSTREAMADDELEMENTS)(
    _In_
    PACX_DRIVER_GLOBALS DriverGlobals,
    _In_
    ACXSTREAM Stream,
    _In_reads_(ElementsCount)
    ACXELEMENT* Elements,
    _In_
    ULONG ElementsCount
    );

_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
FORCEINLINE
NTSTATUS
AcxStreamAddElements(
    _In_
    ACXSTREAM Stream,
    _In_reads_(ElementsCount)
    ACXELEMENT* Elements,
    _In_
    ULONG ElementsCount
    )
{
    return ((PFN_ACXSTREAMADDELEMENTS) AcxFunctions[AcxStreamAddElementsTableIndex])(AcxDriverGlobals, Stream, Elements, ElementsCount);
}

//
// ACX Function: AcxStreamGetElementsCount
//
typedef
_Must_inspect_result_
_IRQL_requires_max_(DISPATCH_LEVEL)
WDFAPI
ULONG
(NTAPI *PFN_ACXSTREAMGETELEMENTSCOUNT)(
    _In_
    PACX_DRIVER_GLOBALS DriverGlobals,
    _In_
    ACXSTREAM Stream
    );

_Must_inspect_result_
_IRQL_requires_max_(DISPATCH_LEVEL)
FORCEINLINE
ULONG
AcxStreamGetElementsCount(
    _In_
    ACXSTREAM Stream
    )
{
    return ((PFN_ACXSTREAMGETELEMENTSCOUNT) AcxFunctions[AcxStreamGetElementsCountTableIndex])(AcxDriverGlobals, Stream);
}

//
// ACX Function: AcxStreamGetElementById
//
typedef
_Must_inspect_result_
_IRQL_requires_max_(DISPATCH_LEVEL)
WDFAPI
ACXELEMENT
(NTAPI *PFN_ACXSTREAMGETELEMENTBYID)(
    _In_
    PACX_DRIVER_GLOBALS DriverGlobals,
    _In_
    ACXSTREAM Stream,
    _In_
    ULONG ElementId
    );

_Must_inspect_result_
_IRQL_requires_max_(DISPATCH_LEVEL)
FORCEINLINE
ACXELEMENT
AcxStreamGetElementById(
    _In_
    ACXSTREAM Stream,
    _In_
    ULONG ElementId
    )
{
    return ((PFN_ACXSTREAMGETELEMENTBYID) AcxFunctions[AcxStreamGetElementByIdTableIndex])(AcxDriverGlobals, Stream, ElementId);
}

//
// ACX Function: AcxStreamAddConnections
//
typedef
_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
WDFAPI
NTSTATUS
(NTAPI *PFN_ACXSTREAMADDCONNECTIONS)(
    _In_
    PACX_DRIVER_GLOBALS DriverGlobals,
    _In_
    ACXSTREAM Stream,
    _In_reads_(ConnectionsCount)
    PACX_CONNECTION Connections,
    _In_
    ULONG ConnectionsCount
    );

_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
FORCEINLINE
NTSTATUS
AcxStreamAddConnections(
    _In_
    ACXSTREAM Stream,
    _In_reads_(ConnectionsCount)
    PACX_CONNECTION Connections,
    _In_
    ULONG ConnectionsCount
    )
{
    return ((PFN_ACXSTREAMADDCONNECTIONS) AcxFunctions[AcxStreamAddConnectionsTableIndex])(AcxDriverGlobals, Stream, Connections, ConnectionsCount);
}

//
// ACX Function: AcxStreamGetCircuit
//
typedef
_IRQL_requires_max_(DISPATCH_LEVEL)
WDFAPI
ACXCIRCUIT
(NTAPI *PFN_ACXSTREAMGETCIRCUIT)(
    _In_
    PACX_DRIVER_GLOBALS DriverGlobals,
    _In_
    ACXSTREAM Stream
    );

_IRQL_requires_max_(DISPATCH_LEVEL)
FORCEINLINE
ACXCIRCUIT
AcxStreamGetCircuit(
    _In_
    ACXSTREAM Stream
    )
{
    return ((PFN_ACXSTREAMGETCIRCUIT) AcxFunctions[AcxStreamGetCircuitTableIndex])(AcxDriverGlobals, Stream);
}

//
// ACX Function: AcxStreamDispatchAcxRequest
//
typedef
_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
WDFAPI
NTSTATUS
(NTAPI *PFN_ACXSTREAMDISPATCHACXREQUEST)(
    _In_
    PACX_DRIVER_GLOBALS DriverGlobals,
    _In_
    ACXSTREAM Stream,
    _In_
    WDFREQUEST Request
    );

_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
FORCEINLINE
NTSTATUS
AcxStreamDispatchAcxRequest(
    _In_
    ACXSTREAM Stream,
    _In_
    WDFREQUEST Request
    )
{
    return ((PFN_ACXSTREAMDISPATCHACXREQUEST) AcxFunctions[AcxStreamDispatchAcxRequestTableIndex])(AcxDriverGlobals, Stream, Request);
}

//
// ACX Function: AcxStreamStopIoActual
//
typedef
_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
WDFAPI
NTSTATUS
(NTAPI *PFN_ACXSTREAMSTOPIOACTUAL)(
    _In_
    PACX_DRIVER_GLOBALS DriverGlobals,
    _In_
    ACXSTREAM Stream,
    _In_
    ULONG Flags,
    _In_opt_
    PVOID ObjectTag,
    _In_
    LONG Line,
    _In_z_
    PCCH File
    );

_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
FORCEINLINE
NTSTATUS
AcxStreamStopIoActual(
    _In_
    ACXSTREAM Stream,
    _In_
    ULONG Flags,
    _In_opt_
    PVOID ObjectTag,
    _In_
    LONG Line,
    _In_z_
    PCCH File
    )
{
    return ((PFN_ACXSTREAMSTOPIOACTUAL) AcxFunctions[AcxStreamStopIoActualTableIndex])(AcxDriverGlobals, Stream, Flags, ObjectTag, Line, File);
}

//
// ACX Function: AcxStreamResumeIoActual
//
typedef
_IRQL_requires_max_(PASSIVE_LEVEL)
WDFAPI
VOID
(NTAPI *PFN_ACXSTREAMRESUMEIOACTUAL)(
    _In_
    PACX_DRIVER_GLOBALS DriverGlobals,
    _In_
    ACXSTREAM Stream,
    _In_opt_
    PVOID ObjectTag,
    _In_
    LONG Line,
    _In_z_
    PCCH File
    );

_IRQL_requires_max_(PASSIVE_LEVEL)
FORCEINLINE
VOID
AcxStreamResumeIoActual(
    _In_
    ACXSTREAM Stream,
    _In_opt_
    PVOID ObjectTag,
    _In_
    LONG Line,
    _In_z_
    PCCH File
    )
{
    ((PFN_ACXSTREAMRESUMEIOACTUAL) AcxFunctions[AcxStreamResumeIoActualTableIndex])(AcxDriverGlobals, Stream, ObjectTag, Line, File);
}

//
// ACX Function: AcxRtStreamCreate
//
typedef
_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
WDFAPI
NTSTATUS
(NTAPI *PFN_ACXRTSTREAMCREATE)(
    _In_
    PACX_DRIVER_GLOBALS DriverGlobals,
    _In_
    WDFDEVICE Device,
    _In_
    ACXCIRCUIT Circuit,
    _In_
    PWDF_OBJECT_ATTRIBUTES Attributes,
    _In_
    PACXSTREAM_INIT* Config,
    _Out_
    ACXSTREAM* Stream
    );

_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
FORCEINLINE
NTSTATUS
AcxRtStreamCreate(
    _In_
    WDFDEVICE Device,
    _In_
    ACXCIRCUIT Circuit,
    _In_
    PWDF_OBJECT_ATTRIBUTES Attributes,
    _In_
    PACXSTREAM_INIT* Config,
    _Out_
    ACXSTREAM* Stream
    )
{
    return ((PFN_ACXRTSTREAMCREATE) AcxFunctions[AcxRtStreamCreateTableIndex])(AcxDriverGlobals, Device, Circuit, Attributes, Config, Stream);
}

//
// ACX Function: AcxRtStreamNotifyPacketComplete
//
typedef
_Must_inspect_result_
_IRQL_requires_max_(DISPATCH_LEVEL)
WDFAPI
NTSTATUS
(NTAPI *PFN_ACXRTSTREAMNOTIFYPACKETCOMPLETE)(
    _In_
    PACX_DRIVER_GLOBALS DriverGlobals,
    _In_
    ACXSTREAM Stream,
    _In_
    ULONGLONG CompletedPacket,
    _In_
    ULONGLONG QPCCompletion
    );

_Must_inspect_result_
_IRQL_requires_max_(DISPATCH_LEVEL)
FORCEINLINE
NTSTATUS
AcxRtStreamNotifyPacketComplete(
    _In_
    ACXSTREAM Stream,
    _In_
    ULONGLONG CompletedPacket,
    _In_
    ULONGLONG QPCCompletion
    )
{
    return ((PFN_ACXRTSTREAMNOTIFYPACKETCOMPLETE) AcxFunctions[AcxRtStreamNotifyPacketCompleteTableIndex])(AcxDriverGlobals, Stream, CompletedPacket, QPCCompletion);
}

//
// ACX Function: AcxDrmAddContentHandlers
//
typedef
_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
WDFAPI
NTSTATUS
(NTAPI *PFN_ACXDRMADDCONTENTHANDLERS)(
    _In_
    PACX_DRIVER_GLOBALS DriverGlobals,
    _In_
    ULONG ContentId,
    _In_reads_(NumHandlers)
    PVOID* paHandlers,
    _In_
    ULONG NumHandlers
    );

_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
FORCEINLINE
NTSTATUS
AcxDrmAddContentHandlers(
    _In_
    ULONG ContentId,
    _In_reads_(NumHandlers)
    PVOID* paHandlers,
    _In_
    ULONG NumHandlers
    )
{
    return ((PFN_ACXDRMADDCONTENTHANDLERS) AcxFunctions[AcxDrmAddContentHandlersTableIndex])(AcxDriverGlobals, ContentId, paHandlers, NumHandlers);
}

//
// ACX Function: AcxDrmCreateContentMixed
//
typedef
_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
WDFAPI
NTSTATUS
(NTAPI *PFN_ACXDRMCREATECONTENTMIXED)(
    _In_
    PACX_DRIVER_GLOBALS DriverGlobals,
    _In_reads_(cContentId)
    PULONG paContentId,
    _In_
    ULONG cContentId,
    _Out_
    PULONG pMixedContentId
    );

_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
FORCEINLINE
NTSTATUS
AcxDrmCreateContentMixed(
    _In_reads_(cContentId)
    PULONG paContentId,
    _In_
    ULONG cContentId,
    _Out_
    PULONG pMixedContentId
    )
{
    return ((PFN_ACXDRMCREATECONTENTMIXED) AcxFunctions[AcxDrmCreateContentMixedTableIndex])(AcxDriverGlobals, paContentId, cContentId, pMixedContentId);
}

//
// ACX Function: AcxDrmDestroyContent
//
typedef
_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
WDFAPI
NTSTATUS
(NTAPI *PFN_ACXDRMDESTROYCONTENT)(
    _In_
    PACX_DRIVER_GLOBALS DriverGlobals,
    _In_
    ULONG ContentId
    );

_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
FORCEINLINE
NTSTATUS
AcxDrmDestroyContent(
    _In_
    ULONG ContentId
    )
{
    return ((PFN_ACXDRMDESTROYCONTENT) AcxFunctions[AcxDrmDestroyContentTableIndex])(AcxDriverGlobals, ContentId);
}

//
// ACX Function: AcxDrmForwardContentToDeviceObject
//
typedef
_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
WDFAPI
NTSTATUS
(NTAPI *PFN_ACXDRMFORWARDCONTENTTODEVICEOBJECT)(
    _In_
    PACX_DRIVER_GLOBALS DriverGlobals,
    _In_
    ULONG ContentId,
    _In_
    PVOID Reserved,
    _In_
    PCACXDRMFORWARD DrmForward
    );

_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
FORCEINLINE
NTSTATUS
AcxDrmForwardContentToDeviceObject(
    _In_
    ULONG ContentId,
    _In_
    PVOID Reserved,
    _In_
    PCACXDRMFORWARD DrmForward
    )
{
    return ((PFN_ACXDRMFORWARDCONTENTTODEVICEOBJECT) AcxFunctions[AcxDrmForwardContentToDeviceObjectTableIndex])(AcxDriverGlobals, ContentId, Reserved, DrmForward);
}

//
// ACX Function: AcxDrmRetrieveContentRights
//
typedef
_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
WDFAPI
NTSTATUS
(NTAPI *PFN_ACXDRMRETRIEVECONTENTRIGHTS)(
    _In_
    PACX_DRIVER_GLOBALS DriverGlobals,
    _In_
    ULONG ContentId,
    _Out_
    PACXDRMRIGHTS DrmRights
    );

_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
FORCEINLINE
NTSTATUS
AcxDrmRetrieveContentRights(
    _In_
    ULONG ContentId,
    _Out_
    PACXDRMRIGHTS DrmRights
    )
{
    return ((PFN_ACXDRMRETRIEVECONTENTRIGHTS) AcxFunctions[AcxDrmRetrieveContentRightsTableIndex])(AcxDriverGlobals, ContentId, DrmRights);
}

//
// ACX Function: AcxStreamBridgeCreate
//
typedef
_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
WDFAPI
NTSTATUS
(NTAPI *PFN_ACXSTREAMBRIDGECREATE)(
    _In_
    PACX_DRIVER_GLOBALS DriverGlobals,
    _In_
    ACXCIRCUIT AcxCircuit,
    _In_
    PWDF_OBJECT_ATTRIBUTES Attributes,
    _In_
    PACX_STREAM_BRIDGE_CONFIG Config,
    _Out_
    ACXSTREAMBRIDGE* StreamBridge
    );

_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
FORCEINLINE
NTSTATUS
AcxStreamBridgeCreate(
    _In_
    ACXCIRCUIT AcxCircuit,
    _In_
    PWDF_OBJECT_ATTRIBUTES Attributes,
    _In_
    PACX_STREAM_BRIDGE_CONFIG Config,
    _Out_
    ACXSTREAMBRIDGE* StreamBridge
    )
{
    return ((PFN_ACXSTREAMBRIDGECREATE) AcxFunctions[AcxStreamBridgeCreateTableIndex])(AcxDriverGlobals, AcxCircuit, Attributes, Config, StreamBridge);
}

//
// ACX Function: AcxStreamBridgeAddStream
//
typedef
_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
WDFAPI
NTSTATUS
(NTAPI *PFN_ACXSTREAMBRIDGEADDSTREAM)(
    _In_
    PACX_DRIVER_GLOBALS DriverGlobals,
    _In_
    ACXSTREAMBRIDGE Bridge,
    _In_
    ACXSTREAM Stream
    );

_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
FORCEINLINE
NTSTATUS
AcxStreamBridgeAddStream(
    _In_
    ACXSTREAMBRIDGE Bridge,
    _In_
    ACXSTREAM Stream
    )
{
    return ((PFN_ACXSTREAMBRIDGEADDSTREAM) AcxFunctions[AcxStreamBridgeAddStreamTableIndex])(AcxDriverGlobals, Bridge, Stream);
}

//
// ACX Function: AcxStreamBridgeRemoveStream
//
typedef
_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
WDFAPI
NTSTATUS
(NTAPI *PFN_ACXSTREAMBRIDGEREMOVESTREAM)(
    _In_
    PACX_DRIVER_GLOBALS DriverGlobals,
    _In_
    ACXSTREAMBRIDGE Bridge,
    _In_
    ACXSTREAM Stream
    );

_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
FORCEINLINE
NTSTATUS
AcxStreamBridgeRemoveStream(
    _In_
    ACXSTREAMBRIDGE Bridge,
    _In_
    ACXSTREAM Stream
    )
{
    return ((PFN_ACXSTREAMBRIDGEREMOVESTREAM) AcxFunctions[AcxStreamBridgeRemoveStreamTableIndex])(AcxDriverGlobals, Bridge, Stream);
}

//
// ACX Function: AcxStreamBridgeGetTargetStream
//
typedef
_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
WDFAPI
ACXTARGETSTREAM
(NTAPI *PFN_ACXSTREAMBRIDGEGETTARGETSTREAM)(
    _In_
    PACX_DRIVER_GLOBALS DriverGlobals,
    _In_
    ACXSTREAMBRIDGE Bridge,
    _In_
    ACXSTREAM Stream
    );

_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
FORCEINLINE
ACXTARGETSTREAM
AcxStreamBridgeGetTargetStream(
    _In_
    ACXSTREAMBRIDGE Bridge,
    _In_
    ACXSTREAM Stream
    )
{
    return ((PFN_ACXSTREAMBRIDGEGETTARGETSTREAM) AcxFunctions[AcxStreamBridgeGetTargetStreamTableIndex])(AcxDriverGlobals, Bridge, Stream);
}

//
// ACX Function: AcxStreamGetNotificationId
//
typedef
_IRQL_requires_max_(DISPATCH_LEVEL)
WDFAPI
GUID
(NTAPI *PFN_ACXSTREAMGETNOTIFICATIONID)(
    _In_
    PACX_DRIVER_GLOBALS DriverGlobals,
    _In_
    ACXSTREAM Stream
    );

_IRQL_requires_max_(DISPATCH_LEVEL)
FORCEINLINE
GUID
AcxStreamGetNotificationId(
    _In_
    ACXSTREAM Stream
    )
{
    return ((PFN_ACXSTREAMGETNOTIFICATIONID) AcxFunctions[AcxStreamGetNotificationIdTableIndex])(AcxDriverGlobals, Stream);
}



#endif // (NTDDI_VERSION >= NTDDI_WIN2K)


WDF_EXTERN_C_END

#endif // _ACXSTREAMS_H_

