

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from data.idl
using RTI Code Generator (rtiddsgen) version 4.3.0.
The rtiddsgen tool is part of the RTI Connext DDS distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the Code Generator User's Manual.
*/

#ifndef data_1787947667_hpp
#define data_1787947667_hpp

#include <iosfwd>

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef RTIUSERDllExport
#define RTIUSERDllExport __declspec(dllexport)
#endif

#include "dds/core/SafeEnumeration.hpp"
#include "dds/core/String.hpp"
#include "dds/core/array.hpp"
#include "dds/core/vector.hpp"
#include "dds/core/External.hpp"
#include "rti/core/LongDouble.hpp"
#include "rti/core/Pointer.hpp"
#include "rti/core/array.hpp"
#include "rti/topic/TopicTraits.hpp"

#include "omg/types/string_view.hpp"

#include "rti/core/BoundedSequence.hpp"
#include "dds/core/Optional.hpp"

#ifndef NDDS_STANDALONE_TYPE
#include "dds/domain/DomainParticipant.hpp"
#include "dds/topic/TopicTraits.hpp"
#include "dds/core/xtypes/DynamicType.hpp"
#include "dds/core/xtypes/StructType.hpp"
#include "dds/core/xtypes/UnionType.hpp"
#include "dds/core/xtypes/EnumType.hpp"
#include "dds/core/xtypes/AliasType.hpp"
#include "rti/util/StreamFlagSaver.hpp"
#include "rti/domain/PluginSupport.hpp"
#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef RTIUSERDllExport
#define RTIUSERDllExport
#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

class NDDSUSERDllExport tele_status {
  public:

    tele_status();

    tele_status(const std::string& tele_id_,bool online_,bool connected_);

    std::string& tele_id() noexcept {
        return m_tele_id_;
    }

    const std::string& tele_id() const noexcept {
        return m_tele_id_;
    }

    void tele_id(const std::string& value) {

        m_tele_id_ = value;
    }

    void tele_id(std::string&& value) {
        m_tele_id_ = std::move(value);
    }
    bool& online() noexcept {
        return m_online_;
    }

    const bool& online() const noexcept {
        return m_online_;
    }

    void online(bool value) {

        m_online_ = value;
    }

    bool& connected() noexcept {
        return m_connected_;
    }

    const bool& connected() const noexcept {
        return m_connected_;
    }

    void connected(bool value) {

        m_connected_ = value;
    }

    bool operator == (const tele_status& other_) const;
    bool operator != (const tele_status& other_) const;

    void swap(tele_status& other_) noexcept ;

  private:

    std::string m_tele_id_;
    bool m_online_;
    bool m_connected_;

};

inline void swap(tele_status& a, tele_status& b)  noexcept 
{
    a.swap(b);
}

NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const tele_status& sample);

class NDDSUSERDllExport vehicle_status {
  public:

    vehicle_status();

    vehicle_status(const std::string& vehicle_id_,bool online_,bool connected_);

    std::string& vehicle_id() noexcept {
        return m_vehicle_id_;
    }

    const std::string& vehicle_id() const noexcept {
        return m_vehicle_id_;
    }

    void vehicle_id(const std::string& value) {

        m_vehicle_id_ = value;
    }

    void vehicle_id(std::string&& value) {
        m_vehicle_id_ = std::move(value);
    }
    bool& online() noexcept {
        return m_online_;
    }

    const bool& online() const noexcept {
        return m_online_;
    }

    void online(bool value) {

        m_online_ = value;
    }

    bool& connected() noexcept {
        return m_connected_;
    }

    const bool& connected() const noexcept {
        return m_connected_;
    }

    void connected(bool value) {

        m_connected_ = value;
    }

    bool operator == (const vehicle_status& other_) const;
    bool operator != (const vehicle_status& other_) const;

    void swap(vehicle_status& other_) noexcept ;

  private:

    std::string m_vehicle_id_;
    bool m_online_;
    bool m_connected_;

};

inline void swap(vehicle_status& a, vehicle_status& b)  noexcept 
{
    a.swap(b);
}

NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const vehicle_status& sample);

class NDDSUSERDllExport connection_msg {
  public:

    connection_msg();

    connection_msg(const std::string& tele_id_,const std::string& vehicle_id_);

    std::string& tele_id() noexcept {
        return m_tele_id_;
    }

    const std::string& tele_id() const noexcept {
        return m_tele_id_;
    }

    void tele_id(const std::string& value) {

        m_tele_id_ = value;
    }

