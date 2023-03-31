/*++

Copyright (c) Microsoft Corporation.  All rights reserved.

Module Name:

    AcxElements.h

Abstract:

    This is the interfaces for the Audio Class eXtension element objects

Environment:

    Kernel-mode.

Revision History:

--*/

//
// NOTE: This header is generated by stubwork.  Please make any 
//       modifications to the corresponding template files 
//       (.x or .y) and use stubwork to regenerate the header
//

#ifndef _ACXELEMENTS_H_
#define _ACXELEMENTS_H_

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
// ACX element defines and structures.
//
#define AcxElementIdNone    ((ULONG)(-1))
#define AcxElementIdDefault ((ULONG)(-1))

typedef struct _ACX_ELEMENT_CONFIG {
    ULONG               Size;
    ULONG               Id;
    const GUID *        Type;
    const GUID *        Name;
    ULONG               Flags;
    ULONG               PropertiesCount;
    ULONG               MethodsCount;
    PACX_PROPERTY_ITEM  Properties;
    PACX_METHOD_ITEM    Methods;
} ACX_ELEMENT_CONFIG, *PACX_ELEMENT_CONFIG;

typedef enum _ACX_ELEMENT_CONFIG_FLAGS {
    AcxElementConfigNoFlags     = 0x00000000,
    AcxElementConfigValidFlags  = 0x00000000
} ACX_ELEMENT_CONFIG_FLAGS;

VOID
FORCEINLINE
ACX_ELEMENT_CONFIG_INIT_ID(
    _Out_ PACX_ELEMENT_CONFIG Config,
    _In_  ULONG Id
    )
{
    RtlZeroMemory(Config, sizeof(ACX_ELEMENT_CONFIG));

    Config->Size = ACX_STRUCTURE_SIZE(ACX_ELEMENT_CONFIG);
    Config->Id = Id;
    Config->Flags = AcxElementConfigNoFlags;
}

#define ACX_ELEMENT_CONFIG_INIT(cfg) \
    ACX_ELEMENT_CONFIG_INIT_ID(cfg, AcxElementIdDefault)

//
// ACX mute element defines and structures.
//
typedef
_Function_class_(EVT_ACX_MUTE_ASSIGN_STATE)
_IRQL_requires_same_
_IRQL_requires_max_(PASSIVE_LEVEL)
NTSTATUS
NTAPI
EVT_ACX_MUTE_ASSIGN_STATE(
    _In_
    ACXMUTE Mute,
    _In_
    ULONG Channel,
    _In_
    ULONG State
    );

typedef EVT_ACX_MUTE_ASSIGN_STATE *PFN_ACX_MUTE_ASSIGN_STATE;

typedef
_Function_class_(EVT_ACX_MUTE_RETRIEVE_STATE)
_IRQL_requires_same_
_IRQL_requires_max_(PASSIVE_LEVEL)
NTSTATUS
NTAPI
EVT_ACX_MUTE_RETRIEVE_STATE(
    _In_
    ACXMUTE Mute,
    _In_
    ULONG Channel,
    _Out_
    ULONG * State
    );

typedef EVT_ACX_MUTE_RETRIEVE_STATE *PFN_ACX_MUTE_RETRIEVE_STATE;

typedef struct _ACX_MUTE_CALLBACKS {
    ULONG                           Size;
    PFN_ACX_MUTE_ASSIGN_STATE       EvtAcxMuteAssignState;
    PFN_ACX_MUTE_RETRIEVE_STATE     EvtAcxMuteRetrieveState;
    PFN_ACX_OBJECT_PROCESS_REQUEST  EvtAcxMuteProcessRequest;
} ACX_MUTE_CALLBACKS, *PACX_MUTE_CALLBACKS;

VOID
FORCEINLINE
ACX_MUTE_CALLBACKS_INIT(
    _Out_ PACX_MUTE_CALLBACKS Callbacks
    )
{
    RtlZeroMemory(Callbacks, sizeof(ACX_MUTE_CALLBACKS));
    Callbacks->Size = ACX_STRUCTURE_SIZE(ACX_MUTE_CALLBACKS);
}

typedef struct _ACX_MUTE_CONFIG {
    ULONG                   Size;
    ULONG                   Id;
    const GUID *            Name;
    ULONG                   Flags;
    ULONG                   ChannelsCount;
    PACX_MUTE_CALLBACKS     Callbacks;
} ACX_MUTE_CONFIG, *PACX_MUTE_CONFIG;

typedef enum _ACX_MUTE_CONFIG_FLAGS {
    AcxMuteConfigNoFlags        = 0x00000000,
    AcxMuteConfigValidFlags     = 0x00000000
} ACX_MUTE_CONFIG_FLAGS;

VOID
FORCEINLINE
ACX_MUTE_CONFIG_INIT_ID(
    _Out_ PACX_MUTE_CONFIG Config,
    _In_  ULONG Id
    )
{
    RtlZeroMemory(Config, sizeof(ACX_MUTE_CONFIG));

    Config->Size = ACX_STRUCTURE_SIZE(ACX_MUTE_CONFIG);
    Config->Id = Id;
    Config->Flags = AcxMuteConfigNoFlags;
}

#define ACX_MUTE_CONFIG_INIT(cfg) \
    ACX_MUTE_CONFIG_INIT_ID(cfg, AcxElementIdDefault)

//
// ACX volume element defines and structures.
//
typedef
_Function_class_(EVT_ACX_VOLUME_ASSIGN_LEVEL)
_IRQL_requires_same_
_IRQL_requires_max_(PASSIVE_LEVEL)
NTSTATUS
NTAPI
EVT_ACX_VOLUME_ASSIGN_LEVEL(
    _In_
    ACXVOLUME Volume,
    _In_
    ULONG Channel,
    _In_
    LONG VolumeLevel
    );

typedef EVT_ACX_VOLUME_ASSIGN_LEVEL *PFN_ACX_VOLUME_ASSIGN_LEVEL;

typedef enum _ACX_VOLUME_CURVE_TYPE
{
    AcxVolumeCurveTypeNone,
    AcxVolumeCurveTypeFade
} ACX_VOLUME_CURVE_TYPE, *PACX_VOLUME_CURVE_TYPE;

//
// ACX audioengine volume element defines and structures.
//
typedef
_Function_class_(EVT_ACX_RAMPED_VOLUME_ASSIGN_LEVEL)
_IRQL_requires_same_
_IRQL_requires_max_(PASSIVE_LEVEL)
NTSTATUS
NTAPI
EVT_ACX_RAMPED_VOLUME_ASSIGN_LEVEL(
    _In_
    ACXVOLUME Volume,
    _In_
    ULONG Channel,
    _In_
    LONG VolumeLevel,
    _In_
    ACX_VOLUME_CURVE_TYPE CurveType,
    _In_
    ULONGLONG CurveDuration
    );

