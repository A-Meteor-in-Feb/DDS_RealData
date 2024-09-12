

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

#ifndef NDDS_STANDALONE_TYPE
#include "rti/topic/cdr/Serialization.hpp"
#include "dataPlugin.hpp"
#else
#include "rti/topic/cdr/SerializationHelpers.hpp"
#endif

#include "data.hpp"

#include <rti/util/ostream_operators.hpp>

// ---- IMU_data: 

IMU_data::IMU_data() :
    m_vin_ ("")  {

}   

IMU_data::IMU_data (const std::string& vin_,const ::rti::core::bounded_sequence< double, 3L >& acceleration_,const ::rti::core::bounded_sequence< double, 3L >& velocity_,const ::rti::core::bounded_sequence< double, 3L >& angle_,const ::rti::core::bounded_sequence< double, 3L >& magnetism_):
    m_vin_(vin_), 
    m_acceleration_(acceleration_), 
    m_velocity_(velocity_), 
    m_angle_(angle_), 
    m_magnetism_(magnetism_) {
}

void IMU_data::swap(IMU_data& other_)  noexcept 
{
    using std::swap;
    swap(m_vin_, other_.m_vin_);
    swap(m_acceleration_, other_.m_acceleration_);
    swap(m_velocity_, other_.m_velocity_);
    swap(m_angle_, other_.m_angle_);
    swap(m_magnetism_, other_.m_magnetism_);
}  

bool IMU_data::operator == (const IMU_data& other_) const {
    if (m_vin_ != other_.m_vin_) {
        return false;
    }
    if (m_acceleration_ != other_.m_acceleration_) {
        return false;
    }
    if (m_velocity_ != other_.m_velocity_) {
        return false;
    }
    if (m_angle_ != other_.m_angle_) {
        return false;
    }
    if (m_magnetism_ != other_.m_magnetism_) {
        return false;
    }
    return true;
}

bool IMU_data::operator != (const IMU_data& other_) const {
    return !this->operator ==(other_);
}

