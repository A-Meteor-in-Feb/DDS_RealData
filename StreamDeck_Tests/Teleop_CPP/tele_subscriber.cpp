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


void data_setter(const double& height_value, const double& depth_value, const int& flag_value);

void process_data(dds::sub::DataReader< ::statistic_data> reader){

    dds::sub::LoanedSamples< ::statistic_data> samples = reader.take();
    for (auto sample : samples) {
        if (sample.info().valid()) {
            data_setter(sample.data().height(), sample.data().depth(), sample.data().auto_flag());

            std::cout << sample.data() << std::endl;
        }
        else {
            std::cout << "Instance state changed to "
                << sample.info().state().instance_state() << std::endl;
        }
    }

}

void run_subscriber_application(std::string tin, std::atomic<bool>& pub_begin) {

    int domain_id = 0;

    dds::domain::DomainParticipant participant(domain_id);

    dds::topic::Topic< ::statistic_data> topic(participant, "statistic_data");

    dds::sub::Subscriber subscriber(participant);
    dds::sub::DataReader< ::statistic_data> reader(subscriber, topic);

    unsigned int samples_read = 0;
    dds::sub::cond::ReadCondition read_condition(
        reader,
        dds::sub::status::DataState::any(),
        [reader]() {process_data(reader); });

    dds::core::cond::WaitSet waitset;
    waitset += read_condition;

    while (!application::shutdown_requested) {
        std::cout << "::statistic_data subscriber sleeping up to 1 sec..." << std::endl;

        waitset.dispatch(dds::core::Duration(1));
    }
}