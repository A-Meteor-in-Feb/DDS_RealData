

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from data.idl
using RTI Code Generator (rtiddsgen) version 4.3.0.
The rtiddsgen tool is part of the RTI Connext DDS distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the Code Generator User's Manual.
*/

#ifndef dataPlugin_1787947667_h
#define dataPlugin_1787947667_h

#include "data.hpp"

struct RTICdrStream;

#ifndef pres_typePlugin_h
#include "pres/pres_typePlugin.h"
#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

#define tele_statusPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

#define tele_statusPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define tele_statusPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

#define tele_statusPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define tele_statusPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern tele_status*
tele_statusPluginSupport_create_data_w_params(
    const struct DDS_TypeAllocationParams_t * alloc_params);

NDDSUSERDllExport extern tele_status*
tele_statusPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern tele_status*
tele_statusPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
tele_statusPluginSupport_copy_data(
    tele_status *out,
    const tele_status *in);

NDDSUSERDllExport extern void 
tele_statusPluginSupport_destroy_data_w_params(
    tele_status *sample,
    const struct DDS_TypeDeallocationParams_t * dealloc_params);

NDDSUSERDllExport extern void 
tele_statusPluginSupport_destroy_data_ex(
    tele_status *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
tele_statusPluginSupport_destroy_data(
    tele_status *sample);

NDDSUSERDllExport extern void 
tele_statusPluginSupport_print_data(
    const tele_status *sample,
    const char *desc,
    unsigned int indent);

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
tele_statusPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
tele_statusPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);

NDDSUSERDllExport extern PRESTypePluginEndpointData 
tele_statusPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
tele_statusPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern void    
tele_statusPlugin_return_sample(
    PRESTypePluginEndpointData endpoint_data,
    tele_status *sample,
    void *handle);    

NDDSUSERDllExport extern RTIBool 
tele_statusPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    tele_status *out,
    const tele_status *in);

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool
tele_statusPlugin_serialize_to_cdr_buffer(
    char * buffer,
    unsigned int * length,
    const tele_status *sample,
    ::dds::core::policy::DataRepresentationId representation
    = ::dds::core::policy::DataRepresentation::xcdr()); 

NDDSUSERDllExport extern RTIBool 
tele_statusPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    tele_status **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *cdrStream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
tele_statusPlugin_deserialize_from_cdr_buffer(
    tele_status *sample,
    const char * buffer,
    unsigned int length);    

NDDSUSERDllExport extern unsigned int 
tele_statusPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */
NDDSUSERDllExport extern PRESTypePluginKeyKind 
tele_statusPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
tele_statusPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
tele_statusPlugin_get_serialized_key_max_size_for_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
tele_statusPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    tele_status ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *cdrStream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
tele_statusPlugin_new(void);

NDDSUSERDllExport extern void
tele_statusPlugin_delete(struct PRESTypePlugin *);

#define vehicle_statusPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

#define vehicle_statusPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define vehicle_statusPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

#define vehicle_statusPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define vehicle_statusPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern vehicle_status*
vehicle_statusPluginSupport_create_data_w_params(
    const struct DDS_TypeAllocationParams_t * alloc_params);

NDDSUSERDllExport extern vehicle_status*
vehicle_statusPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern vehicle_status*
vehicle_statusPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
vehicle_statusPluginSupport_copy_data(
    vehicle_status *out,
    const vehicle_status *in);

NDDSUSERDllExport extern void 
vehicle_statusPluginSupport_destroy_data_w_params(
    vehicle_status *sample,
    const struct DDS_TypeDeallocationParams_t * dealloc_params);

NDDSUSERDllExport extern void 
vehicle_statusPluginSupport_destroy_data_ex(
    vehicle_status *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
vehicle_statusPluginSupport_destroy_data(
    vehicle_status *sample);

NDDSUSERDllExport extern void 
vehicle_statusPluginSupport_print_data(
    const vehicle_status *sample,
    const char *desc,
    unsigned int indent);

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
vehicle_statusPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
vehicle_statusPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);

NDDSUSERDllExport extern PRESTypePluginEndpointData 
vehicle_statusPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
vehicle_statusPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern void    
vehicle_statusPlugin_return_sample(
    PRESTypePluginEndpointData endpoint_data,
    vehicle_status *sample,
    void *handle);    

