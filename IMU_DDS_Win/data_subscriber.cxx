
#include <algorithm>
#include <iostream>

#include <dds/sub/ddssub.hpp>
#include <dds/core/ddscore.hpp>
#include <rti/config/Logger.hpp>  // for logging

#include "data.hpp"
#include "application.hpp"  // for command line parsing and ctrl-c

int process_data(dds::sub::DataReader< ::IMU_data> reader){

    int count = 0;
    dds::sub::LoanedSamples< ::IMU_data> samples = reader.take();
    for (auto sample : samples) {
        if (sample.info().valid()) {
            count++;
            std::cout << sample.data() << std::endl;
        } else {
            std::cout << "Instance state changed to "<< sample.info().state().instance_state() << std::endl;
        }
    }

    return count; 
} // The LoanedSamples destructor returns the loan

void run_subscriber_application(unsigned int domain_id){

    dds::domain::DomainParticipant participant(domain_id);

    dds::topic::Topic< ::IMU_data> topic(participant, "IMU_data");

    dds::sub::Subscriber subscriber(participant);
    dds::sub::DataReader< ::IMU_data> reader(subscriber, topic);

    unsigned int samples_read = 0;
    dds::sub::cond::ReadCondition read_condition(
        reader,
        dds::sub::status::DataState::any(),
        [reader, &samples_read]() { samples_read += process_data(reader); });

    dds::core::cond::WaitSet waitset;
    waitset += read_condition;

    while (!application::shutdown_requested) {
        std::cout << "::IMU_data subscriber sleeping up to 1 sec..." << std::endl;

        waitset.dispatch(dds::core::Duration(1));
    }
}

int main(int argc, char *argv[]){

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
        run_subscriber_application(arguments.domain_id);
    } catch (const std::exception& ex) {
        std::cerr << "Exception in run_subscriber_application(): " << ex.what() << std::endl;
        return EXIT_FAILURE;
    }

    dds::domain::DomainParticipant::finalize_participant_factory();

    return EXIT_SUCCESS;
}