    void tele_id(std::string&& value) {
        m_tele_id_ = std::move(value);
    }
    std::string& vehicle_id() noexcept {
        return m_vehicle_id_;
    }

    const std::string& vehicle_id() const noexcept {
        return m_vehicle_id_;
    }

    void vehicle_id(const std::string& value) {

        m_vehicle_id_ = value;
    }

    void vehicle_id(std::string&& value) {
        m_vehicle_id_ = std::move(value);
    }
    bool operator == (const connection_msg& other_) const;
    bool operator != (const connection_msg& other_) const;

    void swap(connection_msg& other_) noexcept ;

  private:

    std::string m_tele_id_;
    std::string m_vehicle_id_;

};

inline void swap(connection_msg& a, connection_msg& b)  noexcept 
{
    a.swap(b);
}

NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const connection_msg& sample);

class NDDSUSERDllExport disconnection_msg {
  public:

    disconnection_msg();

    explicit disconnection_msg(const std::string& msg_);

    std::string& msg() noexcept {
        return m_msg_;
    }

    const std::string& msg() const noexcept {
        return m_msg_;
    }

    void msg(const std::string& value) {

        m_msg_ = value;
    }

    void msg(std::string&& value) {
        m_msg_ = std::move(value);
    }
    bool operator == (const disconnection_msg& other_) const;
    bool operator != (const disconnection_msg& other_) const;

    void swap(disconnection_msg& other_) noexcept ;

  private:

    std::string m_msg_;

};

inline void swap(disconnection_msg& a, disconnection_msg& b)  noexcept 
{
    a.swap(b);
}

NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const disconnection_msg& sample);

class NDDSUSERDllExport partition_name {
  public:

    partition_name();

    explicit partition_name(const std::string& name_);

    std::string& name() noexcept {
        return m_name_;
    }

    const std::string& name() const noexcept {
        return m_name_;
    }

    void name(const std::string& value) {

        m_name_ = value;
    }

    void name(std::string&& value) {
        m_name_ = std::move(value);
    }
    bool operator == (const partition_name& other_) const;
    bool operator != (const partition_name& other_) const;

    void swap(partition_name& other_) noexcept ;

  private:

    std::string m_name_;

};

inline void swap(partition_name& a, partition_name& b)  noexcept 
{
    a.swap(b);
}

NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const partition_name& sample);

class NDDSUSERDllExport steeringWheel_data {
  public:

    steeringWheel_data();

    steeringWheel_data(int32_t lX_,int32_t lY_,int32_t lRz_,int32_t rglSlider_0_,uint32_t buttons_);

    int32_t& lX() noexcept {
        return m_lX_;
    }

    const int32_t& lX() const noexcept {
        return m_lX_;
    }

    void lX(int32_t value) {

        m_lX_ = value;
    }

    int32_t& lY() noexcept {
        return m_lY_;
    }

    const int32_t& lY() const noexcept {
        return m_lY_;
    }

    void lY(int32_t value) {

        m_lY_ = value;
    }

    int32_t& lRz() noexcept {
        return m_lRz_;
    }

    const int32_t& lRz() const noexcept {
        return m_lRz_;
    }

    void lRz(int32_t value) {

        m_lRz_ = value;
    }

    int32_t& rglSlider_0() noexcept {
        return m_rglSlider_0_;
    }

    const int32_t& rglSlider_0() const noexcept {
        return m_rglSlider_0_;
    }

    void rglSlider_0(int32_t value) {

        m_rglSlider_0_ = value;
    }

    uint32_t& buttons() noexcept {
        return m_buttons_;
    }

    const uint32_t& buttons() const noexcept {
        return m_buttons_;
    }

    void buttons(uint32_t value) {

        m_buttons_ = value;
    }

    bool operator == (const steeringWheel_data& other_) const;
    bool operator != (const steeringWheel_data& other_) const;

    void swap(steeringWheel_data& other_) noexcept ;

  private:

    int32_t m_lX_;
    int32_t m_lY_;
    int32_t m_lRz_;
    int32_t m_rglSlider_0_;
    uint32_t m_buttons_;

};

inline void swap(steeringWheel_data& a, steeringWheel_data& b)  noexcept 
{
    a.swap(b);
}

NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const steeringWheel_data& sample);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
// On Windows, dll-export template instantiations of standard types used by
// other dll-exported types
template class NDDSUSERDllExport std::allocator< int32_t >;
template class NDDSUSERDllExport std::vector< int32_t >;
#endif
class NDDSUSERDllExport joyStick_data {
  public:

    joyStick_data();

