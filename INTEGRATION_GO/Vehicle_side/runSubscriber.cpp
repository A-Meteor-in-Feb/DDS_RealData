#include <algorithm>
#include <iostream>

#include <dds/sub/ddssub.hpp>
#include <dds/core/ddscore.hpp>
#include <rti/config/Logger.hpp>

#include "data.hpp"
#include "application.hpp"



void process_steeringWheel_data(dds::sub::DataReader< ::steeringWheel_data> reader) {
    dds::sub::LoanedSamples< ::steeringWheel_data> samples = reader.take();

    for (auto sample : samples) {
        if (sample.info().valid()) {
            std::cout << "============================SteeringWheel Data============================" << std::endl;
            std::cout << "SteeringWheel lX: " << sample.data().lX() << std::endl;
            std::cout << "SteeringWheel lY: " << sample.data().lY() << std::endl;
            std::cout << "SteeringWheel lRz: " << sample.data().lRz() << std::endl;
            std::cout << "SteeringWheel rglSlider_0: " << sample.data().rglSlider_0() << std::endl;
            std::cout << "SteeringWheel buttons: " << sample.data().buttons() << std::endl;
        }
        else {
            std::cout << "Instance state changed to "
                << sample.info().state().instance_state() << std::endl;
        }
    }
}


void process_joyStick_data(dds::sub::DataReader< ::joyStick_data> js_reader) {
    dds::sub::LoanedSamples< ::joyStick_data> samples = js_reader.take();

    for (auto sample : samples) {
        if (sample.info().valid()) {
            std::cout << "============================JoyStick Data============================" << std::endl;
            std::cout << "JoyStick lX: " << sample.data().lX() << std::endl;
            std::cout << "JoyStick lY: " << sample.data().lY() << std::endl;
            std::cout << "JoyStick lZ: " << sample.data().lZ() << std::endl;
            std::cout << "JoyStick lRx: " << sample.data().lRx() << std::endl;
            std::cout << "JoyStick lRy: " << sample.data().lRy() << std::endl;
            std::cout << "JoyStick lRz: " << sample.data().lRz() << std::endl;
            std::cout << "JoyStick rglSliders: " << sample.data().rglSlider() << std::endl;
            std::cout << "JoyStick buttons: " << sample.data().buttons() << std::endl;
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

    dds::sub::Subscriber vehicle_subscriber(participant);

    dds::topic::Topic< ::steeringWheel_data> steeringWheel_topic(participant, "steeringWheel_topic");
    dds::topic::Topic< ::joyStick_data> joyStick_topic(participant, "joyStick_topic");

    dds::sub::DataReader< ::steeringWheel_data> steeringWheel_reader(vehicle_subscriber, steeringWheel_topic);
    dds::sub::DataReader< ::joyStick_data> joyStick_reader(vehicle_subscriber, joyStick_topic);

    dds::sub::cond::ReadCondition sw_read_condition(
        steeringWheel_reader,
        dds::sub::status::DataState::any(),
        [steeringWheel_reader]() { process_steeringWheel_data(steeringWheel_reader); });

    dds::sub::cond::ReadCondition js_read_condition(
        joyStick_reader,
        dds::sub::status::DataState::any(),
        [joyStick_reader]() { process_joyStick_data(joyStick_reader); });

    // WaitSet will be woken when the attached condition is triggered
    dds::core::cond::WaitSet waitset;
    waitset += sw_read_condition;
    waitset += js_read_condition;

    while (!shutdown_requested) {
        waitset.dispatch(dds::core::Duration(0.033)); //~30Hz
        //waitset.dispatch(dds::core::Duration(10)); 
    }
}