NDDSUSERDllExport extern RTIBool 
vehicle_statusPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    vehicle_status *out,
    const vehicle_status *in);

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool
vehicle_statusPlugin_serialize_to_cdr_buffer(
    char * buffer,
    unsigned int * length,
    const vehicle_status *sample,
    ::dds::core::policy::DataRepresentationId representation
    = ::dds::core::policy::DataRepresentation::xcdr()); 

NDDSUSERDllExport extern RTIBool 
vehicle_statusPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    vehicle_status **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *cdrStream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
vehicle_statusPlugin_deserialize_from_cdr_buffer(
    vehicle_status *sample,
    const char * buffer,
    unsigned int length);    

NDDSUSERDllExport extern unsigned int 
vehicle_statusPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */
NDDSUSERDllExport extern PRESTypePluginKeyKind 
vehicle_statusPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
vehicle_statusPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
vehicle_statusPlugin_get_serialized_key_max_size_for_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
vehicle_statusPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    vehicle_status ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *cdrStream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
vehicle_statusPlugin_new(void);

NDDSUSERDllExport extern void
vehicle_statusPlugin_delete(struct PRESTypePlugin *);

#define connection_msgPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

#define connection_msgPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define connection_msgPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

#define connection_msgPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define connection_msgPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern connection_msg*
connection_msgPluginSupport_create_data_w_params(
    const struct DDS_TypeAllocationParams_t * alloc_params);

NDDSUSERDllExport extern connection_msg*
connection_msgPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern connection_msg*
connection_msgPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
connection_msgPluginSupport_copy_data(
    connection_msg *out,
    const connection_msg *in);

NDDSUSERDllExport extern void 
connection_msgPluginSupport_destroy_data_w_params(
    connection_msg *sample,
    const struct DDS_TypeDeallocationParams_t * dealloc_params);

NDDSUSERDllExport extern void 
connection_msgPluginSupport_destroy_data_ex(
    connection_msg *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
connection_msgPluginSupport_destroy_data(
    connection_msg *sample);

NDDSUSERDllExport extern void 
connection_msgPluginSupport_print_data(
    const connection_msg *sample,
    const char *desc,
    unsigned int indent);

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
connection_msgPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
connection_msgPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);

NDDSUSERDllExport extern PRESTypePluginEndpointData 
connection_msgPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
connection_msgPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern void    
connection_msgPlugin_return_sample(
    PRESTypePluginEndpointData endpoint_data,
    connection_msg *sample,
    void *handle);    

NDDSUSERDllExport extern RTIBool 
connection_msgPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    connection_msg *out,
    const connection_msg *in);

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool
connection_msgPlugin_serialize_to_cdr_buffer(
    char * buffer,
    unsigned int * length,
    const connection_msg *sample,
    ::dds::core::policy::DataRepresentationId representation
    = ::dds::core::policy::DataRepresentation::xcdr()); 

NDDSUSERDllExport extern RTIBool 
connection_msgPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    connection_msg **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *cdrStream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
connection_msgPlugin_deserialize_from_cdr_buffer(
    connection_msg *sample,
    const char * buffer,
    unsigned int length);    

NDDSUSERDllExport extern unsigned int 
connection_msgPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */
NDDSUSERDllExport extern PRESTypePluginKeyKind 
connection_msgPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
connection_msgPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
connection_msgPlugin_get_serialized_key_max_size_for_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
connection_msgPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    connection_msg ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *cdrStream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
connection_msgPlugin_new(void);

NDDSUSERDllExport extern void
connection_msgPlugin_delete(struct PRESTypePlugin *);

#define disconnection_msgPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

#define disconnection_msgPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define disconnection_msgPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

#define disconnection_msgPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define disconnection_msgPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern disconnection_msg*
disconnection_msgPluginSupport_create_data_w_params(
    const struct DDS_TypeAllocationParams_t * alloc_params);

NDDSUSERDllExport extern disconnection_msg*
disconnection_msgPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern disconnection_msg*
disconnection_msgPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
disconnection_msgPluginSupport_copy_data(
    disconnection_msg *out,
    const disconnection_msg *in);

NDDSUSERDllExport extern void 
disconnection_msgPluginSupport_destroy_data_w_params(
    disconnection_msg *sample,
    const struct DDS_TypeDeallocationParams_t * dealloc_params);