    joyStick_data(int32_t lX_,int32_t lZ_,int32_t lRx_,int32_t lRy_,int32_t lRz_,uint32_t buttons_,const ::rti::core::bounded_sequence< int32_t, 2L >& rglSlider_);

    int32_t& lX() noexcept {
        return m_lX_;
    }

    const int32_t& lX() const noexcept {
        return m_lX_;
    }

    void lX(int32_t value) {

        m_lX_ = value;
    }

    int32_t& lZ() noexcept {
        return m_lZ_;
    }

    const int32_t& lZ() const noexcept {
        return m_lZ_;
    }

    void lZ(int32_t value) {

        m_lZ_ = value;
    }

    int32_t& lRx() noexcept {
        return m_lRx_;
    }

    const int32_t& lRx() const noexcept {
        return m_lRx_;
    }

    void lRx(int32_t value) {

        m_lRx_ = value;
    }

    int32_t& lRy() noexcept {
        return m_lRy_;
    }

    const int32_t& lRy() const noexcept {
        return m_lRy_;
    }

    void lRy(int32_t value) {

        m_lRy_ = value;
    }

    int32_t& lRz() noexcept {
        return m_lRz_;
    }

    const int32_t& lRz() const noexcept {
        return m_lRz_;
    }

    void lRz(int32_t value) {

        m_lRz_ = value;
    }

    uint32_t& buttons() noexcept {
        return m_buttons_;
    }

    const uint32_t& buttons() const noexcept {
        return m_buttons_;
    }

    void buttons(uint32_t value) {

        m_buttons_ = value;
    }

    ::rti::core::bounded_sequence< int32_t, 2L >& rglSlider() noexcept {
        return m_rglSlider_;
    }

    const ::rti::core::bounded_sequence< int32_t, 2L >& rglSlider() const noexcept {
        return m_rglSlider_;
    }

    void rglSlider(const ::rti::core::bounded_sequence< int32_t, 2L >& value) {

        m_rglSlider_ = value;
    }

    void rglSlider(::rti::core::bounded_sequence< int32_t, 2L >&& value) {
        m_rglSlider_ = std::move(value);
    }
    bool operator == (const joyStick_data& other_) const;
    bool operator != (const joyStick_data& other_) const;

    void swap(joyStick_data& other_) noexcept ;

  private:

    int32_t m_lX_;
    int32_t m_lZ_;
    int32_t m_lRx_;
    int32_t m_lRy_;
    int32_t m_lRz_;
    uint32_t m_buttons_;
    ::rti::core::bounded_sequence< int32_t, 2L > m_rglSlider_;

};

inline void swap(joyStick_data& a, joyStick_data& b)  noexcept 
{
    a.swap(b);
}

NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const joyStick_data& sample);

class NDDSUSERDllExport streamdeck_buttons_data {
  public:

    streamdeck_buttons_data();

    explicit streamdeck_buttons_data(int16_t buttons_);

    int16_t& buttons() noexcept {
        return m_buttons_;
    }

    const int16_t& buttons() const noexcept {
        return m_buttons_;
    }

    void buttons(int16_t value) {

        m_buttons_ = value;
    }

    bool operator == (const streamdeck_buttons_data& other_) const;
    bool operator != (const streamdeck_buttons_data& other_) const;

    void swap(streamdeck_buttons_data& other_) noexcept ;

  private:

    int16_t m_buttons_;

};

inline void swap(streamdeck_buttons_data& a, streamdeck_buttons_data& b)  noexcept 
{
    a.swap(b);
}

NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const streamdeck_buttons_data& sample);

class NDDSUSERDllExport statistic_data {
  public:

    statistic_data();

    statistic_data(double height_,double depth_,int16_t auto_flag_);

    double& height() noexcept {
        return m_height_;
    }

    const double& height() const noexcept {
        return m_height_;
    }

    void height(double value) {

        m_height_ = value;
    }

    double& depth() noexcept {
        return m_depth_;
    }

    const double& depth() const noexcept {
        return m_depth_;
    }

    void depth(double value) {

        m_depth_ = value;
    }

    int16_t& auto_flag() noexcept {
        return m_auto_flag_;
    }

    const int16_t& auto_flag() const noexcept {
        return m_auto_flag_;
    }

    void auto_flag(int16_t value) {

        m_auto_flag_ = value;
    }

    bool operator == (const statistic_data& other_) const;
    bool operator != (const statistic_data& other_) const;

    void swap(statistic_data& other_) noexcept ;

  private:

    double m_height_;
    double m_depth_;
    int16_t m_auto_flag_;

};

inline void swap(statistic_data& a, statistic_data& b)  noexcept 
{
    a.swap(b);
}

NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const statistic_data& sample);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
// On Windows, dll-export template instantiations of standard types used by
// other dll-exported types
template class NDDSUSERDllExport std::allocator< double >;
template class NDDSUSERDllExport std::vector< double >;
#endif
class NDDSUSERDllExport IMU_data {
  public:

    IMU_data();

    IMU_data(const std::string& vin_,const ::rti::core::bounded_sequence< double, 3L >& acc_,const ::rti::core::bounded_sequence< double, 3L >& gyro_,const ::rti::core::bounded_sequence< double, 3L >& angle_,const ::rti::core::bounded_sequence< double, 3L >& mag_);

    std::string& vin() noexcept {
        return m_vin_;
    }

    const std::string& vin() const noexcept {
        return m_vin_;
    }

    void vin(const std::string& value) {

        m_vin_ = value;
    }

    void vin(std::string&& value) {
        m_vin_ = std::move(value);
    }
    ::rti::core::bounded_sequence< double, 3L >& acc() noexcept {
        return m_acc_;
    }

    const ::rti::core::bounded_sequence< double, 3L >& acc() const noexcept {
        return m_acc_;
    }

    void acc(const ::rti::core::bounded_sequence< double, 3L >& value) {

        m_acc_ = value;
    }

    void acc(::rti::core::bounded_sequence< double, 3L >&& value) {
        m_acc_ = std::move(value);
    }
    ::rti::core::bounded_sequence< double, 3L >& gyro() noexcept {
        return m_gyro_;
    }

    const ::rti::core::bounded_sequence< double, 3L >& gyro() const noexcept {
        return m_gyro_;
    }

    void gyro(const ::rti::core::bounded_sequence< double, 3L >& value) {

        m_gyro_ = value;
    }

    void gyro(::rti::core::bounded_sequence< double, 3L >&& value) {
        m_gyro_ = std::move(value);
    }
    ::rti::core::bounded_sequence< double, 3L >& angle() noexcept {
        return m_angle_;
    }

    const ::rti::core::bounded_sequence< double, 3L >& angle() const noexcept {
        return m_angle_;
    }

    void angle(const ::rti::core::bounded_sequence< double, 3L >& value) {

        m_angle_ = value;
    }

    void angle(::rti::core::bounded_sequence< double, 3L >&& value) {
        m_angle_ = std::move(value);
    }
    ::rti::core::bounded_sequence< double, 3L >& mag() noexcept {
        return m_mag_;
    }

    const ::rti::core::bounded_sequence< double, 3L >& mag() const noexcept {
        return m_mag_;
    }

    void mag(const ::rti::core::bounded_sequence< double, 3L >& value) {

        m_mag_ = value;
    }

    void mag(::rti::core::bounded_sequence< double, 3L >&& value) {
        m_mag_ = std::move(value);
    }
    bool operator == (const IMU_data& other_) const;
    bool operator != (const IMU_data& other_) const;

    void swap(IMU_data& other_) noexcept ;

  private:

    std::string m_vin_;
    ::rti::core::bounded_sequence< double, 3L > m_acc_;
    ::rti::core::bounded_sequence< double, 3L > m_gyro_;
    ::rti::core::bounded_sequence< double, 3L > m_angle_;
    ::rti::core::bounded_sequence< double, 3L > m_mag_;

};

inline void swap(IMU_data& a, IMU_data& b)  noexcept 
{
    a.swap(b);
}

NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const IMU_data& sample);

#ifdef NDDS_STANDALONE_TYPE
namespace rti { 
    namespace topic {
    }
}
#else

namespace rti {
    namespace flat {
        namespace topic {
        }
    }
}
namespace dds {
    namespace topic {

        template<>
        struct topic_type_name< ::tele_status > {
            NDDSUSERDllExport static std::string value() {
                return "tele_status";
            }
        };

