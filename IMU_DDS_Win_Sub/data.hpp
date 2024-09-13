

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from data.idl
using RTI Code Generator (rtiddsgen) version 4.3.0.
The rtiddsgen tool is part of the RTI Connext DDS distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the Code Generator User's Manual.
*/

#ifndef data_1787939817_hpp
#define data_1787939817_hpp

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

#endif // data_1787939817_hpp

