#include <iostream>

#include <dds/pub/ddspub.hpp>
#include <rti/util/util.hpp>      // for sleep()
#include <rti/config/Logger.hpp>  // for logging

#include "application.hpp"  // for command line parsing and ctrl-c
#include "data.hpp"

#include "string.h"
#include "Math.h"
#include "windows.h"
#include "Com.h"

#include<stdio.h>
#include<conio.h>
#include "wit_c_sdk.h"

static char s_cDataUpdate = 0;
int iComPort = 4;
int iBaud = 9600;
int iAddress = 0x50;
void ComRxCallBack(char* p_data, UINT32 uiSize)
{
    for (UINT32 i = 0; i < uiSize; i++)
    {
        WitSerialDataIn(p_data[i]);
    }
}
static void AutoScanSensor(void);
static void SensorUartSend(uint8_t* p_data, uint32_t uiSize);
static void CopeSensorData(uint32_t uiReg, uint32_t uiRegNum);
static void DelayMs(uint16_t ms);


void run_publisher_application(unsigned int domain_id){

    float a[3], w[3], Angle[3], h[3];
    printf("Please enter the serial number:");
    scanf_s("%d", &iComPort);

    OpenCOMDevice(iComPort, iBaud);
    WitInit(WIT_PROTOCOL_NORMAL, 0x50);
    WitSerialWriteRegister(SensorUartSend);
    WitRegisterCallBack(CopeSensorData);
    AutoScanSensor();


    dds::domain::DomainParticipant participant(domain_id);

    dds::topic::Topic< ::IMU_data> topic(participant, "IMU_data");

    dds::pub::Publisher publisher(participant);

    dds::pub::DataWriter< ::IMU_data> writer(publisher, topic);

    ::IMU_data data;



    while (!application::shutdown_requested) {
        
        Sleep(1000);
        for (int i = 0; i < 3; i++){


            a[i] = (float)sReg[AX + i] / 32768.0f * 16.0f;
            w[i] = (float)sReg[GX + i] / 32768.0f * 2000.0f;
            Angle[i] = (float)sReg[Roll + i] / 32768.0f * 180.0f;
            h[i] = (float)sReg[HX + i];
        }
        printf("a:%.2f %.2f %.2f\r\n", a[0], a[1], a[2]);
        printf("w:%.2f %.2f %.2f\r\n", w[0], w[1], w[2]);
        printf("Angle:%.1f %.1f %.1f\r\n", Angle[0], Angle[1], Angle[2]);
        printf("h:%.0f %.0f %.0f\r\n\r\n", h[0], h[1], h[2]);
        
        data.acceleration({ a[0], a[1], a[2]});
        data.velocity({w[0], w[1], w[2]});
        data.angle({Angle[0], Angle[1], Angle[2]});
        data.magnetism({h[0], h[1], h[2]});

        writer.write(data);

        // Send once every second
        rti::util::sleep(dds::core::Duration(1));
    }
}

int main(int argc, char *argv[]){

    using namespace application;

    auto arguments = parse_arguments(argc, argv);
    if (arguments.parse_result == ParseReturn::exit) {
        return EXIT_SUCCESS;
    } else if (arguments.parse_result == ParseReturn::failure) {
        return EXIT_FAILURE;
    }
    setup_signal_handlers();

    rti::config::Logger::instance().verbosity(arguments.verbosity);

    try {
        run_publisher_application(arguments.domain_id);
    } catch (const std::exception& ex) {
        
        std::cerr << "Exception in run_publisher_application(): " << ex.what()
        << std::endl;
        return EXIT_FAILURE;
    }

    dds::domain::DomainParticipant::finalize_participant_factory();

    return EXIT_SUCCESS;
}


static void DelayMs(uint16_t ms)
{
    Sleep(ms);
}

static void SensorUartSend(uint8_t* p_data, uint32_t uiSize)
{
    SendUARTMessageLength((const char*)p_data, uiSize);
}
static void CopeSensorData(uint32_t uiReg, uint32_t uiRegNum)
{
    s_cDataUpdate = 1;
}

static void AutoScanSensor(void)
{
    const uint32_t c_uiBaud[7] = { 4800, 9600, 19200, 38400, 57600, 115200, 230400 };
    int i, iRetry;

    for (i = 0; i < 7; i++)
    {
        CloseCOMDevice();
        OpenCOMDevice(iComPort, c_uiBaud[i]);
        //SetBaundrate(c_uiBaud[i]);
        iRetry = 2;
        do
        {
            s_cDataUpdate = 0;
            WitReadReg(AX, 3);
            Sleep(100);
            if (s_cDataUpdate != 0)
            {
                printf("%d baud find sensor\r\n\r\n", c_uiBaud[i]);
                return;
            }
            iRetry--;
        } while (iRetry);
    }
    printf("can not find sensor\r\n");
    printf("please check your connection\r\n");
}
