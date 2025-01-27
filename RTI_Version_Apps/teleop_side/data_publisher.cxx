
#include <iostream>

#include <dds/pub/ddspub.hpp>
#include <dds/sub/ddssub.hpp>
#include <rti/util/util.hpp>      
#include <rti/config/Logger.hpp>  

#include "application.hpp"  
#include "data.hpp"
#include "partitionName.hpp"
#include "TimeStampLogger.h"


void publisher_control_domain(int& tele, std::string& partition_name);
//void subscriber_control_domain(int& tele, std::string& partition_name);

int count_ConMsg = 0;


int run_command_domain(int& tele){

    //const std::string filename = "tele_connection_msg.txt";

    std::string tele_id = "tele" + std::to_string(tele);
    bool online_state = true;
    bool connected_state = false;

    partitionName control_partition_name;

    int command_domain = 0;

    dds::domain::DomainParticipant command_participant(command_domain);
     
    //====== PUBLISHER ======
    dds::pub::Publisher command_publisher(command_participant);
    dds::topic::Topic< ::tele_status> status_topic(command_participant, "tele_status");
    dds::pub::DataWriter< ::tele_status> status_writer(command_publisher, status_topic);

    
    //====== SUBSCRIBER ======
    dds::sub::qos::SubscriberQos sub_qos;
    dds::core::StringSeq partition_name{ tele_id };
    sub_qos << dds::core::policy::Partition(partition_name);

    dds::sub::Subscriber command_subscriber(command_participant, sub_qos);

    dds::core::QosProvider provider("ReliableQos.xml", "myqos::reliable_reader");
    auto reader_qos = provider.datareader_qos();

    dds::topic::Topic< ::connection_msg> con_topic(command_participant, "connection_msg");

    dds::sub::DataReader< ::connection_msg> con_reader(command_subscriber, con_topic, reader_qos);

    dds::sub::LoanedSamples< ::connection_msg> con_samples;

    std::atomic<bool> known{ false };
    std::atomic<bool> conducted{ false };
    std::string timestamp;

    while (true) {

        con_samples = con_reader.take();

        if (con_samples.length() > 0) {

            timestamp = TimestampLogger::getTimestamp();
            //TimestampLogger::writeToFile(filename, timestamp);
            std::cout << "receive connection msg at: " << timestamp << std::endl;

            dds::sub::LoanedSamples< ::connection_msg>::const_iterator iter = con_samples.begin();

            const ::connection_msg& data = iter->data();
            const dds::sub::SampleInfo& info = iter->info();

            if (info.valid()) {

                count_ConMsg += 1;

                std::string vehicle_id = data.vehicle_id();

                if (vehicle_id == "known") {

                    known.store(true);
                    std::cout << "non-matched vehicle for now ..." << std::endl;

                }
                else {
                    std::cout << "match to vehicle: " << vehicle_id << std::endl;

                    online_state = true;
                    connected_state = true;
                    ::tele_status tele_status_data(tele_id, online_state, connected_state);
                    status_writer.write(tele_status_data);

                    std::string name = data.tele_id() + data.vehicle_id();

                    std::cout << "partition name: " << name << std::endl;


                    std::thread tele_control_publisher(publisher_control_domain, std::ref(tele), std::ref(name));
                    //std::thread tele_control_subscriber(subscriber_control_domain, std::ref(tele), std::ref(name));

                    tele_control_publisher.join();
                    //tele_control_subscriber.join();

                    conducted.store(true);
                }
            }
        }
        else if (!known.load()) {
            ::tele_status tele_status_data(tele_id, online_state, connected_state);
            status_writer.write(tele_status_data);
            timestamp = TimestampLogger::getTimestamp();
            std::cout << "publish status msg at: " << timestamp << std::endl;
            std::this_thread::sleep_for(std::chrono::microseconds(3000000));
        }

        if (conducted.load()) {
            std::cout << "preparing shutdown ..." << std::endl;
            break;
        }
    }

    std::cout << "Totally received connection msg from the command center: " << count_ConMsg << std::endl;
    std::cout << "From teleop side, totally 200 controller messages are sent." << std::endl;

    return 1;
}

int main(int argc, char *argv[]){

    int tele = -1;

    if (argc > 2 && strcmp(argv[1], "-id") == 0) {
        tele = atoi(argv[2]);
    }

    try {
        run_command_domain(std::ref(tele));

    } catch (const std::exception& ex) {
       
        std::cerr << "Exception in run_command_domain(): " << ex.what() << std::endl;
        return EXIT_FAILURE;
    }


    dds::domain::DomainParticipant::finalize_participant_factory();

    return EXIT_SUCCESS;
}