NDDSUSERDllExport extern void 
disconnection_msgPluginSupport_destroy_data_ex(
    disconnection_msg *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
disconnection_msgPluginSupport_destroy_data(
    disconnection_msg *sample);

NDDSUSERDllExport extern void 
disconnection_msgPluginSupport_print_data(
    const disconnection_msg *sample,
    const char *desc,
    unsigned int indent);

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
disconnection_msgPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
disconnection_msgPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);

NDDSUSERDllExport extern PRESTypePluginEndpointData 
disconnection_msgPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
disconnection_msgPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern void    
disconnection_msgPlugin_return_sample(
    PRESTypePluginEndpointData endpoint_data,
    disconnection_msg *sample,
    void *handle);    

NDDSUSERDllExport extern RTIBool 
disconnection_msgPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    disconnection_msg *out,
    const disconnection_msg *in);

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool
disconnection_msgPlugin_serialize_to_cdr_buffer(
    char * buffer,
    unsigned int * length,
    const disconnection_msg *sample,
    ::dds::core::policy::DataRepresentationId representation
    = ::dds::core::policy::DataRepresentation::xcdr()); 

NDDSUSERDllExport extern RTIBool 
disconnection_msgPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    disconnection_msg **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *cdrStream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
disconnection_msgPlugin_deserialize_from_cdr_buffer(
    disconnection_msg *sample,
    const char * buffer,
    unsigned int length);    

NDDSUSERDllExport extern unsigned int 
disconnection_msgPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */
NDDSUSERDllExport extern PRESTypePluginKeyKind 
disconnection_msgPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
disconnection_msgPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
disconnection_msgPlugin_get_serialized_key_max_size_for_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
disconnection_msgPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    disconnection_msg ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *cdrStream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
disconnection_msgPlugin_new(void);

NDDSUSERDllExport extern void
disconnection_msgPlugin_delete(struct PRESTypePlugin *);

#define partition_namePlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

#define partition_namePlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define partition_namePlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

#define partition_namePlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define partition_namePlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern partition_name*
partition_namePluginSupport_create_data_w_params(
    const struct DDS_TypeAllocationParams_t * alloc_params);

NDDSUSERDllExport extern partition_name*
partition_namePluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern partition_name*
partition_namePluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
partition_namePluginSupport_copy_data(
    partition_name *out,
    const partition_name *in);

NDDSUSERDllExport extern void 
partition_namePluginSupport_destroy_data_w_params(
    partition_name *sample,
    const struct DDS_TypeDeallocationParams_t * dealloc_params);

NDDSUSERDllExport extern void 
partition_namePluginSupport_destroy_data_ex(
    partition_name *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
partition_namePluginSupport_destroy_data(
    partition_name *sample);

NDDSUSERDllExport extern void 
partition_namePluginSupport_print_data(
    const partition_name *sample,
    const char *desc,
    unsigned int indent);

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
partition_namePlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
partition_namePlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);

NDDSUSERDllExport extern PRESTypePluginEndpointData 
partition_namePlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
partition_namePlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern void    
partition_namePlugin_return_sample(
    PRESTypePluginEndpointData endpoint_data,
    partition_name *sample,
    void *handle);    

NDDSUSERDllExport extern RTIBool 
partition_namePlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    partition_name *out,
    const partition_name *in);

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool
partition_namePlugin_serialize_to_cdr_buffer(
    char * buffer,
    unsigned int * length,
    const partition_name *sample,
    ::dds::core::policy::DataRepresentationId representation
    = ::dds::core::policy::DataRepresentation::xcdr()); 

NDDSUSERDllExport extern RTIBool 
partition_namePlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    partition_name **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *cdrStream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
partition_namePlugin_deserialize_from_cdr_buffer(
    partition_name *sample,
    const char * buffer,
    unsigned int length);    

NDDSUSERDllExport extern unsigned int 
partition_namePlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */
NDDSUSERDllExport extern PRESTypePluginKeyKind 
partition_namePlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
partition_namePlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
partition_namePlugin_get_serialized_key_max_size_for_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
partition_namePlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    partition_name ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *cdrStream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
partition_namePlugin_new(void);

NDDSUSERDllExport extern void
partition_namePlugin_delete(struct PRESTypePlugin *);

#define steeringWheel_dataPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

#define steeringWheel_dataPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define steeringWheel_dataPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

#define steeringWheel_dataPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define steeringWheel_dataPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern steeringWheel_data*
steeringWheel_dataPluginSupport_create_data_w_params(
    const struct DDS_TypeAllocationParams_t * alloc_params);