typedef EVT_ACX_RAMPED_VOLUME_ASSIGN_LEVEL *PFN_ACX_RAMPED_VOLUME_ASSIGN_LEVEL;

typedef
_Function_class_(EVT_ACX_VOLUME_RETRIEVE_LEVEL)
_IRQL_requires_same_
_IRQL_requires_max_(PASSIVE_LEVEL)
NTSTATUS
NTAPI
EVT_ACX_VOLUME_RETRIEVE_LEVEL(
    _In_
    ACXVOLUME Volume,
    _In_
    ULONG Channel,
    _Out_
    LONG * VolumeLevel
    );

typedef EVT_ACX_VOLUME_RETRIEVE_LEVEL *PFN_ACX_VOLUME_RETRIEVE_LEVEL;

typedef struct _ACX_VOLUME_CALLBACKS {
    ULONG                                   Size;
    PFN_ACX_VOLUME_ASSIGN_LEVEL             EvtAcxVolumeAssignLevel;
    PFN_ACX_RAMPED_VOLUME_ASSIGN_LEVEL      EvtAcxRampedVolumeAssignLevel;
    PFN_ACX_VOLUME_RETRIEVE_LEVEL           EvtAcxVolumeRetrieveLevel;
    PFN_ACX_OBJECT_PROCESS_REQUEST          EvtAcxVolumeProcessRequest;
} ACX_VOLUME_CALLBACKS, *PACX_VOLUME_CALLBACKS;

VOID
FORCEINLINE
ACX_VOLUME_CALLBACKS_INIT(
    _Out_ PACX_VOLUME_CALLBACKS Callbacks
    )
{
    RtlZeroMemory(Callbacks, sizeof(ACX_VOLUME_CALLBACKS));
    Callbacks->Size = ACX_STRUCTURE_SIZE(ACX_VOLUME_CALLBACKS);
}

typedef struct _ACX_VOLUME_CONFIG {
    ULONG                   Size;
    ULONG                   Id;
    const GUID *            Name;
    ULONG                   Flags;
    ULONG                   ChannelsCount;
    LONG                    Maximum;
    LONG                    Minimum;
    ULONG                   SteppingDelta;
    PACX_VOLUME_CALLBACKS   Callbacks;
} ACX_VOLUME_CONFIG, *PACX_VOLUME_CONFIG;

typedef enum _ACX_VOLUME_CONFIG_FLAGS {
    AcxVolumeConfigNoFlags        = 0x00000000,
    AcxVolumeConfigValidFlags     = 0x00000000
} ACX_VOLUME_CONFIG_FLAGS;

VOID
FORCEINLINE
ACX_VOLUME_CONFIG_INIT_ID(
    _Out_ PACX_VOLUME_CONFIG Config,
    _In_  ULONG Id
    )
{
    RtlZeroMemory(Config, sizeof(ACX_VOLUME_CONFIG));

    Config->Size = ACX_STRUCTURE_SIZE(ACX_VOLUME_CONFIG);
    Config->Id = Id;
    Config->Flags = AcxVolumeConfigNoFlags;
}

#define ACX_VOLUME_CONFIG_INIT(cfg) \
    ACX_VOLUME_CONFIG_INIT_ID(cfg, AcxElementIdDefault)

//
// ACX peakmeter element defines and structures.
//
typedef
_Function_class_(EVT_ACX_PEAKMETER_RETRIEVE_LEVEL)
_IRQL_requires_same_
_IRQL_requires_max_(PASSIVE_LEVEL)
NTSTATUS
NTAPI
EVT_ACX_PEAKMETER_RETRIEVE_LEVEL(
    _In_
    ACXPEAKMETER PeakMeter,
    _In_
    ULONG Channel,
    _Out_
    LONG * Level
    );

typedef EVT_ACX_PEAKMETER_RETRIEVE_LEVEL *PFN_ACX_PEAKMETER_RETRIEVE_LEVEL;

typedef struct _ACX_PEAKMETER_CALLBACKS {
    ULONG                              Size;
    PFN_ACX_PEAKMETER_RETRIEVE_LEVEL   EvtAcxPeakMeterRetrieveLevel;
    PFN_ACX_OBJECT_PROCESS_REQUEST     EvtAcxPeakMeterProcessRequest;
} ACX_PEAKMETER_CALLBACKS, *PACX_PEAKMETER_CALLBACKS;

VOID
FORCEINLINE
ACX_PEAKMETER_CALLBACKS_INIT(
    _Out_ PACX_PEAKMETER_CALLBACKS Callbacks
    )
{
    RtlZeroMemory(Callbacks, sizeof(ACX_PEAKMETER_CALLBACKS));
    Callbacks->Size = ACX_STRUCTURE_SIZE(ACX_PEAKMETER_CALLBACKS);
}

typedef struct _ACX_PEAKMETER_CONFIG {
    ULONG                      Size;
    ULONG                      Id;
    const GUID *               Name;
    ULONG                      Flags;
    ULONG                      ChannelsCount;
    LONG                       Maximum;
    LONG                       Minimum;
    ULONG                      SteppingDelta;
    PACX_PEAKMETER_CALLBACKS   Callbacks;
} ACX_PEAKMETER_CONFIG, *PACX_PEAKMETER_CONFIG;

typedef enum _ACX_PEAKMETER_CONFIG_FLAGS {
    AcxPeakMeterConfigNoFlags        = 0x00000000,
    AcxPeakMeterConfigValidFlags     = 0x00000000
} ACX_PEAKMETER_CONFIG_FLAGS;

VOID
FORCEINLINE
ACX_PEAKMETER_CONFIG_INIT_ID(
    _Out_ PACX_PEAKMETER_CONFIG Config,
    _In_  ULONG Id
    )
{
    RtlZeroMemory(Config, sizeof(ACX_PEAKMETER_CONFIG));

    Config->Size = ACX_STRUCTURE_SIZE(ACX_PEAKMETER_CONFIG);
    Config->Id = Id;
    Config->Flags = AcxPeakMeterConfigNoFlags;
}

#define ACX_PEAKMETER_CONFIG_INIT(cfg) \
    ACX_PEAKMETER_CONFIG_INIT_ID(cfg, AcxElementIdDefault)

