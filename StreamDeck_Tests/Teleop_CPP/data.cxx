

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from data.idl
using RTI Code Generator (rtiddsgen) version 4.3.0.
The rtiddsgen tool is part of the RTI Connext DDS distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the Code Generator User's Manual.
*/

#include <iosfwd>
#include <iomanip>
#include <cmath>
#include <limits>

#ifndef NDDS_STANDALONE_TYPE
#include "rti/topic/cdr/Serialization.hpp"
#include "dataPlugin.hpp"
#else
#include "rti/topic/cdr/SerializationHelpers.hpp"
#endif

#include "data.hpp"

#include <rti/util/ostream_operators.hpp>

// ---- streamdeck_buttons_data: 

streamdeck_buttons_data::streamdeck_buttons_data() :
    m_buttons_ (0)  {

}   

streamdeck_buttons_data::streamdeck_buttons_data (int16_t buttons_):
    m_buttons_(buttons_) {
}

void streamdeck_buttons_data::swap(streamdeck_buttons_data& other_)  noexcept 
{
    using std::swap;
    swap(m_buttons_, other_.m_buttons_);
}  

bool streamdeck_buttons_data::operator == (const streamdeck_buttons_data& other_) const {
    if (m_buttons_ != other_.m_buttons_) {
        return false;
    }
    return true;
}

bool streamdeck_buttons_data::operator != (const streamdeck_buttons_data& other_) const {
    return !this->operator ==(other_);
}

std::ostream& operator << (std::ostream& o,const streamdeck_buttons_data& sample)
{
    ::rti::util::StreamFlagSaver flag_saver (o);
    o <<"[";
    o << "buttons: " << sample.buttons ();
    o <<"]";
    return o;
}

// ---- statistic_data: 

statistic_data::statistic_data() :
    m_height_ (0.0) ,
    m_depth_ (0.0) ,
    m_auto_flag_ (0)  {

}   

statistic_data::statistic_data (double height_,double depth_,int16_t auto_flag_):
    m_height_(height_), 
    m_depth_(depth_), 
    m_auto_flag_(auto_flag_) {
}

void statistic_data::swap(statistic_data& other_)  noexcept 
{
    using std::swap;
    swap(m_height_, other_.m_height_);
    swap(m_depth_, other_.m_depth_);
    swap(m_auto_flag_, other_.m_auto_flag_);
}  

bool statistic_data::operator == (const statistic_data& other_) const {
    if (std::fabs(m_height_ - other_.m_height_) > std::numeric_limits< double>::epsilon()
    && !(std::fabs(m_height_ - other_.m_height_) < (std::numeric_limits< double>::min)())) {
        return false;
    }
    if (std::fabs(m_depth_ - other_.m_depth_) > std::numeric_limits< double>::epsilon()
    && !(std::fabs(m_depth_ - other_.m_depth_) < (std::numeric_limits< double>::min)())) {
        return false;
    }
    if (m_auto_flag_ != other_.m_auto_flag_) {
        return false;
    }
    return true;
}

bool statistic_data::operator != (const statistic_data& other_) const {
    return !this->operator ==(other_);
}

std::ostream& operator << (std::ostream& o,const statistic_data& sample)
{
    ::rti::util::StreamFlagSaver flag_saver (o);
    o <<"[";
    o << "height: " << std::setprecision(15) << sample.height ()<<", ";
    o << "depth: " << std::setprecision(15) << sample.depth ()<<", ";
    o << "auto_flag: " << sample.auto_flag ();
    o <<"]";
    return o;
}

#ifdef NDDS_STANDALONE_TYPE
namespace rti {
    namespace topic {
    }
}

#else
// --- Type traits: -------------------------------------------------

namespace rti { 
    namespace topic {

        template<>
        struct native_type_code< ::streamdeck_buttons_data > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member streamdeck_buttons_data_g_tc_members[1]=
                {

