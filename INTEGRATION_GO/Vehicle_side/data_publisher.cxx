#include <iostream>

#include <dds/pub/ddspub.hpp>
#include <rti/util/util.hpp>      
#include <rti/config/Logger.hpp>  

#include "application.hpp" 
#include "data.hpp"

void run_publisher_application();
void run_subscriber_application();


int main(int argc, char *argv[]){

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
        std::thread vehicle_publisher(run_publisher_application);
        std::thread vehicle_subscriber(run_subscriber_application);

        vehicle_publisher.join();
        vehicle_subscriber.join();

    } catch (const std::exception& ex) {
        // This will catch DDS exceptions
        std::cerr << "Exception in run_publisher_application(): " << ex.what()
        << std::endl;
        return EXIT_FAILURE;
    }

    
    dds::domain::DomainParticipant::finalize_participant_factory();

    return EXIT_SUCCESS;
}