//
// ACX audioengine element defines and structures.
//
typedef
_Function_class_(EVT_ACX_AUDIOENGINE_RETRIEVE_BUFFER_SIZE_LIMITS)
_IRQL_requires_same_
_IRQL_requires_max_(PASSIVE_LEVEL)
NTSTATUS
NTAPI
EVT_ACX_AUDIOENGINE_RETRIEVE_BUFFER_SIZE_LIMITS(
    _In_
    ACXAUDIOENGINE AudioEngine,
    _In_
    ACXDATAFORMAT Format,
    _Out_
    PULONG MinBufferSizeInBytes,
    _Out_
    PULONG MaxBufferSizeInBytes
    );

typedef EVT_ACX_AUDIOENGINE_RETRIEVE_BUFFER_SIZE_LIMITS *PFN_ACX_AUDIOENGINE_RETRIEVE_BUFFER_SIZE_LIMITS;

typedef
_Function_class_(EVT_ACX_AUDIOENGINE_ASSIGN_EFFECTS_STATE)
_IRQL_requires_same_
_IRQL_requires_max_(PASSIVE_LEVEL)
NTSTATUS
NTAPI
EVT_ACX_AUDIOENGINE_ASSIGN_EFFECTS_STATE(
    _In_
    ACXAUDIOENGINE AudioEngine,
    _In_
    ULONG State
    );

typedef EVT_ACX_AUDIOENGINE_ASSIGN_EFFECTS_STATE *PFN_ACX_AUDIOENGINE_ASSIGN_EFFECTS_STATE;

typedef
_Function_class_(EVT_ACX_AUDIOENGINE_RETRIEVE_EFFECTS_STATE)
_IRQL_requires_same_
_IRQL_requires_max_(PASSIVE_LEVEL)
NTSTATUS
NTAPI
EVT_ACX_AUDIOENGINE_RETRIEVE_EFFECTS_STATE(
    _In_
    ACXAUDIOENGINE AudioEngine,
    _Out_
    PULONG State
    );

typedef EVT_ACX_AUDIOENGINE_RETRIEVE_EFFECTS_STATE *PFN_ACX_AUDIOENGINE_RETRIEVE_EFFECTS_STATE;

typedef
_Function_class_(EVT_ACX_STREAMAUDIOENGINE_ASSIGN_EFFECTS_STATE)
_IRQL_requires_same_
_IRQL_requires_max_(PASSIVE_LEVEL)
NTSTATUS
NTAPI
EVT_ACX_STREAMAUDIOENGINE_ASSIGN_EFFECTS_STATE(
    _In_
    ACXSTREAMAUDIOENGINE StreamAudioEngine,
    _In_
    ULONG State
    );

typedef EVT_ACX_STREAMAUDIOENGINE_ASSIGN_EFFECTS_STATE *PFN_ACX_STREAMAUDIOENGINE_ASSIGN_EFFECTS_STATE;

typedef
_Function_class_(EVT_ACX_STREAMAUDIOENGINE_RETRIEVE_EFFECTS_STATE)
_IRQL_requires_same_
_IRQL_requires_max_(PASSIVE_LEVEL)
NTSTATUS
NTAPI
EVT_ACX_STREAMAUDIOENGINE_RETRIEVE_EFFECTS_STATE(
    _In_
    ACXSTREAMAUDIOENGINE StreamAudioEngine,
    _Out_
    PULONG State
    );

typedef EVT_ACX_STREAMAUDIOENGINE_RETRIEVE_EFFECTS_STATE *PFN_ACX_STREAMAUDIOENGINE_RETRIEVE_EFFECTS_STATE;

typedef
_Function_class_(EVT_ACX_AUDIOENGINE_ASSIGN_ENGINE_FORMAT)
_IRQL_requires_same_
_IRQL_requires_max_(PASSIVE_LEVEL)
NTSTATUS
NTAPI
EVT_ACX_AUDIOENGINE_ASSIGN_ENGINE_FORMAT(
    _In_
    ACXAUDIOENGINE AudioEngine,
    _In_
    ACXDATAFORMAT Format
    );

typedef EVT_ACX_AUDIOENGINE_ASSIGN_ENGINE_FORMAT *PFN_ACX_AUDIOENGINE_ASSIGN_ENGINE_FORMAT;

typedef
_Function_class_(EVT_ACX_AUDIOENGINE_RETRIEVE_ENGINE_FORMAT)
_IRQL_requires_same_
_IRQL_requires_max_(PASSIVE_LEVEL)
NTSTATUS
NTAPI
EVT_ACX_AUDIOENGINE_RETRIEVE_ENGINE_FORMAT(
    _In_
    ACXAUDIOENGINE AudioEngine,
    _Out_
    ACXDATAFORMAT * Format
    );

typedef EVT_ACX_AUDIOENGINE_RETRIEVE_ENGINE_FORMAT *PFN_ACX_AUDIOENGINE_RETRIEVE_ENGINE_FORMAT;

typedef
_Function_class_(EVT_ACX_STREAMAUDIOENGINE_RETRIEVE_PRESENTATION_POSITION)
_IRQL_requires_same_
_IRQL_requires_max_(PASSIVE_LEVEL)
NTSTATUS
NTAPI
EVT_ACX_STREAMAUDIOENGINE_RETRIEVE_PRESENTATION_POSITION(
    _In_
    ACXSTREAMAUDIOENGINE StreamAudioEngine,
    _Out_
    PULONGLONG PositionInBlocks,
    _Out_
    PULONGLONG QPCPosition
    );

typedef EVT_ACX_STREAMAUDIOENGINE_RETRIEVE_PRESENTATION_POSITION *PFN_ACX_STREAMAUDIOENGINE_RETRIEVE_PRESENTATION_POSITION;

typedef
_Function_class_(EVT_ACX_STREAMAUDIOENGINE_ASSIGN_CURRENT_WRITE_POSITION)
_IRQL_requires_same_
_IRQL_requires_max_(PASSIVE_LEVEL)
NTSTATUS
NTAPI
EVT_ACX_STREAMAUDIOENGINE_ASSIGN_CURRENT_WRITE_POSITION(
    _In_
    ACXSTREAMAUDIOENGINE StreamAudioEngine,
    _In_
    ULONG Position
    );

typedef EVT_ACX_STREAMAUDIOENGINE_ASSIGN_CURRENT_WRITE_POSITION *PFN_ACX_STREAMAUDIOENGINE_ASSIGN_CURRENT_WRITE_POSITION;

typedef
_Function_class_(EVT_ACX_STREAMAUDIOENGINE_RETRIEVE_LINEAR_BUFFER_POSITION)
_IRQL_requires_same_
_IRQL_requires_max_(PASSIVE_LEVEL)
NTSTATUS
NTAPI
EVT_ACX_STREAMAUDIOENGINE_RETRIEVE_LINEAR_BUFFER_POSITION(
    _In_
    ACXSTREAMAUDIOENGINE StreamAudioEngine,
    _Out_
    PULONGLONG Position
    );