                    {
                        (char *)"buttons",/* Member name */
                        {
                            0,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode streamdeck_buttons_data_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"streamdeck_buttons_data", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        1, /* Number of members */
                        streamdeck_buttons_data_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for streamdeck_buttons_data*/

                if (is_initialized) {
                    return &streamdeck_buttons_data_g_tc;
                }

                is_initialized = RTI_TRUE;

                streamdeck_buttons_data_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                streamdeck_buttons_data_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_short;

                /* Initialize the values for member annotations. */
                streamdeck_buttons_data_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_SHORT;
                streamdeck_buttons_data_g_tc_members[0]._annotations._defaultValue._u.short_value = 0;
                streamdeck_buttons_data_g_tc_members[0]._annotations._minValue._d = RTI_XCDR_TK_SHORT;
                streamdeck_buttons_data_g_tc_members[0]._annotations._minValue._u.short_value = RTIXCdrShort_MIN;
                streamdeck_buttons_data_g_tc_members[0]._annotations._maxValue._d = RTI_XCDR_TK_SHORT;
                streamdeck_buttons_data_g_tc_members[0]._annotations._maxValue._u.short_value = RTIXCdrShort_MAX;

                streamdeck_buttons_data_g_tc._data._sampleAccessInfo = sample_access_info();
                streamdeck_buttons_data_g_tc._data._typePlugin = type_plugin_info();    

                return &streamdeck_buttons_data_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                ::streamdeck_buttons_data *sample;

                static RTIXCdrMemberAccessInfo streamdeck_buttons_data_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo streamdeck_buttons_data_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &streamdeck_buttons_data_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    ::streamdeck_buttons_data);
                if (sample == NULL) {
                    return NULL;
                }

                streamdeck_buttons_data_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->buttons() - (char *)sample);

                streamdeck_buttons_data_g_sampleAccessInfo.memberAccessInfos = 
                streamdeck_buttons_data_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(::streamdeck_buttons_data);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        streamdeck_buttons_data_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        streamdeck_buttons_data_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                streamdeck_buttons_data_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                streamdeck_buttons_data_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< ::streamdeck_buttons_data >;

