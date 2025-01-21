

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

// ---- tele_status: 

tele_status::tele_status() :
    m_tele_id_ ("") ,
    m_online_ (0) ,
    m_connected_ (0)  {

}   

tele_status::tele_status (const std::string& tele_id_,bool online_,bool connected_):
    m_tele_id_(tele_id_), 
    m_online_(online_), 
    m_connected_(connected_) {
}

void tele_status::swap(tele_status& other_)  noexcept 
{
    using std::swap;
    swap(m_tele_id_, other_.m_tele_id_);
    swap(m_online_, other_.m_online_);
    swap(m_connected_, other_.m_connected_);
}  

bool tele_status::operator == (const tele_status& other_) const {
    if (m_tele_id_ != other_.m_tele_id_) {
        return false;
    }
    if (m_online_ != other_.m_online_) {
        return false;
    }
    if (m_connected_ != other_.m_connected_) {
        return false;
    }
    return true;
}

bool tele_status::operator != (const tele_status& other_) const {
    return !this->operator ==(other_);
}

std::ostream& operator << (std::ostream& o,const tele_status& sample)
{
    ::rti::util::StreamFlagSaver flag_saver (o);
    o <<"[";
    o << "tele_id: " << sample.tele_id ()<<", ";
    o << "online: " << sample.online ()<<", ";
    o << "connected: " << sample.connected ();
    o <<"]";
    return o;
}

// ---- vehicle_status: 

vehicle_status::vehicle_status() :
    m_vehicle_id_ ("") ,
    m_online_ (0) ,
    m_connected_ (0)  {

}   

vehicle_status::vehicle_status (const std::string& vehicle_id_,bool online_,bool connected_):
    m_vehicle_id_(vehicle_id_), 
    m_online_(online_), 
    m_connected_(connected_) {
}

void vehicle_status::swap(vehicle_status& other_)  noexcept 
{
    using std::swap;
    swap(m_vehicle_id_, other_.m_vehicle_id_);
    swap(m_online_, other_.m_online_);
    swap(m_connected_, other_.m_connected_);
}  

bool vehicle_status::operator == (const vehicle_status& other_) const {
    if (m_vehicle_id_ != other_.m_vehicle_id_) {
        return false;
    }
    if (m_online_ != other_.m_online_) {
        return false;
    }
    if (m_connected_ != other_.m_connected_) {
        return false;
    }
    return true;
}

bool vehicle_status::operator != (const vehicle_status& other_) const {
    return !this->operator ==(other_);
}

std::ostream& operator << (std::ostream& o,const vehicle_status& sample)
{
    ::rti::util::StreamFlagSaver flag_saver (o);
    o <<"[";
    o << "vehicle_id: " << sample.vehicle_id ()<<", ";
    o << "online: " << sample.online ()<<", ";
    o << "connected: " << sample.connected ();
    o <<"]";
    return o;
}

// ---- connection_msg: 

connection_msg::connection_msg() :
    m_tele_id_ ("") ,
    m_vehicle_id_ ("")  {

}   

connection_msg::connection_msg (const std::string& tele_id_,const std::string& vehicle_id_):
    m_tele_id_(tele_id_), 
    m_vehicle_id_(vehicle_id_) {
}

void connection_msg::swap(connection_msg& other_)  noexcept 
{
    using std::swap;
    swap(m_tele_id_, other_.m_tele_id_);
    swap(m_vehicle_id_, other_.m_vehicle_id_);
}  

bool connection_msg::operator == (const connection_msg& other_) const {
    if (m_tele_id_ != other_.m_tele_id_) {
        return false;
    }
    if (m_vehicle_id_ != other_.m_vehicle_id_) {
        return false;
    }
    return true;
}

bool connection_msg::operator != (const connection_msg& other_) const {
    return !this->operator ==(other_);
}

std::ostream& operator << (std::ostream& o,const connection_msg& sample)
{
    ::rti::util::StreamFlagSaver flag_saver (o);
    o <<"[";
    o << "tele_id: " << sample.tele_id ()<<", ";
    o << "vehicle_id: " << sample.vehicle_id ();
    o <<"]";
    return o;
}

// ---- disconnection_msg: 

disconnection_msg::disconnection_msg() :
    m_msg_ ("")  {

}   

disconnection_msg::disconnection_msg (const std::string& msg_):
    m_msg_(msg_) {
}

void disconnection_msg::swap(disconnection_msg& other_)  noexcept 
{
    using std::swap;
    swap(m_msg_, other_.m_msg_);
}  

