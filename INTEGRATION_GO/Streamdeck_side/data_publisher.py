
# (c) Copyright, Real-Time Innovations, 2022.  All rights reserved.
# RTI grants Licensee a license to use, modify, compile, and create derivative
# works of the software solely for use with RTI Connext DDS. Licensee may
# redistribute copies of the software provided that all such copies are subject
# to this license. The software is provided "as is", with no warranty of any
# type, including any warranty for fitness for any purpose. RTI is under no
# obligation to maintain or support the software. RTI shall not be liable for
# any incidental or consequential damages arising out of the use or inability
# to use the software.

import time
import sys
import rti.connextdds as dds
from data import IMU_data

class IMU_dataPublisher:

    @staticmethod
    def run_publisher(domain_id: int, sample_count: int):

        # A DomainParticipant allows an application to begin communicating in
        # a DDS domain. Typically there is one DomainParticipant per application.
        # DomainParticipant QoS is configured in USER_QOS_PROFILES.xml
        participant = dds.DomainParticipant(domain_id)

        # A Topic has a name and a datatype.
        topic = dds.Topic(participant, "Example IMU_data", IMU_data)

        # This DataWriter will write data on Topic "Example IMU_data"
        # DataWriter QoS is configured in USER_QOS_PROFILES.xml
        writer = dds.DataWriter(participant.implicit_publisher, topic)
        sample = IMU_data()        

        for count in range(sample_count):
            # Catch control-C interrupt
            try:
                # Modify the data to be sent here
                
                print(f"Writing IMU_data, count {count}")
                writer.write(sample)
                time.sleep(1)
            except KeyboardInterrupt:
                break

        print("preparing to shut down...")


if __name__ == "__main__":
    IMU_dataPublisher.run_publisher(
            domain_id=0,
            sample_count=sys.maxsize)
