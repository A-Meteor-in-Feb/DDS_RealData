

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from data.idl
using RTI Code Generator (rtiddsgen) version 4.3.0.
The rtiddsgen tool is part of the RTI Connext DDS distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the Code Generator User's Manual.
*/

#ifndef data_1787940864_hpp
#define data_1787940864_hpp

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
    }
}

namespace rti { 
    namespace topic {

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

    }
}

#endif // NDDS_STANDALONE_TYPE
#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif // data_1787940864_hpp

