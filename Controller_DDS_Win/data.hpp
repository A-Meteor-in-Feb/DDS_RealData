

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from data.idl
using RTI Code Generator (rtiddsgen) version 4.3.0.
The rtiddsgen tool is part of the RTI Connext DDS distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the Code Generator User's Manual.
*/

#ifndef data_1787941111_hpp
#define data_1787941111_hpp

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

class NDDSUSERDllExport steeringWheel_data {
  public:

    steeringWheel_data();

    steeringWheel_data(const std::string& tin_,int32_t lX_,int32_t lY_,int32_t lRz_,int32_t rglSlider_0_,uint32_t buttons_);

    std::string& tin() noexcept {
        return m_tin_;
    }

    const std::string& tin() const noexcept {
        return m_tin_;
    }

    void tin(const std::string& value) {

        m_tin_ = value;
    }

    void tin(std::string&& value) {
        m_tin_ = std::move(value);
    }
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

    std::string m_tin_;
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

    joyStick_data(const std::string& tin_,int32_t lX_,int32_t lY_,int32_t lZ_,int32_t lRx_,int32_t lRy_,int32_t lRz_,uint32_t buttons_,const ::rti::core::bounded_sequence< int32_t, 2L >& rglSlider_);

    std::string& tin() noexcept {
        return m_tin_;
    }

    const std::string& tin() const noexcept {
        return m_tin_;
    }

    void tin(const std::string& value) {

        m_tin_ = value;
    }

    void tin(std::string&& value) {
        m_tin_ = std::move(value);
    }
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

    std::string m_tin_;
    int32_t m_lX_;
    int32_t m_lY_;
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
    }
}

namespace rti { 
    namespace topic {

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

    }
}

#endif // NDDS_STANDALONE_TYPE
#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif // data_1787941111_hpp