NDDSUSERDllExport extern steeringWheel_data*
steeringWheel_dataPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern steeringWheel_data*
steeringWheel_dataPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
steeringWheel_dataPluginSupport_copy_data(
    steeringWheel_data *out,
    const steeringWheel_data *in);

NDDSUSERDllExport extern void 
steeringWheel_dataPluginSupport_destroy_data_w_params(
    steeringWheel_data *sample,
    const struct DDS_TypeDeallocationParams_t * dealloc_params);

NDDSUSERDllExport extern void 
steeringWheel_dataPluginSupport_destroy_data_ex(
    steeringWheel_data *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
steeringWheel_dataPluginSupport_destroy_data(
    steeringWheel_data *sample);

NDDSUSERDllExport extern void 
steeringWheel_dataPluginSupport_print_data(
    const steeringWheel_data *sample,
    const char *desc,
    unsigned int indent);

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
steeringWheel_dataPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
steeringWheel_dataPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);

NDDSUSERDllExport extern PRESTypePluginEndpointData 
steeringWheel_dataPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
steeringWheel_dataPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern void    
steeringWheel_dataPlugin_return_sample(
    PRESTypePluginEndpointData endpoint_data,
    steeringWheel_data *sample,
    void *handle);    

NDDSUSERDllExport extern RTIBool 
steeringWheel_dataPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    steeringWheel_data *out,
    const steeringWheel_data *in);

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool
steeringWheel_dataPlugin_serialize_to_cdr_buffer(
    char * buffer,
    unsigned int * length,
    const steeringWheel_data *sample,
    ::dds::core::policy::DataRepresentationId representation
    = ::dds::core::policy::DataRepresentation::xcdr()); 

NDDSUSERDllExport extern RTIBool 
steeringWheel_dataPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    steeringWheel_data **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *cdrStream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
steeringWheel_dataPlugin_deserialize_from_cdr_buffer(
    steeringWheel_data *sample,
    const char * buffer,
    unsigned int length);    

NDDSUSERDllExport extern unsigned int 
steeringWheel_dataPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */
NDDSUSERDllExport extern PRESTypePluginKeyKind 
steeringWheel_dataPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
steeringWheel_dataPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
steeringWheel_dataPlugin_get_serialized_key_max_size_for_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
steeringWheel_dataPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    steeringWheel_data ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *cdrStream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
steeringWheel_dataPlugin_new(void);

NDDSUSERDllExport extern void
steeringWheel_dataPlugin_delete(struct PRESTypePlugin *);

#define joyStick_dataPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

#define joyStick_dataPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define joyStick_dataPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

#define joyStick_dataPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define joyStick_dataPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern joyStick_data*
joyStick_dataPluginSupport_create_data_w_params(
    const struct DDS_TypeAllocationParams_t * alloc_params);

NDDSUSERDllExport extern joyStick_data*
joyStick_dataPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern joyStick_data*
joyStick_dataPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
joyStick_dataPluginSupport_copy_data(
    joyStick_data *out,
    const joyStick_data *in);

NDDSUSERDllExport extern void 
joyStick_dataPluginSupport_destroy_data_w_params(
    joyStick_data *sample,
    const struct DDS_TypeDeallocationParams_t * dealloc_params);

NDDSUSERDllExport extern void 
joyStick_dataPluginSupport_destroy_data_ex(
    joyStick_data *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
joyStick_dataPluginSupport_destroy_data(
    joyStick_data *sample);

NDDSUSERDllExport extern void 
joyStick_dataPluginSupport_print_data(
    const joyStick_data *sample,
    const char *desc,
    unsigned int indent);

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
joyStick_dataPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
joyStick_dataPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);

NDDSUSERDllExport extern PRESTypePluginEndpointData 
joyStick_dataPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
joyStick_dataPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern void    
joyStick_dataPlugin_return_sample(
    PRESTypePluginEndpointData endpoint_data,
    joyStick_data *sample,
    void *handle);    

NDDSUSERDllExport extern RTIBool 
joyStick_dataPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    joyStick_data *out,
    const joyStick_data *in);

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool
joyStick_dataPlugin_serialize_to_cdr_buffer(
    char * buffer,
    unsigned int * length,
    const joyStick_data *sample,
    ::dds::core::policy::DataRepresentationId representation
    = ::dds::core::policy::DataRepresentation::xcdr()); 

