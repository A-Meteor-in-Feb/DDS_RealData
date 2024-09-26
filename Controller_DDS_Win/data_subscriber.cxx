#include <algorithm>
#include <iostream>

#include <dds/sub/ddssub.hpp>
#include <dds/core/ddscore.hpp>
#include <rti/config/Logger.hpp>  // for logging

#include "data.hpp"
#include "application.hpp"  // for command line parsing and ctrl-c



void process_steeringWheel_data(dds::sub::DataReader< ::steeringWheel_data> reader){
    dds::sub::LoanedSamples< ::steeringWheel_data> samples = reader.take();

    for (auto sample : samples) {
        if (sample.info().valid()) {
            std::cout << sample.data() << std::endl;
        } else {
            std::cout << "Instance state changed to "
            << sample.info().state().instance_state() << std::endl;
        }
    }
} 


void process_joyStick_data(dds::sub::DataReader< ::joyStick_data> js_reader) {
    dds::sub::LoanedSamples< ::joyStick_data> samples = js_reader.take();

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


void run_subscriber_application(){ //unsigned int domain_id

    dds::domain::DomainParticipant participant(0);
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

    while (!application::shutdown_requested) {
        waitset.dispatch(dds::core::Duration(0.033)); //~30Hz
    }
}

int main(int argc, char *argv[])
{

    using namespace application;

    // Parse arguments and handle control-C
    auto arguments = parse_arguments(argc, argv);
    if (arguments.parse_result == ParseReturn::exit) {
        return EXIT_SUCCESS;
    } else if (arguments.parse_result == ParseReturn::failure) {
        return EXIT_FAILURE;
    }
    setup_signal_handlers();

    // Sets Connext verbosity to help debugging
    rti::config::Logger::instance().verbosity(arguments.verbosity);

    try {
        run_subscriber_application();
    } catch (const std::exception& ex) {
        // This will catch DDS exceptions
        std::cerr << "Exception in run_subscriber_application(): " << ex.what() << std::endl;
        return EXIT_FAILURE;
    }
    catch (...) {
        std::cerr << "Unknown Error :(" << std::endl;
        return EXIT_FAILURE;
    }

    dds::domain::DomainParticipant::finalize_participant_factory();

    return EXIT_SUCCESS;
}
