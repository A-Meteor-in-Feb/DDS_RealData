# Integration


## Teleoperation Station Side
The entrance of the application: data_publisher.cxx
The command to run the application: objs/x64Win64VS2017/data_publisher.exe

### data_publisher.cxx
First, it creates a new window to initiliaze the controller and joystick. (According to the documentation of Logi... we need a new window side to invoke the initialization.)
Then, we use two threads to publish and subscribe different topics respectively.

### runPublisher.cpp
This program is modified to use based on Dogan's original codes.
It processes the corresponding button data from the controller and joyStick.
Also, it initializes the controller and joy stick devices.
In the end, it publishes the relevant data to the subscribers.
The frequency of publishing these topics is around 30 Hz (Sleep(33)).

### runSubscriber.cpp
This program is for subcription of data from Stream Deck (topic: statistic_data & button_data) and IMU sensor (topic: IMU_data).
The frequency of subscribing the statistic data of streamdeck is 100Hz (dds::core::Duration(0.01)).
The frequency of subscribing the IMU data is 20Hz (imu_waitset.dispatch(dds::core::Duration(0.05))) 1/0.05 = 20Hz.


## Vehicle Side
The entrance of the application: data_publisher.cxx
The commands to run the application:
    1. Windows: (D:\codes\DataFromAllDevices\INTEGRATION_GO\Vehicle_side)
        objs/x64Win64VS2017/data_publisher.cxx
    2. ssh-Sanat's Linux: (Documents\Integration_Test\)
        objs\x64Linux4gcc7.3.0\data_publisher
    3. ssh-Toyota's Linux: (rtidds\......)
        objs\armv8Linux4gcc7.3.0\data_publisher

### data_publisher.cxx
It creates two threads, and ... let the threads run respectively...

### runPublisher.cpp
Publish the data (topic: statistic_data) which will be shown on the streamdeck.
The frequency of sending the statistic data is 100Hz (dds::core::Duration(0.01)).

### runSubscriber.cpp
Subscribe the controller and joystick data comes from the teleoperation station side.
The frequency of reading these data is around 30Hz (waitset.dispatch(dds::core::Duration(33)) )


## Streamdeck Side
How to run the codes of this streamdeck ???
Click the green run button in Pycharm ...
How to quit this program ???
Press 'q' on the keyboard.

Thank you here for Dogan, because this program is complicated based on his original codes.

run_publisher() publishes the button data at frequency 1Hz (send every one second)
run_subscriber() subscribes the statictic_data at frequency OF 100Hz (waitset.dispatch(dds.Duration(0.01)))

---

## How to run cloud discovery service???

Step 1:

```shell
"C:\Program Files\rti_connext_dds-7.3.0\bin\rticlouddiscoveryservice.bat" -cfgFile D:\codes\hahaha\CloudDiscoverySservice\CDS4test.xml -cfgName CDS4test
```

Step 2:

In the USER_QOS_PROFILE.xml, add the following lines:

```xml
<domain_participant_qos>
    
	<!-- Cloud Discovery Service-->
    <transport_builtin>
        <mask>udpv4</mask>
    </transport_builtin>
    <discovery>
        <multicast_receive_addresses/>
        <initial_peers>
            <element>rtps@udpv4://192.168.0.167:7600</element>
        </initial_peers>
    </discovery>
    <!-- Cloud Discovery Service -->

</domain_participant_qos>
```

