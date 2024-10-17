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

void run_subscriber_application(std::string tin, std::atomic<bool>& pub_begin);
void run_publisher_application(std::string tin, std::atomic<bool>& pub_begin);

int main(int argc, char *argv[]){

    //using namespace application;

    auto arguments = parse_arguments(argc, argv);
    if (arguments.parse_result == ParseReturn::exit) {
        return EXIT_SUCCESS;
    } else if (arguments.parse_result == ParseReturn::failure) {
        return EXIT_FAILURE;
    }
    setup_signal_handlers();

    // Sets Connext verbosity to help debugging
    rti::config::Logger::instance().verbosity(arguments.verbosity);

    if (!shutdown_requested) {

        std::atomic<bool> pub_begin = false;

        int tele_id = arguments.sample_count;
        std::string tin = "tele" + std::to_string(tele_id);
        std::thread thread_sub(run_subscriber_application, tin, std::ref(pub_begin));
        //std::thread thread_pub(run_publisher_application, tin, std::ref(pub_begin));

        thread_sub.join();
        //thread_pub.join();

    }

    
    dds::domain::DomainParticipant::finalize_participant_factory();

    return EXIT_SUCCESS;
}