NDDSUSERDllExport extern RTIBool 
joyStick_dataPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    joyStick_data **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *cdrStream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
joyStick_dataPlugin_deserialize_from_cdr_buffer(
    joyStick_data *sample,
    const char * buffer,
    unsigned int length);    

NDDSUSERDllExport extern unsigned int 
joyStick_dataPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */
NDDSUSERDllExport extern PRESTypePluginKeyKind 
joyStick_dataPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
joyStick_dataPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
joyStick_dataPlugin_get_serialized_key_max_size_for_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
joyStick_dataPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    joyStick_data ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *cdrStream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
joyStick_dataPlugin_new(void);

NDDSUSERDllExport extern void
joyStick_dataPlugin_delete(struct PRESTypePlugin *);

#define streamdeck_buttons_dataPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

#define streamdeck_buttons_dataPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define streamdeck_buttons_dataPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

#define streamdeck_buttons_dataPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define streamdeck_buttons_dataPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern streamdeck_buttons_data*
streamdeck_buttons_dataPluginSupport_create_data_w_params(
    const struct DDS_TypeAllocationParams_t * alloc_params);

NDDSUSERDllExport extern streamdeck_buttons_data*
streamdeck_buttons_dataPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern streamdeck_buttons_data*
streamdeck_buttons_dataPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
streamdeck_buttons_dataPluginSupport_copy_data(
    streamdeck_buttons_data *out,
    const streamdeck_buttons_data *in);

NDDSUSERDllExport extern void 
streamdeck_buttons_dataPluginSupport_destroy_data_w_params(
    streamdeck_buttons_data *sample,
    const struct DDS_TypeDeallocationParams_t * dealloc_params);

NDDSUSERDllExport extern void 
streamdeck_buttons_dataPluginSupport_destroy_data_ex(
    streamdeck_buttons_data *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
streamdeck_buttons_dataPluginSupport_destroy_data(
    streamdeck_buttons_data *sample);

NDDSUSERDllExport extern void 
streamdeck_buttons_dataPluginSupport_print_data(
    const streamdeck_buttons_data *sample,
    const char *desc,
    unsigned int indent);

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
streamdeck_buttons_dataPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
streamdeck_buttons_dataPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);

NDDSUSERDllExport extern PRESTypePluginEndpointData 
streamdeck_buttons_dataPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
streamdeck_buttons_dataPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern void    
streamdeck_buttons_dataPlugin_return_sample(
    PRESTypePluginEndpointData endpoint_data,
    streamdeck_buttons_data *sample,
    void *handle);    

NDDSUSERDllExport extern RTIBool 
streamdeck_buttons_dataPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    streamdeck_buttons_data *out,
    const streamdeck_buttons_data *in);

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool
streamdeck_buttons_dataPlugin_serialize_to_cdr_buffer(
    char * buffer,
    unsigned int * length,
    const streamdeck_buttons_data *sample,
    ::dds::core::policy::DataRepresentationId representation
    = ::dds::core::policy::DataRepresentation::xcdr()); 

NDDSUSERDllExport extern RTIBool 
streamdeck_buttons_dataPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    streamdeck_buttons_data **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *cdrStream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
streamdeck_buttons_dataPlugin_deserialize_from_cdr_buffer(
    streamdeck_buttons_data *sample,
    const char * buffer,
    unsigned int length);    

NDDSUSERDllExport extern unsigned int 
streamdeck_buttons_dataPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */
NDDSUSERDllExport extern PRESTypePluginKeyKind 
streamdeck_buttons_dataPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
streamdeck_buttons_dataPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
streamdeck_buttons_dataPlugin_get_serialized_key_max_size_for_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
streamdeck_buttons_dataPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    streamdeck_buttons_data ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *cdrStream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
streamdeck_buttons_dataPlugin_new(void);

NDDSUSERDllExport extern void
streamdeck_buttons_dataPlugin_delete(struct PRESTypePlugin *);

#define statistic_dataPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

#define statistic_dataPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define statistic_dataPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

#define statistic_dataPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define statistic_dataPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern statistic_data*
statistic_dataPluginSupport_create_data_w_params(
    const struct DDS_TypeAllocationParams_t * alloc_params);

NDDSUSERDllExport extern statistic_data*
statistic_dataPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern statistic_data*
statistic_dataPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
statistic_dataPluginSupport_copy_data(
    statistic_data *out,
    const statistic_data *in);

NDDSUSERDllExport extern void 
statistic_dataPluginSupport_destroy_data_w_params(
    statistic_data *sample,
    const struct DDS_TypeDeallocationParams_t * dealloc_params);