typedef EVT_ACX_STREAMAUDIOENGINE_RETRIEVE_LINEAR_BUFFER_POSITION *PFN_ACX_STREAMAUDIOENGINE_RETRIEVE_LINEAR_BUFFER_POSITION;

typedef
_Function_class_(EVT_ACX_STREAMAUDIOENGINE_ASSIGN_LAST_BUFFER_POSITION)
_IRQL_requires_same_
_IRQL_requires_max_(PASSIVE_LEVEL)
NTSTATUS
NTAPI
EVT_ACX_STREAMAUDIOENGINE_ASSIGN_LAST_BUFFER_POSITION(
    _In_
    ACXSTREAMAUDIOENGINE StreamAudioEngine,
    _In_
    ULONG Position
    );

typedef EVT_ACX_STREAMAUDIOENGINE_ASSIGN_LAST_BUFFER_POSITION *PFN_ACX_STREAMAUDIOENGINE_ASSIGN_LAST_BUFFER_POSITION;

typedef enum _ACX_CONSTRICTOR_OPTION {
    AcxConstrictorOptionNone = 0,
    AcxConstrictorOptionMute
} ACX_CONSTRICTOR_OPTION;

typedef
_Function_class_(EVT_ACX_STREAMAUDIOENGINE_ASSIGN_LOOPBACK_PROTECTION)
_IRQL_requires_same_
_IRQL_requires_max_(PASSIVE_LEVEL)
NTSTATUS
NTAPI
EVT_ACX_STREAMAUDIOENGINE_ASSIGN_LOOPBACK_PROTECTION(
    _In_
    ACXSTREAMAUDIOENGINE StreamAudioEngine,
    _In_
    ACX_CONSTRICTOR_OPTION ConstrictorOption
    );

typedef EVT_ACX_STREAMAUDIOENGINE_ASSIGN_LOOPBACK_PROTECTION *PFN_ACX_STREAMAUDIOENGINE_ASSIGN_LOOPBACK_PROTECTION;

typedef struct _ACX_AUDIOENGINE_CALLBACKS {
    ULONG                                               Size;
    PFN_ACX_AUDIOENGINE_RETRIEVE_BUFFER_SIZE_LIMITS     EvtAcxAudioEngineRetrieveBufferSizeLimits;
    PFN_ACX_AUDIOENGINE_ASSIGN_EFFECTS_STATE            EvtAcxAudioEngineAssignEffectsState;
    PFN_ACX_AUDIOENGINE_RETRIEVE_EFFECTS_STATE          EvtAcxAudioEngineRetrieveEffectsState;
    PFN_ACX_AUDIOENGINE_RETRIEVE_ENGINE_FORMAT          EvtAcxAudioEngineRetrieveEngineMixFormat;
    PFN_ACX_AUDIOENGINE_ASSIGN_ENGINE_FORMAT            EvtAcxAudioEngineAssignEngineDeviceFormat;
    PFN_ACX_OBJECT_PROCESS_REQUEST                      EvtAcxAudioEngineProcessRequest;
} ACX_AUDIOENGINE_CALLBACKS, *PACX_AUDIOENGINE_CALLBACKS;

VOID
FORCEINLINE
ACX_AUDIOENGINE_CALLBACKS_INIT(
    _Out_ PACX_AUDIOENGINE_CALLBACKS Callbacks
    )
{
    RtlZeroMemory(Callbacks, sizeof(ACX_AUDIOENGINE_CALLBACKS));
    Callbacks->Size = ACX_STRUCTURE_SIZE(ACX_AUDIOENGINE_CALLBACKS);
}

typedef struct _ACX_AUDIOENGINE_CONFIG {
    ULONG                       Size;
    ULONG                       Id;
    const GUID *                Name;
    ULONG                       Flags;
    ACXPIN                      HostPin;
    ACXPIN                      OffloadPin;
    ACXPIN                      LoopbackPin;
    ACXVOLUME                   VolumeElement;
    ACXMUTE                     MuteElement;
    ACXPEAKMETER                PeakMeterElement;
    PACX_AUDIOENGINE_CALLBACKS  Callbacks;
} ACX_AUDIOENGINE_CONFIG, *PACX_AUDIOENGINE_CONFIG;

typedef enum _ACX_AUDIOENGINE_CONFIG_FLAGS {
    AcxAudioEngineConfigNoFlags             = 0x00000000,
    AcxAudioEngineConfigVolumeNotPresent    = 0x00000001,
    AcxAudioEngineConfigVolumeSecondary     = 0x00000002,
    AcxAudioEngineConfigMuteNotPresent      = 0x00000004,
    AcxAudioEngineConfigMuteSecondary       = 0x00000008,
    AcxAudioEngineConfigPeakMeterNotPresent = 0x00000010,
    AcxAudioEngineConfigPeakMeterSecondary  = 0x00000020,
    AcxAudioEngineConfigValidFlags          = 0x0000003F
} ACX_AUDIOENGINE_CONFIG_FLAGS;

VOID
FORCEINLINE
ACX_AUDIOENGINE_CONFIG_INIT_ID(
    _Out_ PACX_AUDIOENGINE_CONFIG Config,
    _In_  ULONG Id
    )
{
    RtlZeroMemory(Config, sizeof(ACX_AUDIOENGINE_CONFIG));

    Config->Size = ACX_STRUCTURE_SIZE(ACX_AUDIOENGINE_CONFIG);
    Config->Id = Id;
    Config->Flags = AcxAudioEngineConfigNoFlags;
}

#define ACX_AUDIOENGINE_CONFIG_INIT(cfg) \
    ACX_AUDIOENGINE_CONFIG_INIT_ID(cfg, AcxElementIdDefault)

typedef struct _ACX_STREAMAUDIOENGINE_CALLBACKS {
    ULONG                                                       Size;
    PFN_ACX_STREAMAUDIOENGINE_ASSIGN_EFFECTS_STATE              EvtAcxStreamAudioEngineAssignEffectsState;
    PFN_ACX_STREAMAUDIOENGINE_RETRIEVE_EFFECTS_STATE            EvtAcxStreamAudioEngineRetrieveEffectsState;
    PFN_ACX_STREAMAUDIOENGINE_RETRIEVE_PRESENTATION_POSITION    EvtAcxStreamAudioEngineRetrievePresentationPosition;
    PFN_ACX_STREAMAUDIOENGINE_ASSIGN_CURRENT_WRITE_POSITION     EvtAcxStreamAudioEngineAssignCurrentWritePosition;
    PFN_ACX_STREAMAUDIOENGINE_RETRIEVE_LINEAR_BUFFER_POSITION   EvtAcxStreamAudioEngineRetrieveLinearBufferPosition;
    PFN_ACX_STREAMAUDIOENGINE_ASSIGN_LAST_BUFFER_POSITION       EvtAcxStreamAudioEngineAssignLastBufferPosition;
    PFN_ACX_STREAMAUDIOENGINE_ASSIGN_LOOPBACK_PROTECTION        EvtAcxStreamAudioEngineAssignLoopbackProtection;
    PFN_ACX_OBJECT_PROCESS_REQUEST                              EvtAcxStreamAudioEngineProcessRequest;
} ACX_STREAMAUDIOENGINE_CALLBACKS, *PACX_STREAMAUDIOENGINE_CALLBACKS;

