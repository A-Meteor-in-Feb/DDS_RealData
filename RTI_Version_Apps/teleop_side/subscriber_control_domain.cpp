#include <string>
#include <iostream>
#include <thread>
#include <chrono>

#include <dds/pub/ddspub.hpp>
#include <dds/sub/ddssub.hpp>
#include <rti/util/util.hpp>      
#include <rti/config/Logger.hpp>  

#include "application.hpp"  
#include "data.hpp"
#include "partitionName.hpp"
#include "TimeStampLogger.h"


void subscriber_control_domain(int& tele, std::string& control_partition_name) {

	std::string filename1 = "tele_imu.txt";
	std::string filename2 = "tele_streamdeckButtons.txt";

	std::string name = control_partition_name;
	std::cout << "start running subscriber, partition: " << name << std::endl;

	std::string streamdeck_name = "streamdeck_tele" + std::to_string(tele);

	int control_domain = 1;

	dds::domain::DomainParticipant control_participant(control_domain);

	dds::sub::qos::SubscriberQos sub_qos;

	dds::core::StringSeq partition_name{ name };

	sub_qos << dds::core::policy::Partition(partition_name);

	dds::sub::Subscriber tele_subscriber(control_participant, sub_qos);

	dds::topic::Topic< ::streamdeck_buttons_data> buttons_topic(control_participant, "streamdeck_buttons_data");
	dds::topic::Topic< ::IMU_data> imu_topic(control_participant, "imu_data");

	dds::sub::DataReader< ::streamdeck_buttons_data> buttons_reader(tele_subscriber, buttons_topic);
	dds::sub::DataReader< ::IMU_data> imu_reader(tele_subscriber, imu_topic);

	dds::sub::LoanedSamples< ::streamdeck_buttons_data> buttons_samples;
	dds::sub::LoanedSamples< ::IMU_data> imu_samples;

	bool connected_sd = false;
	dds::pub::qos::PublisherQos pub_qos_sd;
	dds::core::StringSeq partition_name_sd{ streamdeck_name };
	pub_qos_sd << dds::core::policy::Partition(partition_name_sd);
	dds::pub::Publisher teleSd_publisher(control_participant, pub_qos_sd);

	dds::topic::Topic< ::partition_name> partiton_topic(control_participant, "partition_data");
	dds::pub::DataWriter< ::partition_name> partition_writer(teleSd_publisher, partiton_topic);


	while (!shutdown_requested) {

		// RECEIVE AND TAKE THE DATA SAMPLE
		buttons_samples = buttons_reader.take();

		if (buttons_samples.length() > 0) {

			std::string timestamp = TimestampLogger::getTimestamp();
			TimestampLogger::writeToFile(filename2, timestamp);

			dds::sub::LoanedSamples< ::streamdeck_buttons_data>::const_iterator iter;
			for (iter = buttons_samples.begin(); iter < buttons_samples.end(); ++iter) {

				const ::streamdeck_buttons_data& data = iter->data();
				const dds::sub::SampleInfo& info = iter->info();

				if (info.valid()) {
					connected_sd = true;
					std::cout << "streamdeck_buttons_data: " << data << std::endl;

				}

			}
		}
		else if (!connected_sd) {
			::partition_name data(name);
			partition_writer.write(data);
		}

		imu_samples = imu_reader.take();

		if (imu_samples.length() > 0) {

			std::string timestamp = TimestampLogger::getTimestamp();
			TimestampLogger::writeToFile(filename1, timestamp);

			dds::sub::LoanedSamples< ::IMU_data>::const_iterator iter;
			for (iter = imu_samples.begin(); iter < imu_samples.end(); ++iter) {

				const ::IMU_data& data = iter->data();
				const dds::sub::SampleInfo& info = iter->info();

				if (info.valid()) {
					std::cout << "imu_data: " << data << std::endl;

				}

			}
		}

	}
}