#include <iostream>
#include <thread>
#include <future>

#include <dds/pub/ddspub.hpp>
#include <rti/util/util.hpp>      
#include <rti/config/Logger.hpp> 

#include "application.hpp" 
#include "data.hpp"


double height;
double depth;
int auto_flag;

void data_setter(const double& height_value, const double& depth_value, const int& flag_value) {
    height = height_value;
    depth = depth_value;
    auto_flag = flag_value;
}

void run_publisher_application(std::string tin, std::atomic<bool>& pub_begin){

    int domain_id = 0;

    dds::domain::DomainParticipant participant(domain_id);

    dds::topic::Topic< ::statistic_data> topic(participant, "statistic_data");

    dds::pub::Publisher publisher(participant);

    dds::pub::DataWriter< ::statistic_data> writer(publisher, topic);

    ::statistic_data data;
    

    while (!application::shutdown_requested && pub_begin.load()) {

        data.height(height);
        data.depth(depth);
        data.auto_flag(auto_flag);

        std::cout << "Writing statistic_data " << std::endl;

        writer.write(data);

        rti::util::sleep(dds::core::Duration(1));
    }
}
