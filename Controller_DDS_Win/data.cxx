

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

// ---- steeringWheel_data: 

steeringWheel_data::steeringWheel_data() :
    m_tin_ ("") ,
    m_lX_ (0) ,
    m_lY_ (0) ,
    m_lRz_ (0) ,
    m_rglSlider_0_ (0) ,
    m_buttons_ (0u)  {

}   

steeringWheel_data::steeringWheel_data (const std::string& tin_,int32_t lX_,int32_t lY_,int32_t lRz_,int32_t rglSlider_0_,uint32_t buttons_):
    m_tin_(tin_), 
    m_lX_(lX_), 
    m_lY_(lY_), 
    m_lRz_(lRz_), 
    m_rglSlider_0_(rglSlider_0_), 
    m_buttons_(buttons_) {
}

void steeringWheel_data::swap(steeringWheel_data& other_)  noexcept 
{
    using std::swap;
    swap(m_tin_, other_.m_tin_);
    swap(m_lX_, other_.m_lX_);
    swap(m_lY_, other_.m_lY_);
    swap(m_lRz_, other_.m_lRz_);
    swap(m_rglSlider_0_, other_.m_rglSlider_0_);
    swap(m_buttons_, other_.m_buttons_);
}  

bool steeringWheel_data::operator == (const steeringWheel_data& other_) const {
    if (m_tin_ != other_.m_tin_) {
        return false;
    }
    if (m_lX_ != other_.m_lX_) {
        return false;
    }
    if (m_lY_ != other_.m_lY_) {
        return false;
    }
    if (m_lRz_ != other_.m_lRz_) {
        return false;
    }
    if (m_rglSlider_0_ != other_.m_rglSlider_0_) {
        return false;
    }
    if (m_buttons_ != other_.m_buttons_) {
        return false;
    }
    return true;
}

bool steeringWheel_data::operator != (const steeringWheel_data& other_) const {
    return !this->operator ==(other_);
}

std::ostream& operator << (std::ostream& o,const steeringWheel_data& sample)
{
    ::rti::util::StreamFlagSaver flag_saver (o);
    o <<"[";
    o << "tin: " << sample.tin ()<<", ";
    o << "lX: " << sample.lX ()<<", ";
    o << "lY: " << sample.lY ()<<", ";
    o << "lRz: " << sample.lRz ()<<", ";
    o << "rglSlider_0: " << sample.rglSlider_0 ()<<", ";
    o << "buttons: " << sample.buttons ();
    o <<"]";
    return o;
}

// ---- joyStick_data: 

joyStick_data::joyStick_data() :
    m_tin_ ("") ,
    m_lX_ (0) ,
    m_lY_ (0) ,
    m_lZ_ (0) ,
    m_lRx_ (0) ,
    m_lRy_ (0) ,
    m_lRz_ (0) ,
    m_buttons_ (0u)  {

}   

joyStick_data::joyStick_data (const std::string& tin_,int32_t lX_,int32_t lY_,int32_t lZ_,int32_t lRx_,int32_t lRy_,int32_t lRz_,uint32_t buttons_,const ::rti::core::bounded_sequence< int32_t, 2L >& rglSlider_):
    m_tin_(tin_), 
    m_lX_(lX_), 
    m_lY_(lY_), 
    m_lZ_(lZ_), 
    m_lRx_(lRx_), 
    m_lRy_(lRy_), 
    m_lRz_(lRz_), 
    m_buttons_(buttons_), 
    m_rglSlider_(rglSlider_) {
}

void joyStick_data::swap(joyStick_data& other_)  noexcept 
{
    using std::swap;
    swap(m_tin_, other_.m_tin_);
    swap(m_lX_, other_.m_lX_);
    swap(m_lY_, other_.m_lY_);
    swap(m_lZ_, other_.m_lZ_);
    swap(m_lRx_, other_.m_lRx_);
    swap(m_lRy_, other_.m_lRy_);
    swap(m_lRz_, other_.m_lRz_);
    swap(m_buttons_, other_.m_buttons_);
    swap(m_rglSlider_, other_.m_rglSlider_);
}  

