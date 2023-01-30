

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0628 */
/* @@MIDL_FILE_HEADING(  ) */



/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

/* verify that the <rpcsal.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCSAL_H_VERSION__
#define __REQUIRED_RPCSAL_H_VERSION__ 100
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __audioengineextensionapo_h__
#define __audioengineextensionapo_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#ifndef DECLSPEC_XFGVIRT
#if defined(_CONTROL_FLOW_GUARD_XFG)
#define DECLSPEC_XFGVIRT(base, func) __declspec(xfg_virtual(base, func))
#else
#define DECLSPEC_XFGVIRT(base, func)
#endif
#endif

/* Forward Declarations */ 

#ifndef __IAudioSystemEffects3_FWD_DEFINED__
#define __IAudioSystemEffects3_FWD_DEFINED__
typedef interface IAudioSystemEffects3 IAudioSystemEffects3;

#endif 	/* __IAudioSystemEffects3_FWD_DEFINED__ */


#ifndef __IAudioProcessingObjectRTQueueService_FWD_DEFINED__
#define __IAudioProcessingObjectRTQueueService_FWD_DEFINED__
typedef interface IAudioProcessingObjectRTQueueService IAudioProcessingObjectRTQueueService;

#endif 	/* __IAudioProcessingObjectRTQueueService_FWD_DEFINED__ */


#ifndef __IAudioProcessingObjectLoggingService_FWD_DEFINED__
#define __IAudioProcessingObjectLoggingService_FWD_DEFINED__
typedef interface IAudioProcessingObjectLoggingService IAudioProcessingObjectLoggingService;

#endif 	/* __IAudioProcessingObjectLoggingService_FWD_DEFINED__ */


#ifndef __IAudioProcessingObjectNotifications_FWD_DEFINED__
#define __IAudioProcessingObjectNotifications_FWD_DEFINED__
typedef interface IAudioProcessingObjectNotifications IAudioProcessingObjectNotifications;

#endif 	/* __IAudioProcessingObjectNotifications_FWD_DEFINED__ */


/* header files for imported files */
#include "audioenginebaseapo.h"
#include "endpointvolume.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_audioengineextensionapo_0000_0000 */
/* [local] */ 

#include <winapifamily.h>
#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
typedef /* [v1_enum] */ 
enum AUDIO_SYSTEMEFFECT_STATE
    {
        AUDIO_SYSTEMEFFECT_STATE_OFF	= 0,
        AUDIO_SYSTEMEFFECT_STATE_ON	= ( AUDIO_SYSTEMEFFECT_STATE_OFF + 1 ) 
    } 	AUDIO_SYSTEMEFFECT_STATE;

typedef struct AUDIO_SYSTEMEFFECT
    {
    GUID id;
    BOOL canSetState;
    AUDIO_SYSTEMEFFECT_STATE state;
    } 	AUDIO_SYSTEMEFFECT;



extern RPC_IF_HANDLE __MIDL_itf_audioengineextensionapo_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_audioengineextensionapo_0000_0000_v0_0_s_ifspec;

#ifndef __IAudioSystemEffects3_INTERFACE_DEFINED__
#define __IAudioSystemEffects3_INTERFACE_DEFINED__

/* interface IAudioSystemEffects3 */
/* [uuid][object][local] */ 


