
#include <algorithm>
#include <iostream>
#include <queue>
#include <typeinfo>
#include <utility>
#include <map>

#include <dds/pub/DataWriter.hpp>
#include <dds/pub/ddspub.hpp>
#include <dds/sub/ddssub.hpp>
#include <dds/core/ddscore.hpp>
#include <rti/config/Logger.hpp>  

#include "data.hpp"
#include "application.hpp" 
#include "TimeStampLogger.h"


std::vector<std::string> online_tele;
std::vector<std::string> online_vehicle;
std::map<std::string, std::string> con_te_ve;

int count_ConMsg_v = 0, count_ConMsg_t = 0;


void publish_known_msg(dds::domain::DomainParticipant& command_participant, dds::topic::Topic< ::connection_msg>& con_topic, const std::string& tele_id, const std::string& vehicle_id) {

	if (tele_id == "known") {
		dds::pub::qos::PublisherQos pub_qos;

		dds::core::StringSeq partition{ vehicle_id };
		pub_qos << dds::core::policy::detail::Partition(partition);

		dds::pub::Publisher command_con_publisher(command_participant, pub_qos);

		dds::core::QosProvider provider("ReliableQos.xml");
		auto writer_qos = provider.datawriter_qos("myqos::reliable_writer");

		dds::pub::DataWriter< ::connection_msg> con_topic_writer(command_con_publisher, con_topic, writer_qos);

		::connection_msg con_msg(tele_id, vehicle_id);

		con_topic_writer.write(con_msg);

		count_ConMsg_v += 1;
	}

	if (vehicle_id == "known") {

		dds::pub::qos::PublisherQos pub_qos;

		dds::core::StringSeq partition{ tele_id };
		pub_qos << dds::core::policy::detail::Partition(partition);

		dds::pub::Publisher command_con_publisher(command_participant, pub_qos);

		dds::core::QosProvider provider("ReliableQos.xml");
		auto writer_qos = provider.datawriter_qos("myqos::reliable_writer");

		dds::pub::DataWriter< ::connection_msg> con_topic_writer(command_con_publisher, con_topic, writer_qos);

		::connection_msg con_msg(tele_id, vehicle_id);

		con_topic_writer.write(con_msg);

		count_ConMsg_t += 1;

	}
}


void publish_connection_msg(dds::domain::DomainParticipant& command_participant, dds::topic::Topic< ::connection_msg>& con_topic, const std::string& tele_id, const std::string& vehicle_id, bool tele_again, bool vehicle_again) {

	if (!tele_again && !vehicle_again) {
		dds::pub::qos::PublisherQos pub_qos;

		dds::core::StringSeq partition{ tele_id, vehicle_id };
		pub_qos << dds::core::policy::detail::Partition(partition);

		dds::pub::Publisher command_con_publisher(command_participant, pub_qos);

		dds::core::QosProvider provider("ReliableQos.xml");
		auto writer_qos = provider.datawriter_qos("myqos::reliable_writer");

		dds::pub::DataWriter< ::connection_msg> con_topic_writer(command_con_publisher, con_topic, writer_qos);

		::connection_msg con_msg(tele_id, vehicle_id);

		con_topic_writer.write(con_msg);

		count_ConMsg_t += 1;
		count_ConMsg_v += 1;

	}
	else if (!tele_again && vehicle_again) {
		dds::pub::qos::PublisherQos pub_qos;

		dds::core::StringSeq partition{ vehicle_id };
		pub_qos << dds::core::policy::detail::Partition(partition);

		dds::pub::Publisher command_con_publisher(command_participant, pub_qos);

		dds::core::QosProvider provider("ReliableQos.xml");
		auto writer_qos = provider.datawriter_qos("myqos::reliable_writer");

		dds::pub::DataWriter< ::connection_msg> con_topic_writer(command_con_publisher, con_topic, writer_qos);

		::connection_msg con_msg(tele_id, vehicle_id);

		con_topic_writer.write(con_msg);

		count_ConMsg_v += 1;

	}
	else if (tele_again && !vehicle_again) {
		dds::pub::qos::PublisherQos pub_qos;

		dds::core::StringSeq partition{ tele_id };
		pub_qos << dds::core::policy::detail::Partition(partition);

		dds::pub::Publisher command_con_publisher(command_participant, pub_qos);

		dds::core::QosProvider provider("ReliableQos.xml");
		auto writer_qos = provider.datawriter_qos("myqos::reliable_writer");

		dds::pub::DataWriter< ::connection_msg> con_topic_writer(command_con_publisher, con_topic, writer_qos);

		::connection_msg con_msg(tele_id, vehicle_id);

		con_topic_writer.write(con_msg);

		count_ConMsg_t += 1;
	}
}


void judge_connection(dds::domain::DomainParticipant& command_participant, dds::topic::Topic< ::connection_msg>& con_topic) {

	int tele_num = online_tele.size();
	int vehicle_num = online_vehicle.size();

	while (tele_num && vehicle_num) {

		std::string usable_vehicle = online_vehicle.back();
		std::string usable_tele = online_tele.back();

		online_vehicle.pop_back();
		online_tele.pop_back();

		tele_num -= 1;
		vehicle_num -= 1;

		con_te_ve.insert(std::make_pair(usable_tele, usable_vehicle));
		con_te_ve.insert(std::make_pair(usable_vehicle, usable_tele));

		publish_connection_msg(command_participant, con_topic, usable_tele, usable_vehicle, false, false);
	}
}