VOID
FORCEINLINE
ACX_STREAMAUDIOENGINE_CALLBACKS_INIT(
    _Out_ PACX_STREAMAUDIOENGINE_CALLBACKS Callbacks
    )
{
    RtlZeroMemory(Callbacks, sizeof(ACX_STREAMAUDIOENGINE_CALLBACKS));
    Callbacks->Size = ACX_STRUCTURE_SIZE(ACX_STREAMAUDIOENGINE_CALLBACKS);
}

typedef struct _ACX_STREAMAUDIOENGINE_CONFIG {
    ULONG                               Size;
    ULONG                               Id;
    const GUID *                        Name;
    ULONG                               Flags;
    ACXVOLUME                           VolumeElement;
    ACXMUTE                             MuteElement;
    ACXPEAKMETER                        PeakMeterElement;
    PACX_STREAMAUDIOENGINE_CALLBACKS    Callbacks;
} ACX_STREAMAUDIOENGINE_CONFIG, *PACX_STREAMAUDIOENGINE_CONFIG;

typedef enum _ACX_STREAMAUDIOENGINE_CONFIG_FLAGS {
    AcxStreamAudioEngineConfigNoFlags        = 0x00000000,
    AcxStreamAudioEngineConfigValidFlags     = 0x00000000
} ACX_STREAMAUDIOENGINE_CONFIG_FLAGS;

VOID
FORCEINLINE
ACX_STREAMAUDIOENGINE_CONFIG_INIT_ID(
    _Out_ PACX_STREAMAUDIOENGINE_CONFIG Config,
    _In_  ULONG Id
    )
{
    RtlZeroMemory(Config, sizeof(ACX_STREAMAUDIOENGINE_CONFIG));

    Config->Size = ACX_STRUCTURE_SIZE(ACX_STREAMAUDIOENGINE_CONFIG);
    Config->Id = Id;
    Config->Flags = AcxStreamAudioEngineConfigNoFlags;
}

#define ACX_STREAMAUDIOENGINE_CONFIG_INIT(cfg) \
    ACX_STREAMAUDIOENGINE_CONFIG_INIT_ID(cfg, AcxElementIdDefault)

//
// ACX keywordspotter element defines and structures.
//
typedef
_Function_class_(EVT_ACX_KEYWORDSPOTTER_RETRIEVE_ARM)
_IRQL_requires_same_
_IRQL_requires_max_(PASSIVE_LEVEL)
NTSTATUS
NTAPI
EVT_ACX_KEYWORDSPOTTER_RETRIEVE_ARM(
    _In_
    ACXKEYWORDSPOTTER KeywordSpotter,
    _In_
    GUID * EventId,
    _Out_
    PBOOLEAN Arm
    );

typedef EVT_ACX_KEYWORDSPOTTER_RETRIEVE_ARM *PFN_ACX_KEYWORDSPOTTER_RETRIEVE_ARM;

typedef
_Function_class_(EVT_ACX_KEYWORDSPOTTER_ASSIGN_ARM)
_IRQL_requires_same_
_IRQL_requires_max_(PASSIVE_LEVEL)
NTSTATUS
NTAPI
EVT_ACX_KEYWORDSPOTTER_ASSIGN_ARM(
    _In_
    ACXKEYWORDSPOTTER KeywordSpotter,
    _In_
    GUID * EventId,
    _In_
    BOOLEAN Arm
    );

typedef EVT_ACX_KEYWORDSPOTTER_ASSIGN_ARM *PFN_ACX_KEYWORDSPOTTER_ASSIGN_ARM;

typedef
_Function_class_(EVT_ACX_KEYWORDSPOTTER_ASSIGN_PATTERNS)
_IRQL_requires_same_
_IRQL_requires_max_(PASSIVE_LEVEL)
NTSTATUS
NTAPI
EVT_ACX_KEYWORDSPOTTER_ASSIGN_PATTERNS(
    _In_
    ACXKEYWORDSPOTTER KeywordSpotter,
    _In_
    GUID * EventId,
    _In_
    PVOID Pattern,
    _In_
    ULONG PatternSize
    );

typedef EVT_ACX_KEYWORDSPOTTER_ASSIGN_PATTERNS *PFN_ACX_KEYWORDSPOTTER_ASSIGN_PATTERNS;

typedef
_Function_class_(EVT_ACX_KEYWORDSPOTTER_ASSIGN_RESET)
_IRQL_requires_same_
_IRQL_requires_max_(PASSIVE_LEVEL)
NTSTATUS
NTAPI
EVT_ACX_KEYWORDSPOTTER_ASSIGN_RESET(
    _In_
    ACXKEYWORDSPOTTER KeywordSpotter,
    _In_
    GUID * EventId
    );

typedef EVT_ACX_KEYWORDSPOTTER_ASSIGN_RESET *PFN_ACX_KEYWORDSPOTTER_ASSIGN_RESET;

typedef struct _ACX_KEYWORDSPOTTER_CALLBACKS {
    ULONG                                   Size;
    PFN_ACX_KEYWORDSPOTTER_RETRIEVE_ARM     EvtAcxKeywordSpotterRetrieveArm;
    PFN_ACX_KEYWORDSPOTTER_ASSIGN_ARM       EvtAcxKeywordSpotterAssignArm;
    PFN_ACX_KEYWORDSPOTTER_ASSIGN_PATTERNS  EvtAcxKeywordSpotterAssignPatterns;
    PFN_ACX_KEYWORDSPOTTER_ASSIGN_RESET     EvtAcxKeywordSpotterAssignReset;
} ACX_KEYWORDSPOTTER_CALLBACKS, *PACX_KEYWORDSPOTTER_CALLBACKS;