EXTERN_C const IID IID_IAudioSystemEffects3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C58B31CD-FC6A-4255-BC1F-AD29BB0A4A17")
    IAudioSystemEffects3 : public IAudioSystemEffects2
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetControllableSystemEffectsList( 
            /* [annotation][size_is][size_is][out] */ 
            _Outptr_result_buffer_maybenull_(*numEffects)  AUDIO_SYSTEMEFFECT **effects,
            /* [annotation][out] */ 
            _Out_  UINT *numEffects,
            /* [annotation][in] */ 
            _In_opt_  HANDLE event) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetAudioSystemEffectState( 
            /* [annotation][in] */ 
            _In_  GUID effectId,
            /* [annotation][in] */ 
            _In_  AUDIO_SYSTEMEFFECT_STATE state) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAudioSystemEffects3Vtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAudioSystemEffects3 * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAudioSystemEffects3 * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAudioSystemEffects3 * This);
        
        DECLSPEC_XFGVIRT(IAudioSystemEffects2, GetEffectsList)
        HRESULT ( STDMETHODCALLTYPE *GetEffectsList )( 
            IAudioSystemEffects3 * This,
            /* [annotation][out] */ 
            _Outptr_result_buffer_maybenull_(*pcEffects)  LPGUID *ppEffectsIds,
            /* [annotation][out] */ 
            _Out_  UINT *pcEffects,
            /* [annotation][in] */ 
            _In_  HANDLE Event);
        
        DECLSPEC_XFGVIRT(IAudioSystemEffects3, GetControllableSystemEffectsList)
        HRESULT ( STDMETHODCALLTYPE *GetControllableSystemEffectsList )( 
            IAudioSystemEffects3 * This,
            /* [annotation][size_is][size_is][out] */ 
            _Outptr_result_buffer_maybenull_(*numEffects)  AUDIO_SYSTEMEFFECT **effects,
            /* [annotation][out] */ 
            _Out_  UINT *numEffects,
            /* [annotation][in] */ 
            _In_opt_  HANDLE event);
        
        DECLSPEC_XFGVIRT(IAudioSystemEffects3, SetAudioSystemEffectState)
        HRESULT ( STDMETHODCALLTYPE *SetAudioSystemEffectState )( 
            IAudioSystemEffects3 * This,
            /* [annotation][in] */ 
            _In_  GUID effectId,
            /* [annotation][in] */ 
            _In_  AUDIO_SYSTEMEFFECT_STATE state);
        
        END_INTERFACE
    } IAudioSystemEffects3Vtbl;

    interface IAudioSystemEffects3
    {
        CONST_VTBL struct IAudioSystemEffects3Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAudioSystemEffects3_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAudioSystemEffects3_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAudioSystemEffects3_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 



#define IAudioSystemEffects3_GetEffectsList(This,ppEffectsIds,pcEffects,Event)	\
    ( (This)->lpVtbl -> GetEffectsList(This,ppEffectsIds,pcEffects,Event) ) 


#define IAudioSystemEffects3_GetControllableSystemEffectsList(This,effects,numEffects,event)	\
    ( (This)->lpVtbl -> GetControllableSystemEffectsList(This,effects,numEffects,event) ) 

#define IAudioSystemEffects3_SetAudioSystemEffectState(This,effectId,state)	\
    ( (This)->lpVtbl -> SetAudioSystemEffectState(This,effectId,state) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAudioSystemEffects3_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_audioengineextensionapo_0000_0001 */
/* [local] */ 

typedef struct APOInitSystemEffects3
    {
    APOInitBaseStruct APOInit;
    IPropertyStore *pAPOEndpointProperties;
    IServiceProvider *pServiceProvider;
    IMMDeviceCollection *pDeviceCollection;
    UINT nSoftwareIoDeviceInCollection;
    UINT nSoftwareIoConnectorIndex;
    GUID AudioProcessingMode;
    BOOL InitializeForDiscoveryOnly;
    } 	APOInitSystemEffects3;



extern RPC_IF_HANDLE __MIDL_itf_audioengineextensionapo_0000_0001_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_audioengineextensionapo_0000_0001_v0_0_s_ifspec;

#ifndef __IAudioProcessingObjectRTQueueService_INTERFACE_DEFINED__
#define __IAudioProcessingObjectRTQueueService_INTERFACE_DEFINED__

/* interface IAudioProcessingObjectRTQueueService */
/* [local][uuid][object] */ 


EXTERN_C const IID IID_IAudioProcessingObjectRTQueueService;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("ACD65E2F-955B-4B57-B9BF-AC297BB752C9")
    IAudioProcessingObjectRTQueueService : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetRealTimeWorkQueue( 
            /* [annotation][out] */ 
            _Out_  DWORD *workQueueId) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAudioProcessingObjectRTQueueServiceVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAudioProcessingObjectRTQueueService * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAudioProcessingObjectRTQueueService * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAudioProcessingObjectRTQueueService * This);
        
        DECLSPEC_XFGVIRT(IAudioProcessingObjectRTQueueService, GetRealTimeWorkQueue)
        HRESULT ( STDMETHODCALLTYPE *GetRealTimeWorkQueue )( 
            IAudioProcessingObjectRTQueueService * This,
            /* [annotation][out] */ 
            _Out_  DWORD *workQueueId);
        
        END_INTERFACE
    } IAudioProcessingObjectRTQueueServiceVtbl;

    interface IAudioProcessingObjectRTQueueService
    {
        CONST_VTBL struct IAudioProcessingObjectRTQueueServiceVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAudioProcessingObjectRTQueueService_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAudioProcessingObjectRTQueueService_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAudioProcessingObjectRTQueueService_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAudioProcessingObjectRTQueueService_GetRealTimeWorkQueue(This,workQueueId)	\
    ( (This)->lpVtbl -> GetRealTimeWorkQueue(This,workQueueId) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAudioProcessingObjectRTQueueService_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_audioengineextensionapo_0000_0002 */
/* [local] */ 

DEFINE_GUID(SID_AudioProcessingObjectRTQueue, 0x458c1a1f, 0x6899, 0x4c12, 0x99, 0xac, 0xe2, 0xe6, 0xac, 0x25, 0x31, 0x4);
typedef 
enum APO_LOG_LEVEL
    {
        APO_LOG_LEVEL_ALWAYS	= 0,
        APO_LOG_LEVEL_CRITICAL	= 1,
        APO_LOG_LEVEL_ERROR	= 2,
        APO_LOG_LEVEL_WARNING	= 3,
        APO_LOG_LEVEL_INFO	= 4,
        APO_LOG_LEVEL_VERBOSE	= 5
    } 	APO_LOG_LEVEL;



extern RPC_IF_HANDLE __MIDL_itf_audioengineextensionapo_0000_0002_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_audioengineextensionapo_0000_0002_v0_0_s_ifspec;

#ifndef __IAudioProcessingObjectLoggingService_INTERFACE_DEFINED__
#define __IAudioProcessingObjectLoggingService_INTERFACE_DEFINED__

/* interface IAudioProcessingObjectLoggingService */
/* [local][uuid][object] */ 


EXTERN_C const IID IID_IAudioProcessingObjectLoggingService;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("698f0107-1745-4708-95a5-d84478a62a65")
    IAudioProcessingObjectLoggingService : public IUnknown
    {
    public:
        virtual void STDMETHODCALLTYPE ApoLog( 
            /* [in] */ APO_LOG_LEVEL level,
            /* [annotation][in] */ 
            _In_  LPCWSTR format,
            ...) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAudioProcessingObjectLoggingServiceVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAudioProcessingObjectLoggingService * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAudioProcessingObjectLoggingService * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAudioProcessingObjectLoggingService * This);
        
        DECLSPEC_XFGVIRT(IAudioProcessingObjectLoggingService, ApoLog)
        void ( STDMETHODCALLTYPE *ApoLog )( 
            IAudioProcessingObjectLoggingService * This,
            /* [in] */ APO_LOG_LEVEL level,
            /* [annotation][in] */ 
            _In_  LPCWSTR format,
            ...);
        
        END_INTERFACE
    } IAudioProcessingObjectLoggingServiceVtbl;

    interface IAudioProcessingObjectLoggingService
    {
        CONST_VTBL struct IAudioProcessingObjectLoggingServiceVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAudioProcessingObjectLoggingService_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAudioProcessingObjectLoggingService_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAudioProcessingObjectLoggingService_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAudioProcessingObjectLoggingService_ApoLog(This,level,format,...)	\
    ( (This)->lpVtbl -> ApoLog(This,level,format,...) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAudioProcessingObjectLoggingService_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_audioengineextensionapo_0000_0003 */
/* [local] */ 

DEFINE_GUID(SID_AudioProcessingObjectLoggingService, 0x8b8008af, 0x9f9, 0x456e, 0xa1, 0x73, 0xbd, 0xb5, 0x84, 0x99, 0xbc, 0xe7);
typedef 
enum APO_NOTIFICATION_TYPE
    {
        APO_NOTIFICATION_TYPE_NONE	= 0,
        APO_NOTIFICATION_TYPE_ENDPOINT_VOLUME	= 1,
        APO_NOTIFICATION_TYPE_ENDPOINT_PROPERTY_CHANGE	= 2,
        APO_NOTIFICATION_TYPE_SYSTEM_EFFECTS_PROPERTY_CHANGE	= 3
    } 	APO_NOTIFICATION_TYPE;

typedef struct AUDIO_ENDPOINT_VOLUME_CHANGE_NOTIFICATION
    {
    IMMDevice *endpoint;
    PAUDIO_VOLUME_NOTIFICATION_DATA volume;
    } 	AUDIO_ENDPOINT_VOLUME_CHANGE_NOTIFICATION;

typedef struct AUDIO_ENDPOINT_PROPERTY_CHANGE_NOTIFICATION
    {
    IMMDevice *endpoint;
    IPropertyStore *propertyStore;
    PROPERTYKEY propertyKey;
    } 	AUDIO_ENDPOINT_PROPERTY_CHANGE_NOTIFICATION;

typedef struct AUDIO_SYSTEMEFFECTS_PROPERTY_CHANGE_NOTIFICATION
    {
    IMMDevice *endpoint;
    GUID propertyStoreContext;
    AUDIO_SYSTEMEFFECTS_PROPERTYSTORE_TYPE propertyStoreType;
    IPropertyStore *propertyStore;
    PROPERTYKEY propertyKey;
    } 	AUDIO_SYSTEMEFFECTS_PROPERTY_CHANGE_NOTIFICATION;

typedef struct APO_NOTIFICATION
    {
    APO_NOTIFICATION_TYPE type;
    union 
        {
        AUDIO_ENDPOINT_VOLUME_CHANGE_NOTIFICATION audioEndpointVolumeChange;
        AUDIO_ENDPOINT_PROPERTY_CHANGE_NOTIFICATION audioEndpointPropertyChange;
        AUDIO_SYSTEMEFFECTS_PROPERTY_CHANGE_NOTIFICATION audioSystemEffectsPropertyChange;
        } 	DUMMYUNIONNAME;
    } 	APO_NOTIFICATION;

typedef struct AUDIO_ENDPOINT_VOLUME_APO_NOTIFICATION_DESCRIPTOR
    {
    IMMDevice *device;
    } 	AUDIO_ENDPOINT_VOLUME_APO_NOTIFICATION_DESCRIPTOR;

typedef struct AUDIO_ENDPOINT_PROPERTY_CHANGE_APO_NOTIFICATION_DESCRIPTOR
    {
    IMMDevice *device;
    } 	AUDIO_ENDPOINT_PROPERTY_CHANGE_APO_NOTIFICATION_DESCRIPTOR;

typedef struct AUDIO_SYSTEMEFFECTS_PROPERTY_CHANGE_APO_NOTIFICATION_DESCRIPTOR
    {
    IMMDevice *device;
    GUID propertyStoreContext;
    } 	AUDIO_SYSTEMEFFECTS_PROPERTY_CHANGE_APO_NOTIFICATION_DESCRIPTOR;

typedef struct APO_NOTIFICATION_DESCRIPTOR
    {
    APO_NOTIFICATION_TYPE type;
    union 
        {
        AUDIO_ENDPOINT_VOLUME_APO_NOTIFICATION_DESCRIPTOR audioEndpointVolume;
        AUDIO_ENDPOINT_PROPERTY_CHANGE_APO_NOTIFICATION_DESCRIPTOR audioEndpointPropertyChange;
        AUDIO_SYSTEMEFFECTS_PROPERTY_CHANGE_APO_NOTIFICATION_DESCRIPTOR audioSystemEffectsPropertyChange;
        } 	DUMMYUNIONNAME;
    } 	APO_NOTIFICATION_DESCRIPTOR;



extern RPC_IF_HANDLE __MIDL_itf_audioengineextensionapo_0000_0003_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_audioengineextensionapo_0000_0003_v0_0_s_ifspec;

#ifndef __IAudioProcessingObjectNotifications_INTERFACE_DEFINED__
#define __IAudioProcessingObjectNotifications_INTERFACE_DEFINED__

/* interface IAudioProcessingObjectNotifications */
/* [local][uuid][object] */ 


EXTERN_C const IID IID_IAudioProcessingObjectNotifications;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("56B0C76F-02FD-4B21-A52E-9F8219FC86E4")
    IAudioProcessingObjectNotifications : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetApoNotificationRegistrationInfo( 
            /* [annotation][out] */ 
            _Out_writes_(*count)  APO_NOTIFICATION_DESCRIPTOR **apoNotifications,
            /* [annotation][out] */ 
            _Out_  DWORD *count) = 0;
        
        virtual void STDMETHODCALLTYPE HandleNotification( 
            /* [annotation][in] */ 
            _In_  APO_NOTIFICATION *apoNotification) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAudioProcessingObjectNotificationsVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAudioProcessingObjectNotifications * This,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAudioProcessingObjectNotifications * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAudioProcessingObjectNotifications * This);
        
        DECLSPEC_XFGVIRT(IAudioProcessingObjectNotifications, GetApoNotificationRegistrationInfo)
        HRESULT ( STDMETHODCALLTYPE *GetApoNotificationRegistrationInfo )( 
            IAudioProcessingObjectNotifications * This,
            /* [annotation][out] */ 
            _Out_writes_(*count)  APO_NOTIFICATION_DESCRIPTOR **apoNotifications,
            /* [annotation][out] */ 
            _Out_  DWORD *count);
        
        DECLSPEC_XFGVIRT(IAudioProcessingObjectNotifications, HandleNotification)
        void ( STDMETHODCALLTYPE *HandleNotification )( 
            IAudioProcessingObjectNotifications * This,
            /* [annotation][in] */ 
            _In_  APO_NOTIFICATION *apoNotification);
        
        END_INTERFACE
    } IAudioProcessingObjectNotificationsVtbl;

    interface IAudioProcessingObjectNotifications
    {
        CONST_VTBL struct IAudioProcessingObjectNotificationsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAudioProcessingObjectNotifications_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAudioProcessingObjectNotifications_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAudioProcessingObjectNotifications_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAudioProcessingObjectNotifications_GetApoNotificationRegistrationInfo(This,apoNotifications,count)	\
    ( (This)->lpVtbl -> GetApoNotificationRegistrationInfo(This,apoNotifications,count) ) 

#define IAudioProcessingObjectNotifications_HandleNotification(This,apoNotification)	\
    ( (This)->lpVtbl -> HandleNotification(This,apoNotification) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAudioProcessingObjectNotifications_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_audioengineextensionapo_0000_0004 */
/* [local] */ 

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion


extern RPC_IF_HANDLE __MIDL_itf_audioengineextensionapo_0000_0004_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_audioengineextensionapo_0000_0004_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