                streamdeck_buttons_data_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &streamdeck_buttons_data_g_sampleAccessInfo;
            }
            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin streamdeck_buttons_data_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &streamdeck_buttons_data_g_typePlugin;
            }
        }; // native_type_code

        const ::dds::core::xtypes::StructType& dynamic_type< ::streamdeck_buttons_data >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< ::streamdeck_buttons_data >::get())));
        }

        template<>
        struct native_type_code< ::statistic_data > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member statistic_data_g_tc_members[3]=
                {

                    {
                        (char *)"height",/* Member name */
                        {
                            0,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"depth",/* Member name */
                        {
                            1,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"auto_flag",/* Member name */
                        {
                            2,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode statistic_data_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"statistic_data", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        3, /* Number of members */
                        statistic_data_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for statistic_data*/

                if (is_initialized) {
                    return &statistic_data_g_tc;
                }

                is_initialized = RTI_TRUE;

                statistic_data_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                statistic_data_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
                statistic_data_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
                statistic_data_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_short;

                /* Initialize the values for member annotations. */
                statistic_data_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_DOUBLE;
                statistic_data_g_tc_members[0]._annotations._defaultValue._u.double_value = 0.0;
                statistic_data_g_tc_members[0]._annotations._minValue._d = RTI_XCDR_TK_DOUBLE;
                statistic_data_g_tc_members[0]._annotations._minValue._u.double_value = RTIXCdrDouble_MIN;
                statistic_data_g_tc_members[0]._annotations._maxValue._d = RTI_XCDR_TK_DOUBLE;
                statistic_data_g_tc_members[0]._annotations._maxValue._u.double_value = RTIXCdrDouble_MAX;
                statistic_data_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_DOUBLE;
                statistic_data_g_tc_members[1]._annotations._defaultValue._u.double_value = 0.0;
                statistic_data_g_tc_members[1]._annotations._minValue._d = RTI_XCDR_TK_DOUBLE;
                statistic_data_g_tc_members[1]._annotations._minValue._u.double_value = RTIXCdrDouble_MIN;
                statistic_data_g_tc_members[1]._annotations._maxValue._d = RTI_XCDR_TK_DOUBLE;
                statistic_data_g_tc_members[1]._annotations._maxValue._u.double_value = RTIXCdrDouble_MAX;
                statistic_data_g_tc_members[2]._annotations._defaultValue._d = RTI_XCDR_TK_SHORT;
                statistic_data_g_tc_members[2]._annotations._defaultValue._u.short_value = 0;
                statistic_data_g_tc_members[2]._annotations._minValue._d = RTI_XCDR_TK_SHORT;
                statistic_data_g_tc_members[2]._annotations._minValue._u.short_value = RTIXCdrShort_MIN;
                statistic_data_g_tc_members[2]._annotations._maxValue._d = RTI_XCDR_TK_SHORT;
                statistic_data_g_tc_members[2]._annotations._maxValue._u.short_value = RTIXCdrShort_MAX;

                statistic_data_g_tc._data._sampleAccessInfo = sample_access_info();
                statistic_data_g_tc._data._typePlugin = type_plugin_info();    

                return &statistic_data_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                ::statistic_data *sample;

                static RTIXCdrMemberAccessInfo statistic_data_g_memberAccessInfos[3] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo statistic_data_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &statistic_data_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    ::statistic_data);
                if (sample == NULL) {
                    return NULL;
                }

                statistic_data_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->height() - (char *)sample);

                statistic_data_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->depth() - (char *)sample);

                statistic_data_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->auto_flag() - (char *)sample);

                statistic_data_g_sampleAccessInfo.memberAccessInfos = 
                statistic_data_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(::statistic_data);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        statistic_data_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        statistic_data_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                statistic_data_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                statistic_data_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< ::statistic_data >;

                statistic_data_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &statistic_data_g_sampleAccessInfo;
            }
            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin statistic_data_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &statistic_data_g_typePlugin;
            }
        }; // native_type_code

        const ::dds::core::xtypes::StructType& dynamic_type< ::statistic_data >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< ::statistic_data >::get())));
        }
    }
}

namespace dds { 
    namespace topic {
        void topic_type_support< ::streamdeck_buttons_data >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                ::streamdeck_buttons_dataPlugin_new,
                ::streamdeck_buttons_dataPlugin_delete);
        }

        std::vector<char>& topic_type_support< ::streamdeck_buttons_data >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const ::streamdeck_buttons_data& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = streamdeck_buttons_dataPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = streamdeck_buttons_dataPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< ::streamdeck_buttons_data >::from_cdr_buffer(::streamdeck_buttons_data& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = streamdeck_buttons_dataPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create ::streamdeck_buttons_data from cdr buffer");
        }

        void topic_type_support< ::streamdeck_buttons_data >::reset_sample(::streamdeck_buttons_data& sample) 
        {
            sample.buttons(0);
        }

        void topic_type_support< ::streamdeck_buttons_data >::allocate_sample(::streamdeck_buttons_data& sample, int, int) 
        {
            RTIOsapiUtility_unusedParameter(sample);
        }
        void topic_type_support< ::statistic_data >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                ::statistic_dataPlugin_new,
                ::statistic_dataPlugin_delete);
        }

        std::vector<char>& topic_type_support< ::statistic_data >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const ::statistic_data& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = statistic_dataPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = statistic_dataPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< ::statistic_data >::from_cdr_buffer(::statistic_data& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = statistic_dataPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create ::statistic_data from cdr buffer");
        }

        void topic_type_support< ::statistic_data >::reset_sample(::statistic_data& sample) 
        {
            sample.height(0.0);
            sample.depth(0.0);
            sample.auto_flag(0);
        }

        void topic_type_support< ::statistic_data >::allocate_sample(::statistic_data& sample, int, int) 
        {
            RTIOsapiUtility_unusedParameter(sample);
        }
    }
}  

#endif // NDDS_STANDALONE_TYPE
