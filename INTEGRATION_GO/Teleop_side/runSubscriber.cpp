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


void update_Recieved_text_display(std::string received_data);


void process_button_data(dds::sub::DataReader< ::streamdeck_buttons_data> reader) {

    dds::sub::LoanedSamples< ::streamdeck_buttons_data> samples = reader.take();
    for (auto sample : samples) {
        if (sample.info().valid()) {
            std::cout << sample.data() << std::endl;
            update_Recieved_text_display(std::to_string(sample.data().buttons()));
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
            update_Recieved_text_display(
                "\nData from IMU sensor : \nacc: \n\t" + std::to_string(sample.data().acc()[0]) +"\n\t" + std::to_string(sample.data().acc()[1]) + "\n\t" + std::to_string(sample.data().acc()[2]) +
                "\nangle: \n\t" + std::to_string(sample.data().angle()[0]) + "\n\t" + std::to_string(sample.data().angle()[1]) + "\n\t" + std::to_string(sample.data().angle()[2]) +
                "\nmag: \n\t" + std::to_string(sample.data().mag()[0]) + "\n\t" + std::to_string(sample.data().mag()[1]) + "\n\t" + std::to_string(sample.data().mag()[2]) +
                "\ngyro: \n\t" + std::to_string(sample.data().gyro()[0]) + "\n\t" + std::to_string(sample.data().gyro()[1]) + "\n\t" + std::to_string(sample.data().gyro()[2]));
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

    dds::topic::Topic< ::streamdeck_buttons_data>  buttons_topic(participant, "streamdeck_buttons_data");
    dds::topic::Topic< ::IMU_data> topic(participant, "IMU_data");

    dds::sub::Subscriber buttons_subscriber(participant);
    dds::sub::Subscriber imu_subscriber(participant);

    dds::sub::DataReader< ::streamdeck_buttons_data> buttons_reader(buttons_subscriber, buttons_topic);
    dds::sub::DataReader< ::IMU_data> imu_reader(imu_subscriber, topic);

    dds::sub::cond::ReadCondition read_buttons_condition(
        buttons_reader,
        dds::sub::status::DataState::any(),
       [buttons_reader]() { process_button_data(buttons_reader); });

    dds::sub::cond::ReadCondition read_imu_condition(
        imu_reader,
        dds::sub::status::DataState::any(),
        [imu_reader]() { process_imu_data(imu_reader); });


    dds::core::cond::WaitSet streamdeck_button_waitset;
    dds::core::cond::WaitSet imu_waitset;

    
    streamdeck_button_waitset += read_buttons_condition;
    imu_waitset += read_imu_condition;

    while (!shutdown_requested) {
        //Frequency for publishing data of streamdeck's buttons.
        streamdeck_button_waitset.dispatch(dds::core::Duration(1));

        //Frequency of the imu part.
        std::cout << "hello" << std::endl;
        imu_waitset.dispatch(dds::core::Duration(0.05));
    }
}