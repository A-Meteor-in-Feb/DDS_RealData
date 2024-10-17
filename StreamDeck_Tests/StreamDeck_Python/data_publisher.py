import time
import sys
import rti.connextdds as dds
from data import statistic_data

class statistic_dataPublisher:

    @staticmethod
    def run_publisher(domain_id: int, sample_count: int):

        participant = dds.DomainParticipant(domain_id)

        topic = dds.Topic(participant, "statistic_data", statistic_data)

        writer = dds.DataWriter(participant.implicit_publisher, topic)

        sample = statistic_data()

        for count in range(sample_count):
            # Catch control-C interrupt
            try:
                # Modify the data to be sent here
                sample.auto_flag = count
                
                print(f"Writing statistic_data, count {count}")
                writer.write(sample)
                time.sleep(1)
            except KeyboardInterrupt:
                break

        print("preparing to shut down...")


if __name__ == "__main__":
    statistic_dataPublisher.run_publisher(
            domain_id=0,
            sample_count=sys.maxsize)