bool joyStick_data::operator == (const joyStick_data& other_) const {
    if (m_tin_ != other_.m_tin_) {
        return false;
    }
    if (m_lX_ != other_.m_lX_) {
        return false;
    }
    if (m_lY_ != other_.m_lY_) {
        return false;
    }
    if (m_lZ_ != other_.m_lZ_) {
        return false;
    }
    if (m_lRx_ != other_.m_lRx_) {
        return false;
    }
    if (m_lRy_ != other_.m_lRy_) {
        return false;
    }
    if (m_lRz_ != other_.m_lRz_) {
        return false;
    }
    if (m_buttons_ != other_.m_buttons_) {
        return false;
    }
    if (m_rglSlider_ != other_.m_rglSlider_) {
        return false;
    }
    return true;
}

bool joyStick_data::operator != (const joyStick_data& other_) const {
    return !this->operator ==(other_);
}

std::ostream& operator << (std::ostream& o,const joyStick_data& sample)
{
    ::rti::util::StreamFlagSaver flag_saver (o);
    o <<"[";
    o << "tin: " << sample.tin ()<<", ";
    o << "lX: " << sample.lX ()<<", ";
    o << "lY: " << sample.lY ()<<", ";
    o << "lZ: " << sample.lZ ()<<", ";
    o << "lRx: " << sample.lRx ()<<", ";
    o << "lRy: " << sample.lRy ()<<", ";
    o << "lRz: " << sample.lRz ()<<", ";
    o << "buttons: " << sample.buttons ()<<", ";
    o << "rglSlider: " << sample.rglSlider ();
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
        struct native_type_code< ::steeringWheel_data > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode steeringWheel_data_g_tc_tin_string;

                static DDS_TypeCode_Member steeringWheel_data_g_tc_members[6]=
                {

                    {
                        (char *)"tin",/* Member name */
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
                        (char *)"lX",/* Member name */
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
                        (char *)"lY",/* Member name */
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
                        (char *)"lRz",/* Member name */
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
                        (char *)"rglSlider_0",/* Member name */
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
                    }, 
                    {
                        (char *)"buttons",/* Member name */
                        {
                            5,/* Representation ID */
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

                static DDS_TypeCode steeringWheel_data_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"steeringWheel_data", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        6, /* Number of members */
                        steeringWheel_data_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for steeringWheel_data*/

                if (is_initialized) {
                    return &steeringWheel_data_g_tc;
                }

                is_initialized = RTI_TRUE;

                steeringWheel_data_g_tc_tin_string = initialize_string_typecode((255L));

                steeringWheel_data_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                steeringWheel_data_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&steeringWheel_data_g_tc_tin_string;
                steeringWheel_data_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;
                steeringWheel_data_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;
                steeringWheel_data_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;
                steeringWheel_data_g_tc_members[4]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;
                steeringWheel_data_g_tc_members[5]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ulong;

                /* Initialize the values for member annotations. */
                steeringWheel_data_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_STRING;
                steeringWheel_data_g_tc_members[0]._annotations._defaultValue._u.string_value = (DDS_Char *) "";
                steeringWheel_data_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_LONG;
                steeringWheel_data_g_tc_members[1]._annotations._defaultValue._u.long_value = 0;
                steeringWheel_data_g_tc_members[1]._annotations._minValue._d = RTI_XCDR_TK_LONG;
                steeringWheel_data_g_tc_members[1]._annotations._minValue._u.long_value = RTIXCdrLong_MIN;
                steeringWheel_data_g_tc_members[1]._annotations._maxValue._d = RTI_XCDR_TK_LONG;
                steeringWheel_data_g_tc_members[1]._annotations._maxValue._u.long_value = RTIXCdrLong_MAX;
                steeringWheel_data_g_tc_members[2]._annotations._defaultValue._d = RTI_XCDR_TK_LONG;
                steeringWheel_data_g_tc_members[2]._annotations._defaultValue._u.long_value = 0;
                steeringWheel_data_g_tc_members[2]._annotations._minValue._d = RTI_XCDR_TK_LONG;
                steeringWheel_data_g_tc_members[2]._annotations._minValue._u.long_value = RTIXCdrLong_MIN;
                steeringWheel_data_g_tc_members[2]._annotations._maxValue._d = RTI_XCDR_TK_LONG;
                steeringWheel_data_g_tc_members[2]._annotations._maxValue._u.long_value = RTIXCdrLong_MAX;
                steeringWheel_data_g_tc_members[3]._annotations._defaultValue._d = RTI_XCDR_TK_LONG;
                steeringWheel_data_g_tc_members[3]._annotations._defaultValue._u.long_value = 0;
                steeringWheel_data_g_tc_members[3]._annotations._minValue._d = RTI_XCDR_TK_LONG;
                steeringWheel_data_g_tc_members[3]._annotations._minValue._u.long_value = RTIXCdrLong_MIN;
                steeringWheel_data_g_tc_members[3]._annotations._maxValue._d = RTI_XCDR_TK_LONG;
                steeringWheel_data_g_tc_members[3]._annotations._maxValue._u.long_value = RTIXCdrLong_MAX;
                steeringWheel_data_g_tc_members[4]._annotations._defaultValue._d = RTI_XCDR_TK_LONG;
                steeringWheel_data_g_tc_members[4]._annotations._defaultValue._u.long_value = 0;
                steeringWheel_data_g_tc_members[4]._annotations._minValue._d = RTI_XCDR_TK_LONG;
                steeringWheel_data_g_tc_members[4]._annotations._minValue._u.long_value = RTIXCdrLong_MIN;
                steeringWheel_data_g_tc_members[4]._annotations._maxValue._d = RTI_XCDR_TK_LONG;
                steeringWheel_data_g_tc_members[4]._annotations._maxValue._u.long_value = RTIXCdrLong_MAX;
                steeringWheel_data_g_tc_members[5]._annotations._defaultValue._d = RTI_XCDR_TK_ULONG;
                steeringWheel_data_g_tc_members[5]._annotations._defaultValue._u.ulong_value = 0u;
                steeringWheel_data_g_tc_members[5]._annotations._minValue._d = RTI_XCDR_TK_ULONG;
                steeringWheel_data_g_tc_members[5]._annotations._minValue._u.ulong_value = RTIXCdrUnsignedLong_MIN;
                steeringWheel_data_g_tc_members[5]._annotations._maxValue._d = RTI_XCDR_TK_ULONG;
                steeringWheel_data_g_tc_members[5]._annotations._maxValue._u.ulong_value = RTIXCdrUnsignedLong_MAX;

                steeringWheel_data_g_tc._data._sampleAccessInfo = sample_access_info();
                steeringWheel_data_g_tc._data._typePlugin = type_plugin_info();    

                return &steeringWheel_data_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                ::steeringWheel_data *sample;

                static RTIXCdrMemberAccessInfo steeringWheel_data_g_memberAccessInfos[6] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo steeringWheel_data_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &steeringWheel_data_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    ::steeringWheel_data);
                if (sample == NULL) {
                    return NULL;
                }

                steeringWheel_data_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->tin() - (char *)sample);

                steeringWheel_data_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->lX() - (char *)sample);

                steeringWheel_data_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->lY() - (char *)sample);

                steeringWheel_data_g_memberAccessInfos[3].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->lRz() - (char *)sample);

                steeringWheel_data_g_memberAccessInfos[4].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->rglSlider_0() - (char *)sample);

                steeringWheel_data_g_memberAccessInfos[5].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->buttons() - (char *)sample);

                steeringWheel_data_g_sampleAccessInfo.memberAccessInfos = 
                steeringWheel_data_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(::steeringWheel_data);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        steeringWheel_data_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        steeringWheel_data_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                steeringWheel_data_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                steeringWheel_data_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< ::steeringWheel_data >;

                steeringWheel_data_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &steeringWheel_data_g_sampleAccessInfo;
            }
            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin steeringWheel_data_g_typePlugin = 
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

                return &steeringWheel_data_g_typePlugin;
            }
        }; // native_type_code

        const ::dds::core::xtypes::StructType& dynamic_type< ::steeringWheel_data >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< ::steeringWheel_data >::get())));
        }

        template<>
        struct native_type_code< ::joyStick_data > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode joyStick_data_g_tc_tin_string;
                static DDS_TypeCode joyStick_data_g_tc_rglSlider_sequence;

                static DDS_TypeCode_Member joyStick_data_g_tc_members[9]=
                {

                    {
                        (char *)"tin",/* Member name */
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
                        (char *)"lX",/* Member name */
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
                        (char *)"lY",/* Member name */
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
                        (char *)"lZ",/* Member name */
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
                        (char *)"lRx",/* Member name */
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
                    }, 
                    {
                        (char *)"lRy",/* Member name */
                        {
                            5,/* Representation ID */
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
                        (char *)"lRz",/* Member name */
                        {
                            6,/* Representation ID */
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
                        (char *)"buttons",/* Member name */
                        {
                            7,/* Representation ID */
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
                        (char *)"rglSlider",/* Member name */
                        {
                            8,/* Representation ID */
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

                static DDS_TypeCode joyStick_data_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"joyStick_data", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        9, /* Number of members */
                        joyStick_data_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for joyStick_data*/

                if (is_initialized) {
                    return &joyStick_data_g_tc;
                }

                is_initialized = RTI_TRUE;

                joyStick_data_g_tc_tin_string = initialize_string_typecode((255L));
                joyStick_data_g_tc_rglSlider_sequence = initialize_sequence_typecode< ::rti::core::bounded_sequence< int32_t, 2L > >((2L));

                joyStick_data_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                joyStick_data_g_tc_rglSlider_sequence._data._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;
                joyStick_data_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&joyStick_data_g_tc_tin_string;
                joyStick_data_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;
                joyStick_data_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;
                joyStick_data_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;
                joyStick_data_g_tc_members[4]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;
                joyStick_data_g_tc_members[5]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;
                joyStick_data_g_tc_members[6]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;
                joyStick_data_g_tc_members[7]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ulong;
                joyStick_data_g_tc_members[8]._representation._typeCode = (RTICdrTypeCode *)& joyStick_data_g_tc_rglSlider_sequence;

                /* Initialize the values for member annotations. */
                joyStick_data_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_STRING;
                joyStick_data_g_tc_members[0]._annotations._defaultValue._u.string_value = (DDS_Char *) "";
                joyStick_data_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_LONG;
                joyStick_data_g_tc_members[1]._annotations._defaultValue._u.long_value = 0;
                joyStick_data_g_tc_members[1]._annotations._minValue._d = RTI_XCDR_TK_LONG;
                joyStick_data_g_tc_members[1]._annotations._minValue._u.long_value = RTIXCdrLong_MIN;
                joyStick_data_g_tc_members[1]._annotations._maxValue._d = RTI_XCDR_TK_LONG;
                joyStick_data_g_tc_members[1]._annotations._maxValue._u.long_value = RTIXCdrLong_MAX;
                joyStick_data_g_tc_members[2]._annotations._defaultValue._d = RTI_XCDR_TK_LONG;
                joyStick_data_g_tc_members[2]._annotations._defaultValue._u.long_value = 0;
                joyStick_data_g_tc_members[2]._annotations._minValue._d = RTI_XCDR_TK_LONG;
                joyStick_data_g_tc_members[2]._annotations._minValue._u.long_value = RTIXCdrLong_MIN;
                joyStick_data_g_tc_members[2]._annotations._maxValue._d = RTI_XCDR_TK_LONG;
                joyStick_data_g_tc_members[2]._annotations._maxValue._u.long_value = RTIXCdrLong_MAX;
                joyStick_data_g_tc_members[3]._annotations._defaultValue._d = RTI_XCDR_TK_LONG;
                joyStick_data_g_tc_members[3]._annotations._defaultValue._u.long_value = 0;
                joyStick_data_g_tc_members[3]._annotations._minValue._d = RTI_XCDR_TK_LONG;
                joyStick_data_g_tc_members[3]._annotations._minValue._u.long_value = RTIXCdrLong_MIN;
                joyStick_data_g_tc_members[3]._annotations._maxValue._d = RTI_XCDR_TK_LONG;
                joyStick_data_g_tc_members[3]._annotations._maxValue._u.long_value = RTIXCdrLong_MAX;
                joyStick_data_g_tc_members[4]._annotations._defaultValue._d = RTI_XCDR_TK_LONG;
                joyStick_data_g_tc_members[4]._annotations._defaultValue._u.long_value = 0;
                joyStick_data_g_tc_members[4]._annotations._minValue._d = RTI_XCDR_TK_LONG;
                joyStick_data_g_tc_members[4]._annotations._minValue._u.long_value = RTIXCdrLong_MIN;
                joyStick_data_g_tc_members[4]._annotations._maxValue._d = RTI_XCDR_TK_LONG;
                joyStick_data_g_tc_members[4]._annotations._maxValue._u.long_value = RTIXCdrLong_MAX;
                joyStick_data_g_tc_members[5]._annotations._defaultValue._d = RTI_XCDR_TK_LONG;
                joyStick_data_g_tc_members[5]._annotations._defaultValue._u.long_value = 0;
                joyStick_data_g_tc_members[5]._annotations._minValue._d = RTI_XCDR_TK_LONG;
                joyStick_data_g_tc_members[5]._annotations._minValue._u.long_value = RTIXCdrLong_MIN;
                joyStick_data_g_tc_members[5]._annotations._maxValue._d = RTI_XCDR_TK_LONG;
                joyStick_data_g_tc_members[5]._annotations._maxValue._u.long_value = RTIXCdrLong_MAX;
                joyStick_data_g_tc_members[6]._annotations._defaultValue._d = RTI_XCDR_TK_LONG;
                joyStick_data_g_tc_members[6]._annotations._defaultValue._u.long_value = 0;
                joyStick_data_g_tc_members[6]._annotations._minValue._d = RTI_XCDR_TK_LONG;
                joyStick_data_g_tc_members[6]._annotations._minValue._u.long_value = RTIXCdrLong_MIN;
                joyStick_data_g_tc_members[6]._annotations._maxValue._d = RTI_XCDR_TK_LONG;
                joyStick_data_g_tc_members[6]._annotations._maxValue._u.long_value = RTIXCdrLong_MAX;
                joyStick_data_g_tc_members[7]._annotations._defaultValue._d = RTI_XCDR_TK_ULONG;
                joyStick_data_g_tc_members[7]._annotations._defaultValue._u.ulong_value = 0u;
                joyStick_data_g_tc_members[7]._annotations._minValue._d = RTI_XCDR_TK_ULONG;
                joyStick_data_g_tc_members[7]._annotations._minValue._u.ulong_value = RTIXCdrUnsignedLong_MIN;
                joyStick_data_g_tc_members[7]._annotations._maxValue._d = RTI_XCDR_TK_ULONG;
                joyStick_data_g_tc_members[7]._annotations._maxValue._u.ulong_value = RTIXCdrUnsignedLong_MAX;

                joyStick_data_g_tc._data._sampleAccessInfo = sample_access_info();
                joyStick_data_g_tc._data._typePlugin = type_plugin_info();    

                return &joyStick_data_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                ::joyStick_data *sample;

                static RTIXCdrMemberAccessInfo joyStick_data_g_memberAccessInfos[9] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo joyStick_data_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &joyStick_data_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    ::joyStick_data);
                if (sample == NULL) {
                    return NULL;
                }

                joyStick_data_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->tin() - (char *)sample);

                joyStick_data_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->lX() - (char *)sample);

                joyStick_data_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->lY() - (char *)sample);

                joyStick_data_g_memberAccessInfos[3].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->lZ() - (char *)sample);

                joyStick_data_g_memberAccessInfos[4].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->lRx() - (char *)sample);

                joyStick_data_g_memberAccessInfos[5].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->lRy() - (char *)sample);

                joyStick_data_g_memberAccessInfos[6].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->lRz() - (char *)sample);

                joyStick_data_g_memberAccessInfos[7].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->buttons() - (char *)sample);

                joyStick_data_g_memberAccessInfos[8].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->rglSlider() - (char *)sample);

                joyStick_data_g_sampleAccessInfo.memberAccessInfos = 
                joyStick_data_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(::joyStick_data);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        joyStick_data_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        joyStick_data_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                joyStick_data_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                joyStick_data_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< ::joyStick_data >;

                joyStick_data_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &joyStick_data_g_sampleAccessInfo;
            }
            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin joyStick_data_g_typePlugin = 
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

                return &joyStick_data_g_typePlugin;
            }
        }; // native_type_code

        const ::dds::core::xtypes::StructType& dynamic_type< ::joyStick_data >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< ::joyStick_data >::get())));
        }
    }
}

