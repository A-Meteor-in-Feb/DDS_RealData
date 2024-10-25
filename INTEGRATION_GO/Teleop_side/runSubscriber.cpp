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


void process_statistic_data(dds::sub::DataReader< ::statistic_data> reader) {

    dds::sub::LoanedSamples< ::statistic_data> samples = reader.take();
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

void process_imu_data(dds::sub::DataReader< ::IMU_data> reader) {

    dds::sub::LoanedSamples< ::IMU_data> samples = reader.take();
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


void run_subscriber_application() {

    int domain_id = 0;

    dds::domain::DomainParticipant participant(domain_id);

    dds::topic::Topic< ::statistic_data> statistic_topic(participant, "statistic_data");
    dds::topic::Topic< ::streamdeck_buttons_data>  buttons_topic(participant, "streamdeck_buttons_data");
    dds::topic::Topic< ::IMU_data> topic(participant, "IMU_data");

    dds::sub::Subscriber statistic_subscriber(participant);
    dds::sub::Subscriber buttons_subscriber(participant);
    dds::sub::Subscriber imu_subscriber(participant);

    dds::sub::DataReader< ::statistic_data> statistic_reader(statistic_subscriber, statistic_topic);
    dds::sub::DataReader< ::streamdeck_buttons_data> buttons_reader(buttons_subscriber, buttons_topic);
    dds::sub::DataReader< ::IMU_data> imu_reader(imu_subscriber, topic);

    dds::sub::cond::ReadCondition read_statistic_condition(
        statistic_reader,
        dds::sub::status::DataState::any(),
        [statistic_reader]() { process_statistic_data(statistic_reader); });

    dds::sub::cond::ReadCondition read_buttons_condition(
        buttons_reader,
        dds::sub::status::DataState::any(),
        [buttons_reader]() { process_button_data(buttons_reader); });

    dds::sub::cond::ReadCondition read_imu_condition(
        imu_reader,
        dds::sub::status::DataState::any(),
        [imu_reader]() { process_imu_data(imu_reader); });

    dds::core::cond::WaitSet streamdeck_statistic_waitset;
    dds::core::cond::WaitSet streamdeck_button_waitset;
    dds::core::cond::WaitSet imu_waitset;

    streamdeck_statistic_waitset += read_statistic_condition;
    streamdeck_button_waitset += read_buttons_condition;
    imu_waitset += read_imu_condition;

    while (!shutdown_requested) {
        //Frequency for receiving data of streamdeck part.
        streamdeck_statistic_waitset.dispatch(dds::core::Duration(0.01));
        streamdeck_button_waitset.dispatch(dds::core::Duration(1));

        //Frequency of the imu part.
        imu_waitset.dispatch(dds::core::Duration(0.05));
    }
}