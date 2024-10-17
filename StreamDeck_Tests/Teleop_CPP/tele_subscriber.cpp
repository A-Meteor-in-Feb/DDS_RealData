#include <algorithm>
#include <iostream>
#include <thread>
#include <future>

#include <dds/sub/ddssub.hpp>
#include <dds/core/ddscore.hpp>
#include <rti/config/Logger.hpp>
#include <rti/util/util.hpp>

#include "data.hpp"
#include "application.hpp"


void data_setter(const double& height_value, const double& depth_value, const int& flag_value);

void process_statistic_data(dds::sub::DataReader< ::statistic_data> reader, std::atomic<bool>& pub_begin){

    dds::sub::LoanedSamples< ::statistic_data> samples = reader.take();
    for (auto sample : samples) {
        if (sample.info().valid()) {
            data_setter(sample.data().height(), sample.data().depth(), sample.data().auto_flag());
            pub_begin = true;
            std::cout << sample.data() << std::endl;
        }
        else {
            pub_begin = false;
            std::cout << "Instance state changed to "
                << sample.info().state().instance_state() << std::endl;
        }
    }

}

void process_button_data(dds::sub::DataReader< ::streamdeck_buttons_data> reader) {
    
    dds::sub::LoanedSamples< ::streamdeck_buttons_data> samples = reader.take();
    for (auto sample : samples) {
        if (sample.info().valid()) {
            std::cout << sample.data() << std::endl;
        }
        else {
            std::cout << "Instance state changed to "
                << sample.info().state().instance_state() << std::endl;
        }
    }

}

void run_subscriber_application(std::string tin, std::atomic<bool>& pub_begin) {

    int domain_id = 0;

    dds::domain::DomainParticipant participant(domain_id);

    dds::topic::Topic< ::statistic_data> statistic_topic(participant, "statistic_data");
    dds::topic::Topic< ::streamdeck_buttons_data>  buttons_topic(participant, "streamdeck_buttons_data");

    dds::sub::Subscriber statistic_subscriber(participant);
    dds::sub::Subscriber buttons_subscriber(participant);

    dds::sub::DataReader< ::statistic_data> statistic_reader(statistic_subscriber, statistic_topic);
    dds::sub::DataReader< ::streamdeck_buttons_data> buttons_reader(buttons_subscriber, buttons_topic);

    dds::sub::cond::ReadCondition read_statistic_condition(
        statistic_reader,
        dds::sub::status::DataState::any(),
        [statistic_reader, &pub_begin]() {process_statistic_data(statistic_reader, pub_begin); });

    dds::sub::cond::ReadCondition read_buttons_condition(
        buttons_reader,
        dds::sub::status::DataState::any(),
        [buttons_reader]() {process_button_data(buttons_reader); });

    dds::core::cond::WaitSet waitset;
    waitset += read_statistic_condition;
    waitset += read_buttons_condition;

    while (!shutdown_requested) {
        waitset.dispatch(dds::core::Duration(1));
    }
}