VOID
FORCEINLINE
ACX_KEYWORDSPOTTER_CALLBACKS_INIT(
    _Out_ PACX_KEYWORDSPOTTER_CALLBACKS Callbacks
    )
{
    RtlZeroMemory(Callbacks, sizeof(ACX_KEYWORDSPOTTER_CALLBACKS));
    Callbacks->Size = ACX_STRUCTURE_SIZE(ACX_KEYWORDSPOTTER_CALLBACKS);
}

typedef struct _ACX_KEYWORDSPOTTER_CONFIG {
    ULONG                           Size;
    ULONG                           Id;
    const GUID *                    Name;
    ULONG                           Flags;
    const GUID *                    Pattern;
    PACX_KEYWORDSPOTTER_CALLBACKS   Callbacks;
} ACX_KEYWORDSPOTTER_CONFIG, *PACX_KEYWORDSPOTTER_CONFIG;

typedef enum _ACX_KEYWORDSPOTTER_CONFIG_FLAGS {
    AcxKeywordSpotterConfigNoFlags        = 0x00000000,
    AcxKeywordSpotterConfigValidFlags     = 0x00000000
} ACX_KEYWORDSPOTTER_CONFIG_FLAGS;

VOID
FORCEINLINE
ACX_KEYWORDSPOTTER_CONFIG_INIT_ID(
    _Out_ PACX_KEYWORDSPOTTER_CONFIG Config,
    _In_  ULONG Id
    )
{
    RtlZeroMemory(Config, sizeof(ACX_KEYWORDSPOTTER_CONFIG));

    Config->Size = ACX_STRUCTURE_SIZE(ACX_KEYWORDSPOTTER_CONFIG);
    Config->Id = Id;
    Config->Flags = AcxKeywordSpotterConfigNoFlags;
}

#define ACX_KEYWORDSPOTTER_CONFIG_INIT(cfg) \
    ACX_KEYWORDSPOTTER_CONFIG_INIT_ID(cfg, AcxElementIdDefault)

//
// ACX audiomodules element defines and structures.
//
typedef
_Function_class_(EVT_ACX_AUDIOMODULE_PROCESSCOMMAND)
_IRQL_requires_same_
_IRQL_requires_max_(PASSIVE_LEVEL)
NTSTATUS
NTAPI
EVT_ACX_AUDIOMODULE_PROCESSCOMMAND(
    _In_
    ACXAUDIOMODULE AudioModule,
    _In_
    PVOID InBuffer,
    _In_
    ULONG InBufferCb,
    _In_
    PVOID OutBuffer,
    _Inout_
    PULONG OutBufferCb
    );

typedef EVT_ACX_AUDIOMODULE_PROCESSCOMMAND *PFN_ACX_AUDIOMODULE_PROCESSCOMMAND;

typedef struct _ACX_AUDIOMODULE_CALLBACKS {
    ULONG                                   Size;
    PFN_ACX_AUDIOMODULE_PROCESSCOMMAND      EvtAcxAudioModuleProcessCommand;
} ACX_AUDIOMODULE_CALLBACKS, *PACX_AUDIOMODULE_CALLBACKS;

#define ACX_AUDIOMODULE_MAX_NAME_CCH_SIZE 128

typedef struct _ACX_AUDIOMODULE_DESCRIPTOR
{
    GUID        ClassId; 
    ULONG       InstanceId;
    ULONG       VersionMajor;
    ULONG       VersionMinor;
    WCHAR       Name[ACX_AUDIOMODULE_MAX_NAME_CCH_SIZE];
} ACX_AUDIOMODULE_DESCRIPTOR, *PACX_AUDIOMODULE_DESCRIPTOR;

VOID
FORCEINLINE
ACX_AUDIOMODULE_CALLBACKS_INIT(
    _Out_ PACX_AUDIOMODULE_CALLBACKS Callbacks
    )
{
    RtlZeroMemory(Callbacks, sizeof(ACX_AUDIOMODULE_CALLBACKS));
    Callbacks->Size = ACX_STRUCTURE_SIZE(ACX_AUDIOMODULE_CALLBACKS);
}

typedef struct _ACX_AUDIOMODULE_CONFIG {
    ULONG                           Size;
    ULONG                           Id;
    const GUID *                    Name;
    ULONG                           Flags;
    ACX_AUDIOMODULE_DESCRIPTOR      Descriptor;
    PACX_AUDIOMODULE_CALLBACKS      Callbacks;
} ACX_AUDIOMODULE_CONFIG, *PACX_AUDIOMODULE_CONFIG;

typedef enum _ACX_AUDIOMODULE_CONFIG_FLAGS {
    AcxAudioModuleConfigNoFlags        = 0x00000000,
    AcxAudioModuleConfigValidFlags     = 0x00000000
} ACX_AUDIOMODULE_CONFIG_FLAGS;

VOID
FORCEINLINE
ACX_AUDIOMODULE_CONFIG_INIT_ID(
    _Out_ PACX_AUDIOMODULE_CONFIG Config,
    _In_  ULONG Id
    )
{
    RtlZeroMemory(Config, sizeof(ACX_AUDIOMODULE_CONFIG));

    Config->Size = ACX_STRUCTURE_SIZE(ACX_AUDIOMODULE_CONFIG);
    Config->Id = Id;
    Config->Flags = AcxAudioModuleConfigNoFlags;
}

#define ACX_AUDIOMODULE_CONFIG_INIT(cfg) \
    ACX_AUDIOMODULE_CONFIG_INIT_ID(cfg, AcxElementIdDefault)


//
// ACX Function: AcxElementCreate
//
typedef
_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
WDFAPI
NTSTATUS
(NTAPI *PFN_ACXELEMENTCREATE)(
    _In_
    PACX_DRIVER_GLOBALS DriverGlobals,
    _In_
    ACXOBJECT Object,
    _In_
    PWDF_OBJECT_ATTRIBUTES Attributes,
    _In_
    PACX_ELEMENT_CONFIG Config,
    _Out_
    ACXELEMENT* Element
    );

_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
FORCEINLINE
NTSTATUS
AcxElementCreate(
    _In_
    ACXOBJECT Object,
    _In_
    PWDF_OBJECT_ATTRIBUTES Attributes,
    _In_
    PACX_ELEMENT_CONFIG Config,
    _Out_
    ACXELEMENT* Element
    )
{
    return ((PFN_ACXELEMENTCREATE) AcxFunctions[AcxElementCreateTableIndex])(AcxDriverGlobals, Object, Attributes, Config, Element);
}

//
// ACX Function: AcxElementAddEvents
//
typedef
_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
WDFAPI
NTSTATUS
(NTAPI *PFN_ACXELEMENTADDEVENTS)(
    _In_
    PACX_DRIVER_GLOBALS DriverGlobals,
    _In_
    ACXELEMENT Element,
    _In_reads_(EventsCount)
    ACXEVENT* Events,
    _In_
    ULONG EventsCount
    );