bool disconnection_msg::operator == (const disconnection_msg& other_) const {
    if (m_msg_ != other_.m_msg_) {
        return false;
    }
    return true;
}

bool disconnection_msg::operator != (const disconnection_msg& other_) const {
    return !this->operator ==(other_);
}

std::ostream& operator << (std::ostream& o,const disconnection_msg& sample)
{
    ::rti::util::StreamFlagSaver flag_saver (o);
    o <<"[";
    o << "msg: " << sample.msg ();
    o <<"]";
    return o;
}

// ---- partition_name: 

partition_name::partition_name() :
    m_name_ ("")  {

}   

partition_name::partition_name (const std::string& name_):
    m_name_(name_) {
}

void partition_name::swap(partition_name& other_)  noexcept 
{
    using std::swap;
    swap(m_name_, other_.m_name_);
}  

bool partition_name::operator == (const partition_name& other_) const {
    if (m_name_ != other_.m_name_) {
        return false;
    }
    return true;
}

bool partition_name::operator != (const partition_name& other_) const {
    return !this->operator ==(other_);
}

std::ostream& operator << (std::ostream& o,const partition_name& sample)
{
    ::rti::util::StreamFlagSaver flag_saver (o);
    o <<"[";
    o << "name: " << sample.name ();
    o <<"]";
    return o;
}

// ---- steeringWheel_data: 

steeringWheel_data::steeringWheel_data() :
    m_lX_ (0) ,
    m_lY_ (0) ,
    m_lRz_ (0) ,
    m_rglSlider_0_ (0) ,
    m_buttons_ (0u)  {

}   

steeringWheel_data::steeringWheel_data (int32_t lX_,int32_t lY_,int32_t lRz_,int32_t rglSlider_0_,uint32_t buttons_):
    m_lX_(lX_), 
    m_lY_(lY_), 
    m_lRz_(lRz_), 
    m_rglSlider_0_(rglSlider_0_), 
    m_buttons_(buttons_) {
}

void steeringWheel_data::swap(steeringWheel_data& other_)  noexcept 
{
    using std::swap;
    swap(m_lX_, other_.m_lX_);
    swap(m_lY_, other_.m_lY_);
    swap(m_lRz_, other_.m_lRz_);
    swap(m_rglSlider_0_, other_.m_rglSlider_0_);
    swap(m_buttons_, other_.m_buttons_);
}  

bool steeringWheel_data::operator == (const steeringWheel_data& other_) const {
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
    m_lX_ (0) ,
    m_lZ_ (0) ,
    m_lRx_ (0) ,
    m_lRy_ (0) ,
    m_lRz_ (0) ,
    m_buttons_ (0u)  {

}   

joyStick_data::joyStick_data (int32_t lX_,int32_t lZ_,int32_t lRx_,int32_t lRy_,int32_t lRz_,uint32_t buttons_,const ::rti::core::bounded_sequence< int32_t, 2L >& rglSlider_):
    m_lX_(lX_), 
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
    swap(m_lX_, other_.m_lX_);
    swap(m_lZ_, other_.m_lZ_);
    swap(m_lRx_, other_.m_lRx_);
    swap(m_lRy_, other_.m_lRy_);
    swap(m_lRz_, other_.m_lRz_);
    swap(m_buttons_, other_.m_buttons_);
    swap(m_rglSlider_, other_.m_rglSlider_);
}  