NDDSUSERDllExport extern void 
statistic_dataPluginSupport_destroy_data_ex(
    statistic_data *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
statistic_dataPluginSupport_destroy_data(
    statistic_data *sample);

NDDSUSERDllExport extern void 
statistic_dataPluginSupport_print_data(
    const statistic_data *sample,
    const char *desc,
    unsigned int indent);

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
statistic_dataPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
statistic_dataPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);

NDDSUSERDllExport extern PRESTypePluginEndpointData 
statistic_dataPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
statistic_dataPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern void    
statistic_dataPlugin_return_sample(
    PRESTypePluginEndpointData endpoint_data,
    statistic_data *sample,
    void *handle);    

NDDSUSERDllExport extern RTIBool 
statistic_dataPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    statistic_data *out,
    const statistic_data *in);

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool
statistic_dataPlugin_serialize_to_cdr_buffer(
    char * buffer,
    unsigned int * length,
    const statistic_data *sample,
    ::dds::core::policy::DataRepresentationId representation
    = ::dds::core::policy::DataRepresentation::xcdr()); 

NDDSUSERDllExport extern RTIBool 
statistic_dataPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    statistic_data **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *cdrStream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
statistic_dataPlugin_deserialize_from_cdr_buffer(
    statistic_data *sample,
    const char * buffer,
    unsigned int length);    

NDDSUSERDllExport extern unsigned int 
statistic_dataPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */
NDDSUSERDllExport extern PRESTypePluginKeyKind 
statistic_dataPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
statistic_dataPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
statistic_dataPlugin_get_serialized_key_max_size_for_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
statistic_dataPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    statistic_data ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *cdrStream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
statistic_dataPlugin_new(void);

NDDSUSERDllExport extern void
statistic_dataPlugin_delete(struct PRESTypePlugin *);

#define IMU_dataPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

#define IMU_dataPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define IMU_dataPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

#define IMU_dataPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define IMU_dataPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern IMU_data*
IMU_dataPluginSupport_create_data_w_params(
    const struct DDS_TypeAllocationParams_t * alloc_params);

NDDSUSERDllExport extern IMU_data*
IMU_dataPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern IMU_data*
IMU_dataPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
IMU_dataPluginSupport_copy_data(
    IMU_data *out,
    const IMU_data *in);

NDDSUSERDllExport extern void 
IMU_dataPluginSupport_destroy_data_w_params(
    IMU_data *sample,
    const struct DDS_TypeDeallocationParams_t * dealloc_params);

NDDSUSERDllExport extern void 
IMU_dataPluginSupport_destroy_data_ex(
    IMU_data *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
IMU_dataPluginSupport_destroy_data(
    IMU_data *sample);

NDDSUSERDllExport extern void 
IMU_dataPluginSupport_print_data(
    const IMU_data *sample,
    const char *desc,
    unsigned int indent);

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
IMU_dataPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
IMU_dataPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);

NDDSUSERDllExport extern PRESTypePluginEndpointData 
IMU_dataPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
IMU_dataPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern void    
IMU_dataPlugin_return_sample(
    PRESTypePluginEndpointData endpoint_data,
    IMU_data *sample,
    void *handle);    

NDDSUSERDllExport extern RTIBool 
IMU_dataPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    IMU_data *out,
    const IMU_data *in);

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool
IMU_dataPlugin_serialize_to_cdr_buffer(
    char * buffer,
    unsigned int * length,
    const IMU_data *sample,
    ::dds::core::policy::DataRepresentationId representation
    = ::dds::core::policy::DataRepresentation::xcdr()); 

NDDSUSERDllExport extern RTIBool 
IMU_dataPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    IMU_data **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *cdrStream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
IMU_dataPlugin_deserialize_from_cdr_buffer(
    IMU_data *sample,
    const char * buffer,
    unsigned int length);    

NDDSUSERDllExport extern unsigned int 
IMU_dataPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */
NDDSUSERDllExport extern PRESTypePluginKeyKind 
IMU_dataPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
IMU_dataPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
IMU_dataPlugin_get_serialized_key_max_size_for_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
IMU_dataPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    IMU_data ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *cdrStream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
IMU_dataPlugin_new(void);

NDDSUSERDllExport extern void
IMU_dataPlugin_delete(struct PRESTypePlugin *);

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif /* dataPlugin_1787947667_h */