_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
FORCEINLINE
NTSTATUS
AcxElementAddEvents(
    _In_
    ACXELEMENT Element,
    _In_reads_(EventsCount)
    ACXEVENT* Events,
    _In_
    ULONG EventsCount
    )
{
    return ((PFN_ACXELEMENTADDEVENTS) AcxFunctions[AcxElementAddEventsTableIndex])(AcxDriverGlobals, Element, Events, EventsCount);
}

//
// ACX Function: AcxElementGetId
//
typedef
_Must_inspect_result_
_IRQL_requires_max_(DISPATCH_LEVEL)
WDFAPI
ULONG
(NTAPI *PFN_ACXELEMENTGETID)(
    _In_
    PACX_DRIVER_GLOBALS DriverGlobals,
    _In_
    ACXELEMENT Element
    );

_Must_inspect_result_
_IRQL_requires_max_(DISPATCH_LEVEL)
FORCEINLINE
ULONG
AcxElementGetId(
    _In_
    ACXELEMENT Element
    )
{
    return ((PFN_ACXELEMENTGETID) AcxFunctions[AcxElementGetIdTableIndex])(AcxDriverGlobals, Element);
}

//
// ACX Function: AcxElementGetContainer
//
typedef
_IRQL_requires_max_(DISPATCH_LEVEL)
WDFAPI
ACXOBJECT
(NTAPI *PFN_ACXELEMENTGETCONTAINER)(
    _In_
    PACX_DRIVER_GLOBALS DriverGlobals,
    _In_
    ACXELEMENT Element
    );

_IRQL_requires_max_(DISPATCH_LEVEL)
FORCEINLINE
ACXOBJECT
AcxElementGetContainer(
    _In_
    ACXELEMENT Element
    )
{
    return ((PFN_ACXELEMENTGETCONTAINER) AcxFunctions[AcxElementGetContainerTableIndex])(AcxDriverGlobals, Element);
}

//
// ACX Function: AcxMuteCreate
//
typedef
_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
WDFAPI
NTSTATUS
(NTAPI *PFN_ACXMUTECREATE)(
    _In_
    PACX_DRIVER_GLOBALS DriverGlobals,
    _In_
    ACXOBJECT Object,
    _In_
    PWDF_OBJECT_ATTRIBUTES Attributes,
    _In_
    PACX_MUTE_CONFIG Config,
    _Out_
    ACXMUTE* Mute
    );

_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
FORCEINLINE
NTSTATUS
AcxMuteCreate(
    _In_
    ACXOBJECT Object,
    _In_
    PWDF_OBJECT_ATTRIBUTES Attributes,
    _In_
    PACX_MUTE_CONFIG Config,
    _Out_
    ACXMUTE* Mute
    )
{
    return ((PFN_ACXMUTECREATE) AcxFunctions[AcxMuteCreateTableIndex])(AcxDriverGlobals, Object, Attributes, Config, Mute);
}

//
// ACX Function: AcxMuteChangeStateNotification
//
typedef
WDFAPI
VOID
(NTAPI *PFN_ACXMUTECHANGESTATENOTIFICATION)(
    _In_
    PACX_DRIVER_GLOBALS DriverGlobals,
    _In_
    ACXMUTE Mute
    );

FORCEINLINE
VOID
AcxMuteChangeStateNotification(
    _In_
    ACXMUTE Mute
    )
{
    ((PFN_ACXMUTECHANGESTATENOTIFICATION) AcxFunctions[AcxMuteChangeStateNotificationTableIndex])(AcxDriverGlobals, Mute);
}

//
// ACX Function: AcxVolumeCreate
//
typedef
_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
WDFAPI
NTSTATUS
(NTAPI *PFN_ACXVOLUMECREATE)(
    _In_
    PACX_DRIVER_GLOBALS DriverGlobals,
    _In_
    ACXOBJECT Object,
    _In_
    PWDF_OBJECT_ATTRIBUTES Attributes,
    _In_
    PACX_VOLUME_CONFIG Config,
    _Out_
    ACXVOLUME* Volume
    );

_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
FORCEINLINE
NTSTATUS
AcxVolumeCreate(
    _In_
    ACXOBJECT Object,
    _In_
    PWDF_OBJECT_ATTRIBUTES Attributes,
    _In_
    PACX_VOLUME_CONFIG Config,
    _Out_
    ACXVOLUME* Volume
    )
{
    return ((PFN_ACXVOLUMECREATE) AcxFunctions[AcxVolumeCreateTableIndex])(AcxDriverGlobals, Object, Attributes, Config, Volume);
}

//
// ACX Function: AcxVolumeChangeLevelNotification
//
typedef
WDFAPI
VOID
(NTAPI *PFN_ACXVOLUMECHANGELEVELNOTIFICATION)(
    _In_
    PACX_DRIVER_GLOBALS DriverGlobals,
    _In_
    ACXVOLUME Volume
    );

FORCEINLINE
VOID
AcxVolumeChangeLevelNotification(
    _In_
    ACXVOLUME Volume
    )
{
    ((PFN_ACXVOLUMECHANGELEVELNOTIFICATION) AcxFunctions[AcxVolumeChangeLevelNotificationTableIndex])(AcxDriverGlobals, Volume);
}

//
// ACX Function: AcxPeakMeterCreate
//
typedef
_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
WDFAPI
NTSTATUS
(NTAPI *PFN_ACXPEAKMETERCREATE)(
    _In_
    PACX_DRIVER_GLOBALS DriverGlobals,
    _In_
    ACXOBJECT Object,
    _In_
    PWDF_OBJECT_ATTRIBUTES Attributes,
    _In_
    PACX_PEAKMETER_CONFIG Config,
    _Out_
    ACXPEAKMETER* PeakMeter
    );

_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
FORCEINLINE
NTSTATUS
AcxPeakMeterCreate(
    _In_
    ACXOBJECT Object,
    _In_
    PWDF_OBJECT_ATTRIBUTES Attributes,
    _In_
    PACX_PEAKMETER_CONFIG Config,
    _Out_
    ACXPEAKMETER* PeakMeter
    )
{
    return ((PFN_ACXPEAKMETERCREATE) AcxFunctions[AcxPeakMeterCreateTableIndex])(AcxDriverGlobals, Object, Attributes, Config, PeakMeter);
}