        template<>
        struct is_topic_type< ::tele_status > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< ::tele_status > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const ::tele_status& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(::tele_status& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(::tele_status& sample);

            NDDSUSERDllExport 
            static void allocate_sample(::tele_status& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };
        template<>
        struct topic_type_name< ::vehicle_status > {
            NDDSUSERDllExport static std::string value() {
                return "vehicle_status";
            }
        };

        template<>
        struct is_topic_type< ::vehicle_status > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< ::vehicle_status > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const ::vehicle_status& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(::vehicle_status& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(::vehicle_status& sample);

            NDDSUSERDllExport 
            static void allocate_sample(::vehicle_status& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };
        template<>
        struct topic_type_name< ::connection_msg > {
            NDDSUSERDllExport static std::string value() {
                return "connection_msg";
            }
        };

        template<>
        struct is_topic_type< ::connection_msg > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< ::connection_msg > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const ::connection_msg& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(::connection_msg& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(::connection_msg& sample);

            NDDSUSERDllExport 
            static void allocate_sample(::connection_msg& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };
        template<>
        struct topic_type_name< ::disconnection_msg > {
            NDDSUSERDllExport static std::string value() {
                return "disconnection_msg";
            }
        };

        template<>
        struct is_topic_type< ::disconnection_msg > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< ::disconnection_msg > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const ::disconnection_msg& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(::disconnection_msg& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(::disconnection_msg& sample);

            NDDSUSERDllExport 
            static void allocate_sample(::disconnection_msg& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };
        template<>
        struct topic_type_name< ::partition_name > {
            NDDSUSERDllExport static std::string value() {
                return "partition_name";
            }
        };

        template<>
        struct is_topic_type< ::partition_name > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< ::partition_name > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const ::partition_name& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(::partition_name& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(::partition_name& sample);

            NDDSUSERDllExport 
            static void allocate_sample(::partition_name& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };
        template<>
        struct topic_type_name< ::steeringWheel_data > {
            NDDSUSERDllExport static std::string value() {
                return "steeringWheel_data";
            }
        };

        template<>
        struct is_topic_type< ::steeringWheel_data > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< ::steeringWheel_data > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const ::steeringWheel_data& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(::steeringWheel_data& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(::steeringWheel_data& sample);

            NDDSUSERDllExport 
            static void allocate_sample(::steeringWheel_data& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };
        template<>
        struct topic_type_name< ::joyStick_data > {
            NDDSUSERDllExport static std::string value() {
                return "joyStick_data";
            }
        };

        template<>
        struct is_topic_type< ::joyStick_data > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< ::joyStick_data > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const ::joyStick_data& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(::joyStick_data& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(::joyStick_data& sample);

            NDDSUSERDllExport 
            static void allocate_sample(::joyStick_data& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };
        template<>
        struct topic_type_name< ::streamdeck_buttons_data > {
            NDDSUSERDllExport static std::string value() {
                return "streamdeck_buttons_data";
            }
        };

        template<>
        struct is_topic_type< ::streamdeck_buttons_data > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< ::streamdeck_buttons_data > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const ::streamdeck_buttons_data& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(::streamdeck_buttons_data& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(::streamdeck_buttons_data& sample);

            NDDSUSERDllExport 
            static void allocate_sample(::streamdeck_buttons_data& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };
        template<>
        struct topic_type_name< ::statistic_data > {
            NDDSUSERDllExport static std::string value() {
                return "statistic_data";
            }
        };

        template<>
        struct is_topic_type< ::statistic_data > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< ::statistic_data > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const ::statistic_data& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(::statistic_data& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(::statistic_data& sample);

            NDDSUSERDllExport 
            static void allocate_sample(::statistic_data& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };
        template<>
        struct topic_type_name< ::IMU_data > {
            NDDSUSERDllExport static std::string value() {
                return "IMU_data";
            }
        };

        template<>
        struct is_topic_type< ::IMU_data > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< ::IMU_data > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const ::IMU_data& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(::IMU_data& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(::IMU_data& sample);

            NDDSUSERDllExport 
            static void allocate_sample(::IMU_data& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };
    }
}

namespace rti { 
    namespace topic {

        template<>
        struct dynamic_type< ::tele_status > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility< ::tele_status > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;    };

        template<>
        struct dynamic_type< ::vehicle_status > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility< ::vehicle_status > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;    };

        template<>
        struct dynamic_type< ::connection_msg > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility< ::connection_msg > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;    };

        template<>
        struct dynamic_type< ::disconnection_msg > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility< ::disconnection_msg > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;    };

        template<>
        struct dynamic_type< ::partition_name > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility< ::partition_name > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;    };

        template<>
        struct dynamic_type< ::steeringWheel_data > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility< ::steeringWheel_data > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;    };

        template<>
        struct dynamic_type< ::joyStick_data > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility< ::joyStick_data > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;    };

        template<>
        struct dynamic_type< ::streamdeck_buttons_data > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility< ::streamdeck_buttons_data > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;    };

        template<>
        struct dynamic_type< ::statistic_data > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility< ::statistic_data > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;    };

        template<>
        struct dynamic_type< ::IMU_data > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility< ::IMU_data > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;    };

    }
}

#endif // NDDS_STANDALONE_TYPE
#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif // data_1787947667_hpp

