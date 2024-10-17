#include <iostream>
#include <stdlib.h>

#include <dds/pub/ddspub.hpp>
#include <rti/util/util.hpp>      
#include <rti/config/Logger.hpp> 

#include "application.hpp"  
#include "data.hpp"

void run_publisher_application(){
    
    int domain_id = 0;

    dds::domain::DomainParticipant participant(domain_id);

    dds::pub::Publisher publisher(participant);

    dds::topic::Topic< ::statistic_data> topic(participant, "statistic_data");

    dds::pub::DataWriter< ::statistic_data> writer(publisher, topic);

    ::statistic_data data;
    
    int count = 0;

    while (!application::shutdown_requested) {

        count += 1;
        int auto_flag;

        if (count % 3 == 1) {
            auto_flag = 0;
        }
        else {
            auto_flag = 1;
        }

        srand(time(nullptr));

        data.height(rand()%10);
        data.depth(rand()%10);
        data.auto_flag(auto_flag);

        std::cout << "Writing ::statistic_data" << std::endl;

        writer.write(data);

        rti::util::sleep(dds::core::Duration(1));
    }
}

int main(int argc, char *argv[]){

    try {
        run_publisher_application();
    } catch (const std::exception& ex) {
        std::cerr << "Exception in run_publisher_application(): " << ex.what()
        << std::endl;
        return EXIT_FAILURE;
    }

    
    dds::domain::DomainParticipant::finalize_participant_factory();

    return EXIT_SUCCESS;
}