bool joyStick_data::operator == (const joyStick_data& other_) const {
    if (m_lX_ != other_.m_lX_) {
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
    o << "lX: " << sample.lX ()<<", ";
    o << "lZ: " << sample.lZ ()<<", ";
    o << "lRx: " << sample.lRx ()<<", ";
    o << "lRy: " << sample.lRy ()<<", ";
    o << "lRz: " << sample.lRz ()<<", ";
    o << "buttons: " << sample.buttons ()<<", ";
    o << "rglSlider: " << sample.rglSlider ();
    o <<"]";
    return o;
}

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

// ---- IMU_data: 

IMU_data::IMU_data() :
    m_vin_ ("")  {

}   

IMU_data::IMU_data (const std::string& vin_,const ::rti::core::bounded_sequence< double, 3L >& acc_,const ::rti::core::bounded_sequence< double, 3L >& gyro_,const ::rti::core::bounded_sequence< double, 3L >& angle_,const ::rti::core::bounded_sequence< double, 3L >& mag_):
    m_vin_(vin_), 
    m_acc_(acc_), 
    m_gyro_(gyro_), 
    m_angle_(angle_), 
    m_mag_(mag_) {
}

void IMU_data::swap(IMU_data& other_)  noexcept 
{
    using std::swap;
    swap(m_vin_, other_.m_vin_);
    swap(m_acc_, other_.m_acc_);
    swap(m_gyro_, other_.m_gyro_);
    swap(m_angle_, other_.m_angle_);
    swap(m_mag_, other_.m_mag_);
}  

bool IMU_data::operator == (const IMU_data& other_) const {
    if (m_vin_ != other_.m_vin_) {
        return false;
    }
    if (m_acc_ != other_.m_acc_) {
        return false;
    }
    if (m_gyro_ != other_.m_gyro_) {
        return false;
    }
    if (m_angle_ != other_.m_angle_) {
        return false;
    }
    if (m_mag_ != other_.m_mag_) {
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
    o << "acc: " << sample.acc ()<<", ";
    o << "gyro: " << sample.gyro ()<<", ";
    o << "angle: " << sample.angle ()<<", ";
    o << "mag: " << sample.mag ();
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
        struct native_type_code< ::tele_status > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode tele_status_g_tc_tele_id_string;

                static DDS_TypeCode_Member tele_status_g_tc_members[3]=
                {

                    {
                        (char *)"tele_id",/* Member name */
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
                        (char *)"online",/* Member name */
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
                        (char *)"connected",/* Member name */
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

                static DDS_TypeCode tele_status_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"tele_status", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        3, /* Number of members */
                        tele_status_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for tele_status*/

                if (is_initialized) {
                    return &tele_status_g_tc;
                }

                is_initialized = RTI_TRUE;

                tele_status_g_tc_tele_id_string = initialize_string_typecode((255L));

                tele_status_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                tele_status_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&tele_status_g_tc_tele_id_string;
                tele_status_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::interpreter::initialize_bool_typecode();
                tele_status_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::interpreter::initialize_bool_typecode();

                /* Initialize the values for member annotations. */
                tele_status_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_STRING;
                tele_status_g_tc_members[0]._annotations._defaultValue._u.string_value = (DDS_Char *) "";
                tele_status_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_BOOLEAN;
                tele_status_g_tc_members[1]._annotations._defaultValue._u.boolean_value = 0;
                tele_status_g_tc_members[2]._annotations._defaultValue._d = RTI_XCDR_TK_BOOLEAN;
                tele_status_g_tc_members[2]._annotations._defaultValue._u.boolean_value = 0;

                tele_status_g_tc._data._sampleAccessInfo = sample_access_info();
                tele_status_g_tc._data._typePlugin = type_plugin_info();    

                return &tele_status_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                ::tele_status *sample;

                static RTIXCdrMemberAccessInfo tele_status_g_memberAccessInfos[3] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo tele_status_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &tele_status_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    ::tele_status);
                if (sample == NULL) {
                    return NULL;
                }

                tele_status_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->tele_id() - (char *)sample);

                tele_status_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->online() - (char *)sample);

                tele_status_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->connected() - (char *)sample);

                tele_status_g_sampleAccessInfo.memberAccessInfos = 
                tele_status_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(::tele_status);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        tele_status_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        tele_status_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                tele_status_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                tele_status_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< ::tele_status >;

                tele_status_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &tele_status_g_sampleAccessInfo;
            }
            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin tele_status_g_typePlugin = 
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

                return &tele_status_g_typePlugin;
            }
        }; // native_type_code

        const ::dds::core::xtypes::StructType& dynamic_type< ::tele_status >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< ::tele_status >::get())));
        }

        template<>
        struct native_type_code< ::vehicle_status > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode vehicle_status_g_tc_vehicle_id_string;

                static DDS_TypeCode_Member vehicle_status_g_tc_members[3]=
                {

                    {
                        (char *)"vehicle_id",/* Member name */
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
                        (char *)"online",/* Member name */
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
                        (char *)"connected",/* Member name */
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

                static DDS_TypeCode vehicle_status_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"vehicle_status", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        3, /* Number of members */
                        vehicle_status_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for vehicle_status*/

                if (is_initialized) {
                    return &vehicle_status_g_tc;
                }

                is_initialized = RTI_TRUE;

                vehicle_status_g_tc_vehicle_id_string = initialize_string_typecode((255L));

                vehicle_status_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                vehicle_status_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&vehicle_status_g_tc_vehicle_id_string;
                vehicle_status_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::interpreter::initialize_bool_typecode();
                vehicle_status_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::interpreter::initialize_bool_typecode();

                /* Initialize the values for member annotations. */
                vehicle_status_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_STRING;
                vehicle_status_g_tc_members[0]._annotations._defaultValue._u.string_value = (DDS_Char *) "";
                vehicle_status_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_BOOLEAN;
                vehicle_status_g_tc_members[1]._annotations._defaultValue._u.boolean_value = 0;
                vehicle_status_g_tc_members[2]._annotations._defaultValue._d = RTI_XCDR_TK_BOOLEAN;
                vehicle_status_g_tc_members[2]._annotations._defaultValue._u.boolean_value = 0;

                vehicle_status_g_tc._data._sampleAccessInfo = sample_access_info();
                vehicle_status_g_tc._data._typePlugin = type_plugin_info();    

                return &vehicle_status_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                ::vehicle_status *sample;

                static RTIXCdrMemberAccessInfo vehicle_status_g_memberAccessInfos[3] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo vehicle_status_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &vehicle_status_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    ::vehicle_status);
                if (sample == NULL) {
                    return NULL;
                }

                vehicle_status_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->vehicle_id() - (char *)sample);

                vehicle_status_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->online() - (char *)sample);

                vehicle_status_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->connected() - (char *)sample);

                vehicle_status_g_sampleAccessInfo.memberAccessInfos = 
                vehicle_status_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(::vehicle_status);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        vehicle_status_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        vehicle_status_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                vehicle_status_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                vehicle_status_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< ::vehicle_status >;

                vehicle_status_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &vehicle_status_g_sampleAccessInfo;
            }
            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin vehicle_status_g_typePlugin = 
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

                return &vehicle_status_g_typePlugin;
            }
        }; // native_type_code

        const ::dds::core::xtypes::StructType& dynamic_type< ::vehicle_status >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< ::vehicle_status >::get())));
        }

        template<>
        struct native_type_code< ::connection_msg > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode connection_msg_g_tc_tele_id_string;
                static DDS_TypeCode connection_msg_g_tc_vehicle_id_string;

                static DDS_TypeCode_Member connection_msg_g_tc_members[2]=
                {

                    {
                        (char *)"tele_id",/* Member name */
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
                        (char *)"vehicle_id",/* Member name */
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
                    }
                };

                static DDS_TypeCode connection_msg_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"connection_msg", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        2, /* Number of members */
                        connection_msg_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for connection_msg*/

                if (is_initialized) {
                    return &connection_msg_g_tc;
                }

                is_initialized = RTI_TRUE;

                connection_msg_g_tc_tele_id_string = initialize_string_typecode((255L));
                connection_msg_g_tc_vehicle_id_string = initialize_string_typecode((255L));

                connection_msg_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                connection_msg_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&connection_msg_g_tc_tele_id_string;
                connection_msg_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&connection_msg_g_tc_vehicle_id_string;

                /* Initialize the values for member annotations. */
                connection_msg_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_STRING;
                connection_msg_g_tc_members[0]._annotations._defaultValue._u.string_value = (DDS_Char *) "";
                connection_msg_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_STRING;
                connection_msg_g_tc_members[1]._annotations._defaultValue._u.string_value = (DDS_Char *) "";

                connection_msg_g_tc._data._sampleAccessInfo = sample_access_info();
                connection_msg_g_tc._data._typePlugin = type_plugin_info();    

                return &connection_msg_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                ::connection_msg *sample;

                static RTIXCdrMemberAccessInfo connection_msg_g_memberAccessInfos[2] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo connection_msg_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &connection_msg_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    ::connection_msg);
                if (sample == NULL) {
                    return NULL;
                }

                connection_msg_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->tele_id() - (char *)sample);

                connection_msg_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->vehicle_id() - (char *)sample);

                connection_msg_g_sampleAccessInfo.memberAccessInfos = 
                connection_msg_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(::connection_msg);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        connection_msg_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        connection_msg_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                connection_msg_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                connection_msg_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< ::connection_msg >;

                connection_msg_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &connection_msg_g_sampleAccessInfo;
            }
            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin connection_msg_g_typePlugin = 
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

                return &connection_msg_g_typePlugin;
            }
        }; // native_type_code

        const ::dds::core::xtypes::StructType& dynamic_type< ::connection_msg >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< ::connection_msg >::get())));
        }

        template<>
        struct native_type_code< ::disconnection_msg > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode disconnection_msg_g_tc_msg_string;

                static DDS_TypeCode_Member disconnection_msg_g_tc_members[1]=
                {

                    {
                        (char *)"msg",/* Member name */
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

                static DDS_TypeCode disconnection_msg_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"disconnection_msg", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        1, /* Number of members */
                        disconnection_msg_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for disconnection_msg*/

                if (is_initialized) {
                    return &disconnection_msg_g_tc;
                }

                is_initialized = RTI_TRUE;

                disconnection_msg_g_tc_msg_string = initialize_string_typecode((255L));

                disconnection_msg_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                disconnection_msg_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&disconnection_msg_g_tc_msg_string;

                /* Initialize the values for member annotations. */
                disconnection_msg_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_STRING;
                disconnection_msg_g_tc_members[0]._annotations._defaultValue._u.string_value = (DDS_Char *) "";

                disconnection_msg_g_tc._data._sampleAccessInfo = sample_access_info();
                disconnection_msg_g_tc._data._typePlugin = type_plugin_info();    

                return &disconnection_msg_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                ::disconnection_msg *sample;

                static RTIXCdrMemberAccessInfo disconnection_msg_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo disconnection_msg_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &disconnection_msg_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    ::disconnection_msg);
                if (sample == NULL) {
                    return NULL;
                }

                disconnection_msg_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->msg() - (char *)sample);

                disconnection_msg_g_sampleAccessInfo.memberAccessInfos = 
                disconnection_msg_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(::disconnection_msg);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        disconnection_msg_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        disconnection_msg_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                disconnection_msg_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                disconnection_msg_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< ::disconnection_msg >;

                disconnection_msg_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &disconnection_msg_g_sampleAccessInfo;
            }
            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin disconnection_msg_g_typePlugin = 
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

                return &disconnection_msg_g_typePlugin;
            }
        }; // native_type_code

        const ::dds::core::xtypes::StructType& dynamic_type< ::disconnection_msg >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< ::disconnection_msg >::get())));
        }

        template<>
        struct native_type_code< ::partition_name > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode partition_name_g_tc_name_string;

                static DDS_TypeCode_Member partition_name_g_tc_members[1]=
                {

                    {
                        (char *)"name",/* Member name */
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

                static DDS_TypeCode partition_name_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"partition_name", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        1, /* Number of members */
                        partition_name_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for partition_name*/

                if (is_initialized) {
                    return &partition_name_g_tc;
                }

                is_initialized = RTI_TRUE;

                partition_name_g_tc_name_string = initialize_string_typecode((255L));

                partition_name_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                partition_name_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&partition_name_g_tc_name_string;

                /* Initialize the values for member annotations. */
                partition_name_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_STRING;
                partition_name_g_tc_members[0]._annotations._defaultValue._u.string_value = (DDS_Char *) "";

                partition_name_g_tc._data._sampleAccessInfo = sample_access_info();
                partition_name_g_tc._data._typePlugin = type_plugin_info();    

                return &partition_name_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                ::partition_name *sample;

                static RTIXCdrMemberAccessInfo partition_name_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo partition_name_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &partition_name_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    ::partition_name);
                if (sample == NULL) {
                    return NULL;
                }

                partition_name_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->name() - (char *)sample);

                partition_name_g_sampleAccessInfo.memberAccessInfos = 
                partition_name_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(::partition_name);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        partition_name_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        partition_name_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                partition_name_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                partition_name_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< ::partition_name >;

                partition_name_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &partition_name_g_sampleAccessInfo;
            }
            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin partition_name_g_typePlugin = 
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

                return &partition_name_g_typePlugin;
            }
        }; // native_type_code

        const ::dds::core::xtypes::StructType& dynamic_type< ::partition_name >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< ::partition_name >::get())));
        }

        template<>
        struct native_type_code< ::steeringWheel_data > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member steeringWheel_data_g_tc_members[5]=
                {

                    {
                        (char *)"lX",/* Member name */
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
                        (char *)"lY",/* Member name */
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
                        (char *)"lRz",/* Member name */
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
                        (char *)"rglSlider_0",/* Member name */
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
                        (char *)"buttons",/* Member name */
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
                        5, /* Number of members */
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

                steeringWheel_data_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                steeringWheel_data_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;
                steeringWheel_data_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;
                steeringWheel_data_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;
                steeringWheel_data_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;
                steeringWheel_data_g_tc_members[4]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ulong;

                /* Initialize the values for member annotations. */
                steeringWheel_data_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_LONG;
                steeringWheel_data_g_tc_members[0]._annotations._defaultValue._u.long_value = 0;
                steeringWheel_data_g_tc_members[0]._annotations._minValue._d = RTI_XCDR_TK_LONG;
                steeringWheel_data_g_tc_members[0]._annotations._minValue._u.long_value = RTIXCdrLong_MIN;
                steeringWheel_data_g_tc_members[0]._annotations._maxValue._d = RTI_XCDR_TK_LONG;
                steeringWheel_data_g_tc_members[0]._annotations._maxValue._u.long_value = RTIXCdrLong_MAX;
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
                steeringWheel_data_g_tc_members[4]._annotations._defaultValue._d = RTI_XCDR_TK_ULONG;
                steeringWheel_data_g_tc_members[4]._annotations._defaultValue._u.ulong_value = 0u;
                steeringWheel_data_g_tc_members[4]._annotations._minValue._d = RTI_XCDR_TK_ULONG;
                steeringWheel_data_g_tc_members[4]._annotations._minValue._u.ulong_value = RTIXCdrUnsignedLong_MIN;
                steeringWheel_data_g_tc_members[4]._annotations._maxValue._d = RTI_XCDR_TK_ULONG;
                steeringWheel_data_g_tc_members[4]._annotations._maxValue._u.ulong_value = RTIXCdrUnsignedLong_MAX;

                steeringWheel_data_g_tc._data._sampleAccessInfo = sample_access_info();
                steeringWheel_data_g_tc._data._typePlugin = type_plugin_info();    

                return &steeringWheel_data_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                ::steeringWheel_data *sample;

                static RTIXCdrMemberAccessInfo steeringWheel_data_g_memberAccessInfos[5] =
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
                (RTIXCdrUnsignedLong) ((char *)&sample->lX() - (char *)sample);

                steeringWheel_data_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->lY() - (char *)sample);

                steeringWheel_data_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->lRz() - (char *)sample);

                steeringWheel_data_g_memberAccessInfos[3].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->rglSlider_0() - (char *)sample);

                steeringWheel_data_g_memberAccessInfos[4].bindingMemberValueOffset[0] = 
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

                static DDS_TypeCode joyStick_data_g_tc_rglSlider_sequence;

                static DDS_TypeCode_Member joyStick_data_g_tc_members[7]=
                {

                    {
                        (char *)"lX",/* Member name */
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
                        (char *)"lZ",/* Member name */
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
                        (char *)"lRx",/* Member name */
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
                        (char *)"lRy",/* Member name */
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
                        (char *)"lRz",/* Member name */
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
                    }, 
                    {
                        (char *)"rglSlider",/* Member name */
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
                        7, /* Number of members */
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

                joyStick_data_g_tc_rglSlider_sequence = initialize_sequence_typecode< ::rti::core::bounded_sequence< int32_t, 2L > >((2L));

                joyStick_data_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                joyStick_data_g_tc_rglSlider_sequence._data._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;
                joyStick_data_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;
                joyStick_data_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;
                joyStick_data_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;
                joyStick_data_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;
                joyStick_data_g_tc_members[4]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;
                joyStick_data_g_tc_members[5]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ulong;
                joyStick_data_g_tc_members[6]._representation._typeCode = (RTICdrTypeCode *)& joyStick_data_g_tc_rglSlider_sequence;

                /* Initialize the values for member annotations. */
                joyStick_data_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_LONG;
                joyStick_data_g_tc_members[0]._annotations._defaultValue._u.long_value = 0;
                joyStick_data_g_tc_members[0]._annotations._minValue._d = RTI_XCDR_TK_LONG;
                joyStick_data_g_tc_members[0]._annotations._minValue._u.long_value = RTIXCdrLong_MIN;
                joyStick_data_g_tc_members[0]._annotations._maxValue._d = RTI_XCDR_TK_LONG;
                joyStick_data_g_tc_members[0]._annotations._maxValue._u.long_value = RTIXCdrLong_MAX;
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
                joyStick_data_g_tc_members[5]._annotations._defaultValue._d = RTI_XCDR_TK_ULONG;
                joyStick_data_g_tc_members[5]._annotations._defaultValue._u.ulong_value = 0u;
                joyStick_data_g_tc_members[5]._annotations._minValue._d = RTI_XCDR_TK_ULONG;
                joyStick_data_g_tc_members[5]._annotations._minValue._u.ulong_value = RTIXCdrUnsignedLong_MIN;
                joyStick_data_g_tc_members[5]._annotations._maxValue._d = RTI_XCDR_TK_ULONG;
                joyStick_data_g_tc_members[5]._annotations._maxValue._u.ulong_value = RTIXCdrUnsignedLong_MAX;

                joyStick_data_g_tc._data._sampleAccessInfo = sample_access_info();
                joyStick_data_g_tc._data._typePlugin = type_plugin_info();    

                return &joyStick_data_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                ::joyStick_data *sample;

                static RTIXCdrMemberAccessInfo joyStick_data_g_memberAccessInfos[7] =
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
                (RTIXCdrUnsignedLong) ((char *)&sample->lX() - (char *)sample);

                joyStick_data_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->lZ() - (char *)sample);

                joyStick_data_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->lRx() - (char *)sample);

                joyStick_data_g_memberAccessInfos[3].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->lRy() - (char *)sample);

                joyStick_data_g_memberAccessInfos[4].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->lRz() - (char *)sample);

                joyStick_data_g_memberAccessInfos[5].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->buttons() - (char *)sample);

                joyStick_data_g_memberAccessInfos[6].bindingMemberValueOffset[0] = 
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

        template<>
        struct native_type_code< ::IMU_data > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode IMU_data_g_tc_vin_string;
                static DDS_TypeCode IMU_data_g_tc_acc_sequence;
                static DDS_TypeCode IMU_data_g_tc_gyro_sequence;
                static DDS_TypeCode IMU_data_g_tc_angle_sequence;
                static DDS_TypeCode IMU_data_g_tc_mag_sequence;

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
                        (char *)"acc",/* Member name */
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
                        (char *)"gyro",/* Member name */
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
                        (char *)"mag",/* Member name */
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
                IMU_data_g_tc_acc_sequence = initialize_sequence_typecode< ::rti::core::bounded_sequence< double, 3L > >((3L));
                IMU_data_g_tc_gyro_sequence = initialize_sequence_typecode< ::rti::core::bounded_sequence< double, 3L > >((3L));
                IMU_data_g_tc_angle_sequence = initialize_sequence_typecode< ::rti::core::bounded_sequence< double, 3L > >((3L));
                IMU_data_g_tc_mag_sequence = initialize_sequence_typecode< ::rti::core::bounded_sequence< double, 3L > >((3L));

                IMU_data_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                IMU_data_g_tc_acc_sequence._data._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
                IMU_data_g_tc_gyro_sequence._data._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
                IMU_data_g_tc_angle_sequence._data._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
                IMU_data_g_tc_mag_sequence._data._typeCode = (RTICdrTypeCode *)&DDS_g_tc_double;
                IMU_data_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&IMU_data_g_tc_vin_string;
                IMU_data_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)& IMU_data_g_tc_acc_sequence;
                IMU_data_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)& IMU_data_g_tc_gyro_sequence;
                IMU_data_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)& IMU_data_g_tc_angle_sequence;
                IMU_data_g_tc_members[4]._representation._typeCode = (RTICdrTypeCode *)& IMU_data_g_tc_mag_sequence;

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
                (RTIXCdrUnsignedLong) ((char *)&sample->acc() - (char *)sample);

                IMU_data_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->gyro() - (char *)sample);

                IMU_data_g_memberAccessInfos[3].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->angle() - (char *)sample);

                IMU_data_g_memberAccessInfos[4].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->mag() - (char *)sample);

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
        void topic_type_support< ::tele_status >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                ::tele_statusPlugin_new,
                ::tele_statusPlugin_delete);
        }

        std::vector<char>& topic_type_support< ::tele_status >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const ::tele_status& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = tele_statusPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = tele_statusPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< ::tele_status >::from_cdr_buffer(::tele_status& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = tele_statusPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create ::tele_status from cdr buffer");
        }

        void topic_type_support< ::tele_status >::reset_sample(::tele_status& sample) 
        {
            sample.tele_id("");
            sample.online(0);
            sample.connected(0);
        }

        void topic_type_support< ::tele_status >::allocate_sample(::tele_status& sample, int, int) 
        {
            ::rti::topic::allocate_sample(sample.tele_id(),  -1, 255L);
        }
        void topic_type_support< ::vehicle_status >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                ::vehicle_statusPlugin_new,
                ::vehicle_statusPlugin_delete);
        }

        std::vector<char>& topic_type_support< ::vehicle_status >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const ::vehicle_status& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = vehicle_statusPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = vehicle_statusPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< ::vehicle_status >::from_cdr_buffer(::vehicle_status& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = vehicle_statusPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create ::vehicle_status from cdr buffer");
        }

        void topic_type_support< ::vehicle_status >::reset_sample(::vehicle_status& sample) 
        {
            sample.vehicle_id("");
            sample.online(0);
            sample.connected(0);
        }

        void topic_type_support< ::vehicle_status >::allocate_sample(::vehicle_status& sample, int, int) 
        {
            ::rti::topic::allocate_sample(sample.vehicle_id(),  -1, 255L);
        }
        void topic_type_support< ::connection_msg >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                ::connection_msgPlugin_new,
                ::connection_msgPlugin_delete);
        }

        std::vector<char>& topic_type_support< ::connection_msg >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const ::connection_msg& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = connection_msgPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = connection_msgPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< ::connection_msg >::from_cdr_buffer(::connection_msg& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = connection_msgPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create ::connection_msg from cdr buffer");
        }

        void topic_type_support< ::connection_msg >::reset_sample(::connection_msg& sample) 
        {
            sample.tele_id("");
            sample.vehicle_id("");
        }

        void topic_type_support< ::connection_msg >::allocate_sample(::connection_msg& sample, int, int) 
        {
            ::rti::topic::allocate_sample(sample.tele_id(),  -1, 255L);
            ::rti::topic::allocate_sample(sample.vehicle_id(),  -1, 255L);
        }
        void topic_type_support< ::disconnection_msg >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                ::disconnection_msgPlugin_new,
                ::disconnection_msgPlugin_delete);
        }

        std::vector<char>& topic_type_support< ::disconnection_msg >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const ::disconnection_msg& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = disconnection_msgPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = disconnection_msgPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< ::disconnection_msg >::from_cdr_buffer(::disconnection_msg& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = disconnection_msgPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create ::disconnection_msg from cdr buffer");
        }

        void topic_type_support< ::disconnection_msg >::reset_sample(::disconnection_msg& sample) 
        {
            sample.msg("");
        }

        void topic_type_support< ::disconnection_msg >::allocate_sample(::disconnection_msg& sample, int, int) 
        {
            ::rti::topic::allocate_sample(sample.msg(),  -1, 255L);
        }
        void topic_type_support< ::partition_name >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                ::partition_namePlugin_new,
                ::partition_namePlugin_delete);
        }

        std::vector<char>& topic_type_support< ::partition_name >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const ::partition_name& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = partition_namePlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = partition_namePlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< ::partition_name >::from_cdr_buffer(::partition_name& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = partition_namePlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create ::partition_name from cdr buffer");
        }

        void topic_type_support< ::partition_name >::reset_sample(::partition_name& sample) 
        {
            sample.name("");
        }

        void topic_type_support< ::partition_name >::allocate_sample(::partition_name& sample, int, int) 
        {
            ::rti::topic::allocate_sample(sample.name(),  -1, 255L);
        }
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
            sample.lX(0);
            sample.lY(0);
            sample.lRz(0);
            sample.rglSlider_0(0);
            sample.buttons(0u);
        }

        void topic_type_support< ::steeringWheel_data >::allocate_sample(::steeringWheel_data& sample, int, int) 
        {
            RTIOsapiUtility_unusedParameter(sample);
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
            sample.lX(0);
            sample.lZ(0);
            sample.lRx(0);
            sample.lRy(0);
            sample.lRz(0);
            sample.buttons(0u);
            ::rti::topic::reset_sample(sample.rglSlider());
        }

        void topic_type_support< ::joyStick_data >::allocate_sample(::joyStick_data& sample, int, int) 
        {
            ::rti::topic::allocate_sample(sample.rglSlider(),  2L, -1);
        }
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
            ::rti::topic::reset_sample(sample.acc());
            ::rti::topic::reset_sample(sample.gyro());
            ::rti::topic::reset_sample(sample.angle());
            ::rti::topic::reset_sample(sample.mag());
        }

        void topic_type_support< ::IMU_data >::allocate_sample(::IMU_data& sample, int, int) 
        {
            ::rti::topic::allocate_sample(sample.vin(),  -1, 255L);
            ::rti::topic::allocate_sample(sample.acc(),  3L, -1);
            ::rti::topic::allocate_sample(sample.gyro(),  3L, -1);
            ::rti::topic::allocate_sample(sample.angle(),  3L, -1);
            ::rti::topic::allocate_sample(sample.mag(),  3L, -1);
        }
    }
}  

#endif // NDDS_STANDALONE_TYPE