namespace dds { 
    namespace topic {
        void topic_type_support< ::steeringWheel_data >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                ::steeringWheel_dataPlugin_new,
                ::steeringWheel_dataPlugin_delete);
        }

        std::vector<char>& topic_type_support< ::steeringWheel_data >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const ::steeringWheel_data& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = steeringWheel_dataPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = steeringWheel_dataPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< ::steeringWheel_data >::from_cdr_buffer(::steeringWheel_data& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = steeringWheel_dataPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create ::steeringWheel_data from cdr buffer");
        }

        void topic_type_support< ::steeringWheel_data >::reset_sample(::steeringWheel_data& sample) 
        {
            sample.tin("");
            sample.lX(0);
            sample.lY(0);
            sample.lRz(0);
            sample.rglSlider_0(0);
            sample.buttons(0u);
        }

        void topic_type_support< ::steeringWheel_data >::allocate_sample(::steeringWheel_data& sample, int, int) 
        {
            ::rti::topic::allocate_sample(sample.tin(),  -1, 255L);
        }
        void topic_type_support< ::joyStick_data >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                ::joyStick_dataPlugin_new,
                ::joyStick_dataPlugin_delete);
        }

        std::vector<char>& topic_type_support< ::joyStick_data >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const ::joyStick_data& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = joyStick_dataPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = joyStick_dataPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< ::joyStick_data >::from_cdr_buffer(::joyStick_data& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = joyStick_dataPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create ::joyStick_data from cdr buffer");
        }

        void topic_type_support< ::joyStick_data >::reset_sample(::joyStick_data& sample) 
        {
            sample.tin("");
            sample.lX(0);
            sample.lY(0);
            sample.lZ(0);
            sample.lRx(0);
            sample.lRy(0);
            sample.lRz(0);
            sample.buttons(0u);
            ::rti::topic::reset_sample(sample.rglSlider());
        }

        void topic_type_support< ::joyStick_data >::allocate_sample(::joyStick_data& sample, int, int) 
        {
            ::rti::topic::allocate_sample(sample.tin(),  -1, 255L);
            ::rti::topic::allocate_sample(sample.rglSlider(),  2L, -1);
        }
    }
}  

#endif // NDDS_STANDALONE_TYPE
