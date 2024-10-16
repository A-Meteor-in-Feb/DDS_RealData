

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from data.idl
using RTI Code Generator (rtiddsgen) version 4.3.0.
The rtiddsgen tool is part of the RTI Connext DDS distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the Code Generator User's Manual.
*/

#ifndef dataPlugin_1787940864_h
#define dataPlugin_1787940864_h

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

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif /* dataPlugin_1787940864_h */