std::ostream& operator << (std::ostream& o,const IMU_data& sample)
{
    ::rti::util::StreamFlagSaver flag_saver (o);
    o <<"[";
    o << "vin: " << sample.vin ()<<", ";
    o << "acceleration: " << sample.acceleration ()<<", ";
    o << "velocity: " << sample.velocity ()<<", ";
    o << "angle: " << sample.angle ()<<", ";
    o << "magnetism: " << sample.magnetism ();
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
        struct native_type_code< ::IMU_data > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode IMU_data_g_tc_vin_string;
                static DDS_TypeCode IMU_data_g_tc_acceleration_sequence;
                static DDS_TypeCode IMU_data_g_tc_velocity_sequence;
                static DDS_TypeCode IMU_data_g_tc_angle_sequence;
                static DDS_TypeCode IMU_data_g_tc_magnetism_sequence;

                static DDS_TypeCode_Member IMU_data_g_tc_members[5]=
                {

                    {
                        (char *)"vin",/* Member name */
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
                        (char *)"acceleration",/* Member name */
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
                        (char *)"velocity",/* Member name */
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
                    }, 
                    {
                        (char *)"angle",/* Member name */
                        {
                            3,/* Representation ID */
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
                        (char *)"magnetism",/* Member name */
                        {
                            4,/* Representation ID */
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

                static DDS_TypeCode IMU_data_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"IMU_data", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        5, /* Number of members */
                        IMU_data_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for IMU_data*/

                if (is_initialized) {
                    return &IMU_data_g_tc;
                }

                is_initialized = RTI_TRUE;

                IMU_data_g_tc_vin_string = initialize_string_typecode((255L));
                IMU_data_g_tc_acceleration_sequence = initialize_sequence_typecode< ::rti::core::bounded_sequence< double, 3L > >((3L));
                IMU_data_g_tc_velocity_sequence = initialize_sequence_typecode< ::rti::core::bounded_sequence< double, 3L > >((3L));
                IMU_data_g_tc_angle_sequence = initialize_sequence_typecode< ::rti::core::bounded_sequence< double, 3L > >((3L));
                IMU_data_g_tc_magnetism_sequence = initialize_sequence_typecode< ::rti::core::bounded_sequence< double, 3L > >((3L));

                IMU_data_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                IMU_data_g_tc_acceleration_sequence._data._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
                IMU_data_g_tc_velocity_sequence._data._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
                IMU_data_g_tc_angle_sequence._data._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
                IMU_data_g_tc_magnetism_sequence._data._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
                IMU_data_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&IMU_data_g_tc_vin_string;
                IMU_data_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)& IMU_data_g_tc_acceleration_sequence;
                IMU_data_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)& IMU_data_g_tc_velocity_sequence;
                IMU_data_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)& IMU_data_g_tc_angle_sequence;
                IMU_data_g_tc_members[4]._representation._typeCode = (RTICdrTypeCode *)& IMU_data_g_tc_magnetism_sequence;

                /* Initialize the values for member annotations. */
                IMU_data_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_STRING;
                IMU_data_g_tc_members[0]._annotations._defaultValue._u.string_value = (DDS_Char *) "";

                IMU_data_g_tc._data._sampleAccessInfo = sample_access_info();
                IMU_data_g_tc._data._typePlugin = type_plugin_info();    

                return &IMU_data_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                ::IMU_data *sample;

                static RTIXCdrMemberAccessInfo IMU_data_g_memberAccessInfos[5] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo IMU_data_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &IMU_data_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    ::IMU_data);
                if (sample == NULL) {
                    return NULL;
                }

                IMU_data_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->vin() - (char *)sample);

                IMU_data_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->acceleration() - (char *)sample);

                IMU_data_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->velocity() - (char *)sample);

                IMU_data_g_memberAccessInfos[3].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->angle() - (char *)sample);

                IMU_data_g_memberAccessInfos[4].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->magnetism() - (char *)sample);

                IMU_data_g_sampleAccessInfo.memberAccessInfos = 
                IMU_data_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(::IMU_data);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        IMU_data_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        IMU_data_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                IMU_data_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                IMU_data_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< ::IMU_data >;

                IMU_data_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &IMU_data_g_sampleAccessInfo;
            }
            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin IMU_data_g_typePlugin = 
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

                return &IMU_data_g_typePlugin;
            }
        }; // native_type_code

        const ::dds::core::xtypes::StructType& dynamic_type< ::IMU_data >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< ::IMU_data >::get())));
        }
    }
}

namespace dds { 
    namespace topic {
        void topic_type_support< ::IMU_data >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                ::IMU_dataPlugin_new,
                ::IMU_dataPlugin_delete);
        }

        std::vector<char>& topic_type_support< ::IMU_data >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const ::IMU_data& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = IMU_dataPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = IMU_dataPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< ::IMU_data >::from_cdr_buffer(::IMU_data& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = IMU_dataPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create ::IMU_data from cdr buffer");
        }

        void topic_type_support< ::IMU_data >::reset_sample(::IMU_data& sample) 
        {
            sample.vin("");
            ::rti::topic::reset_sample(sample.acceleration());
            ::rti::topic::reset_sample(sample.velocity());
            ::rti::topic::reset_sample(sample.angle());
            ::rti::topic::reset_sample(sample.magnetism());
        }

        void topic_type_support< ::IMU_data >::allocate_sample(::IMU_data& sample, int, int) 
        {
            ::rti::topic::allocate_sample(sample.vin(),  -1, 255L);
            ::rti::topic::allocate_sample(sample.acceleration(),  3L, -1);
            ::rti::topic::allocate_sample(sample.velocity(),  3L, -1);
            ::rti::topic::allocate_sample(sample.angle(),  3L, -1);
            ::rti::topic::allocate_sample(sample.magnetism(),  3L, -1);
        }
    }
}  

#endif // NDDS_STANDALONE_TYPE