//
// ACX Function: AcxAudioEngineCreate
//
typedef
_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
WDFAPI
NTSTATUS
(NTAPI *PFN_ACXAUDIOENGINECREATE)(
    _In_
    PACX_DRIVER_GLOBALS DriverGlobals,
    _In_
    ACXCIRCUIT Object,
    _In_
    PWDF_OBJECT_ATTRIBUTES Attributes,
    _In_
    PACX_AUDIOENGINE_CONFIG Config,
    _Out_
    ACXAUDIOENGINE* AudioEngine
    );

_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
FORCEINLINE
NTSTATUS
AcxAudioEngineCreate(
    _In_
    ACXCIRCUIT Object,
    _In_
    PWDF_OBJECT_ATTRIBUTES Attributes,
    _In_
    PACX_AUDIOENGINE_CONFIG Config,
    _Out_
    ACXAUDIOENGINE* AudioEngine
    )
{
    return ((PFN_ACXAUDIOENGINECREATE) AcxFunctions[AcxAudioEngineCreateTableIndex])(AcxDriverGlobals, Object, Attributes, Config, AudioEngine);
}

//
// ACX Function: AcxAudioEngineGetDeviceFormatList
//
typedef
_IRQL_requires_max_(PASSIVE_LEVEL)
WDFAPI
ACXDATAFORMATLIST
(NTAPI *PFN_ACXAUDIOENGINEGETDEVICEFORMATLIST)(
    _In_
    PACX_DRIVER_GLOBALS DriverGlobals,
    _In_
    ACXAUDIOENGINE AudioEngine
    );

_IRQL_requires_max_(PASSIVE_LEVEL)
FORCEINLINE
ACXDATAFORMATLIST
AcxAudioEngineGetDeviceFormatList(
    _In_
    ACXAUDIOENGINE AudioEngine
    )
{
    return ((PFN_ACXAUDIOENGINEGETDEVICEFORMATLIST) AcxFunctions[AcxAudioEngineGetDeviceFormatListTableIndex])(AcxDriverGlobals, AudioEngine);
}

//
// ACX Function: AcxStreamAudioEngineCreate
//
typedef
_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
WDFAPI
NTSTATUS
(NTAPI *PFN_ACXSTREAMAUDIOENGINECREATE)(
    _In_
    PACX_DRIVER_GLOBALS DriverGlobals,
    _In_
    ACXSTREAM Stream,
    _In_
    ACXAUDIOENGINE AudioEngine,
    _In_
    PWDF_OBJECT_ATTRIBUTES Attributes,
    _In_
    PACX_STREAMAUDIOENGINE_CONFIG Config,
    _Out_
    ACXSTREAMAUDIOENGINE* StreamAudioEngine
    );

_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
FORCEINLINE
NTSTATUS
AcxStreamAudioEngineCreate(
    _In_
    ACXSTREAM Stream,
    _In_
    ACXAUDIOENGINE AudioEngine,
    _In_
    PWDF_OBJECT_ATTRIBUTES Attributes,
    _In_
    PACX_STREAMAUDIOENGINE_CONFIG Config,
    _Out_
    ACXSTREAMAUDIOENGINE* StreamAudioEngine
    )
{
    return ((PFN_ACXSTREAMAUDIOENGINECREATE) AcxFunctions[AcxStreamAudioEngineCreateTableIndex])(AcxDriverGlobals, Stream, AudioEngine, Attributes, Config, StreamAudioEngine);
}

//
// ACX Function: AcxStreamAudioEngineGetStream
//
typedef
_IRQL_requires_max_(PASSIVE_LEVEL)
WDFAPI
ACXSTREAM
(NTAPI *PFN_ACXSTREAMAUDIOENGINEGETSTREAM)(
    _In_
    PACX_DRIVER_GLOBALS DriverGlobals,
    _In_
    ACXSTREAMAUDIOENGINE StreamAudioEngine
    );

_IRQL_requires_max_(PASSIVE_LEVEL)
FORCEINLINE
ACXSTREAM
AcxStreamAudioEngineGetStream(
    _In_
    ACXSTREAMAUDIOENGINE StreamAudioEngine
    )
{
    return ((PFN_ACXSTREAMAUDIOENGINEGETSTREAM) AcxFunctions[AcxStreamAudioEngineGetStreamTableIndex])(AcxDriverGlobals, StreamAudioEngine);
}

//
// ACX Function: AcxKeywordSpotterCreate
//
typedef
_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
WDFAPI
NTSTATUS
(NTAPI *PFN_ACXKEYWORDSPOTTERCREATE)(
    _In_
    PACX_DRIVER_GLOBALS DriverGlobals,
    _In_
    ACXCIRCUIT Object,
    _In_
    PWDF_OBJECT_ATTRIBUTES Attributes,
    _In_
    PACX_KEYWORDSPOTTER_CONFIG Config,
    _Out_
    ACXKEYWORDSPOTTER* KeywordSpotter
    );

_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
FORCEINLINE
NTSTATUS
AcxKeywordSpotterCreate(
    _In_
    ACXCIRCUIT Object,
    _In_
    PWDF_OBJECT_ATTRIBUTES Attributes,
    _In_
    PACX_KEYWORDSPOTTER_CONFIG Config,
    _Out_
    ACXKEYWORDSPOTTER* KeywordSpotter
    )
{
    return ((PFN_ACXKEYWORDSPOTTERCREATE) AcxFunctions[AcxKeywordSpotterCreateTableIndex])(AcxDriverGlobals, Object, Attributes, Config, KeywordSpotter);
}

//
// ACX Function: AcxAudioModuleCreate
//
typedef
_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
WDFAPI
NTSTATUS
(NTAPI *PFN_ACXAUDIOMODULECREATE)(
    _In_
    PACX_DRIVER_GLOBALS DriverGlobals,
    _In_
    ACXOBJECT Object,
    _In_
    PWDF_OBJECT_ATTRIBUTES Attributes,
    _In_
    PACX_AUDIOMODULE_CONFIG Config,
    _Out_
    ACXAUDIOMODULE* AudioModule
    );

_Must_inspect_result_
_IRQL_requires_max_(PASSIVE_LEVEL)
FORCEINLINE
NTSTATUS
AcxAudioModuleCreate(
    _In_
    ACXOBJECT Object,
    _In_
    PWDF_OBJECT_ATTRIBUTES Attributes,
    _In_
    PACX_AUDIOMODULE_CONFIG Config,
    _Out_
    ACXAUDIOMODULE* AudioModule
    )
{
    return ((PFN_ACXAUDIOMODULECREATE) AcxFunctions[AcxAudioModuleCreateTableIndex])(AcxDriverGlobals, Object, Attributes, Config, AudioModule);
}



#endif // (NTDDI_VERSION >= NTDDI_WIN2K)


WDF_EXTERN_C_END

#endif // _ACXELEMENTS_H_

