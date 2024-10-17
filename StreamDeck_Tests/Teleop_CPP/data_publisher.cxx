#include <iostream>

#include <dds/pub/ddspub.hpp>
#include <rti/util/util.hpp>     
#include <rti/config/Logger.hpp> 

#include "data.hpp"

void run_publisher_application(){
    
    dds::domain::DomainParticipant participant(0);

    dds::topic::Topic< ::statistic_data> topic(participant, "Example statistic_data");

    dds::pub::Publisher publisher(participant);

    dds::pub::DataWriter< ::statistic_data> writer(publisher, topic);

    ::statistic_data data;
    
   while(true){
        
        data.auto_flag(static_cast< int16_t>(1));
        std::cout << "Writing ::statistic_data" << std::endl;

        writer.write(data);

        rti::util::sleep(dds::core::Duration(1));
    }
}

int main(int argc, char *argv[])
{

    run_publisher_application();
    dds::domain::DomainParticipant::finalize_participant_factory();

    return EXIT_SUCCESS;
}