void run_subscriber_application() {

	const std::string filename1 = "command_tele.txt";
	const std::string filename2 = "command_vehicle.txt";

	int command_domain = 0;

	dds::domain::DomainParticipant command_participant(command_domain);

	dds::topic::Topic< ::connection_msg> con_topic(command_participant, "connection_msg");
	dds::topic::Topic< ::disconnection_msg> discon_topic(command_participant, "disconnection_msg");

	dds::sub::Subscriber command_subscriber(command_participant);

	dds::topic::Topic< ::tele_status> tele_status_topic(command_participant, "tele_status");
	dds::topic::Topic< ::vehicle_status> vehicle_status_topic(command_participant, "vehicle_status");

	dds::sub::DataReader< ::tele_status> tele_status_reader(command_subscriber, tele_status_topic);
	dds::sub::DataReader< ::vehicle_status> vehicle_status_reader(command_subscriber, vehicle_status_topic);

	dds::sub::LoanedSamples< ::tele_status> tele_status_samples;
	dds::sub::LoanedSamples< ::vehicle_status> vehicle_status_samples;

	std::string timestamp;

	while (true) {

		tele_status_samples = tele_status_reader.take();

		if (tele_status_samples.length() > 0) {

			timestamp = TimestampLogger::getTimestamp();
			std::cout << "receive status msg from tele: " << timestamp << std::endl;

			dds::sub::LoanedSamples< ::tele_status>::const_iterator iter = tele_status_samples.begin();

			const ::tele_status& data = iter->data();
			const dds::sub::SampleInfo& info = iter->info();

			if (info.valid()) {

				std::cout << "\ntele_status data:    " << data << std::endl;

				std::string tele_id = data.tele_id();

				std::string tele_state = data.connected() ? "conneccted" : "online";


				if (tele_state == "online" && con_te_ve.count(tele_id) == 0) {
					bool usable = true;

					for (int i = 0; i < online_tele.size(); i++) {
						if (online_tele.at(i) == tele_id) {
							usable = false;
							break;
						}
					}

					if (usable) {
						publish_known_msg(command_participant, con_topic, tele_id, "known");
						timestamp = TimestampLogger::getTimestamp();
						//TimestampLogger::writeToFile(filename1, timestamp);
						online_tele.push_back(tele_id);
						std::cout << "Publish connection msg to tele: " << timestamp << std::endl;
					}
				}
				else if (tele_state == "online" && con_te_ve.count(tele_id)) {
					publish_connection_msg(command_participant, con_topic, tele_id, con_te_ve[tele_id], true, false);
					std::string timestamp = TimestampLogger::getTimestamp();
					//TimestampLogger::writeToFile(filename1, timestamp);
					std::cout << "publish connection msg to tele: " << timestamp << std::endl;
				}
			}
			
		}

		vehicle_status_samples = vehicle_status_reader.take();

		if (vehicle_status_samples.length() > 0) {
			timestamp = TimestampLogger::getTimestamp();
			std::cout << "receive status msg from vehicle: " << timestamp << std::endl;


			dds::sub::LoanedSamples< ::vehicle_status>::const_iterator iter = vehicle_status_samples.begin();
			/*for (iter = vehicle_status_samples.begin(); iter < vehicle_status_samples.end(); ++iter) {

				const ::vehicle_status& data = iter->data();
				const dds::sub::SampleInfo& info = iter->info();

				if (info.valid()) {

					std::string vehicle_id = data.vehicle_id();

					std::string vehicle_state = data.connected() ? "connected" : "online";


					if (vehicle_state == "online" && con_te_ve.count(vehicle_id) == 0) {
						bool usable = true;

						for (int i = 0; i < online_vehicle.size(); i++) {
							if (online_vehicle.at(i) == vehicle_id) {
								publish_known_msg(command_participant, con_topic, "known", vehicle_id);
								usable = false;
								break;
							}
						}

						if (usable) {
							std::cout << "here 1 - know vehicle" << std::endl;
							publish_known_msg(command_participant, con_topic, "known", vehicle_id);
							timestamp = TimestampLogger::getTimestamp();
							//TimestampLogger::writeToFile(filename2, timestamp);
							std::cout << "publish connection msg to vehicle: " << timestamp << std::endl;
							online_vehicle.push_back(vehicle_id);
						}
					}
					else if (vehicle_state == "online" && con_te_ve.count(vehicle_id)) {
						std::cout << "here 2 - resend connection msg" << std::endl;
						publish_connection_msg(command_participant, con_topic, con_te_ve[vehicle_id], vehicle_id, false, true);
						timestamp = TimestampLogger::getTimestamp();
						//TimestampLogger::writeToFile(filename2, timestamp);
						std::cout << "publish connection msg to vehicle: " << timestamp << std::endl;
					}


				}

			}*/
		}

		if (online_tele.size() > 0 && online_vehicle.size() > 0) {
			std::cout << "there are suitable pairs" << std::endl;
			judge_connection(command_participant, con_topic);
			std::string timestamp = TimestampLogger::getTimestamp();
			//TimestampLogger::writeToFile(filename1, timestamp);
			//TimestampLogger::writeToFile(filename2, timestamp);
			std::cout << "publish connection msg to tele: " << timestamp << std::endl;
			std::cout << "publish connection msg to vehicle: " << timestamp << std::endl;
		}

		
	}

	std::cout << "Preparing to shutdown ..." << std::endl;
	std::cout << "Totally sent connection msg to vehicle side: " << count_ConMsg_v << std::endl;
	std::cout << "Totally sent connection msg to teleop side: " << count_ConMsg_t << std::endl;

}

int main(int argc, char* argv[]) {


	try {
		run_subscriber_application();
	}
	catch (const std::exception& ex) {
		std::cerr << "Exception in run_subscriber_application(): " << ex.what() << std::endl;
		return EXIT_FAILURE;
	}


	dds::domain::DomainParticipant::finalize_participant_factory();

	return EXIT_SUCCESS;
}
