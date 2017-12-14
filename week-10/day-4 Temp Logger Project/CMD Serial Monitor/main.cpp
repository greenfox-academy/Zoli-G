#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <conio.h>
#include <time.h>

#include "SerialPortWrapper.h"

void OpenPort(SerialPortWrapper* serial, bool* isPortOpen);
void ClosePort(SerialPortWrapper* serial, bool* isPortOpen);
void ConvertToUNIXTimeStamp(string data);

using namespace std;

int main() {
	//Main menu's "global" variables
    SerialPortWrapper* serial = new SerialPortWrapper("COM1", 115200);  //Serial port object
    bool isPortOpen = false;

    //Port counting: let's print out how many COM ports are on the PC
    vector<string> ports = SerialPortWrapper::listAvailablePorts();
    cout << "Number of serial ports found: " << ports.size() << endl;
    for (unsigned int i = 0; i < ports.size(); i++) {
        cout << "\tPort name: " << ports.at(i) << endl;
    }
    //If there's no COM ports, it means the STM32 is also not connected, let's terminate the program
    if (ports.size() == 0) {
        cout << "Device not connected, program terminates." << endl;
        exit(0);
    }

    OpenPort(serial, &isPortOpen);

    string line;
    char keypressed;

    cout << "Printing Serial Data... press ESC to exit:" << endl;
    while(1){
        serial->readLineFromPort(&line);
        if (line.length() > 0){
            cout << line << endl;
            ConvertToUNIXTimeStamp(line);
        }
        if (kbhit() && (keypressed = getch(), keypressed == 27)) break;
    }
}
//--------------------------------------------------------------------------------------------------
void OpenPort(SerialPortWrapper* serial, bool* isPortOpen) {
    if (*isPortOpen == true) {
        cout << "Port already open." << endl;
        return;
    }
    cout << "Opening port... ";
    serial->openPort();
    *isPortOpen = true;
    cout << "opened." << endl;
}
//--------------------------------------------------------------------------------------------------
void ClosePort(SerialPortWrapper* serial, bool* isPortOpen) {
    if (*isPortOpen == false) {
        cout << "Port already closed." << endl;
        return;
    }
    cout << "Closing port... ";
    serial->closePort();
    *isPortOpen = false;
    cout << "closed." << endl;
}

void ConvertToUNIXTimeStamp(string data) {
    unsigned int year, month, day, hour, minute, sec;
    signed int temp;

    char _year[] = {data[0], data[1], data[2], data[3], '\0'};
    year = atoi(_year);

    char _month[] = {data[5], data[6], '\0'};
    month= atoi(_month);

    char _day[] = {data[8], data[9], '\0'};
    day = atoi(_day);

    char _hour[] = {data[11], data[12], '\0'};
    hour = atoi(_hour);

    char _minute[] = {data[14], data[15], '\0'};
    minute = atoi(_minute);

    char _sec[] = {data[17], data[18], '\0'};
    sec = atoi(_sec);

    char _temp[4];
    for (int i = 20; i < data.length(); ++i) {
        _temp[i - 20] = data[i];
    }
    temp = atoi(_temp);

    //printf("%d - %d - %d : %d - %d - %d\n", year, month, day, hour, minute, sec);

    time_t rawtime, date;
    struct tm * timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    timeinfo->tm_year   = year - 1900;
    timeinfo->tm_mon    = month - 1;
    timeinfo->tm_mday   = day;
    timeinfo->tm_hour   = hour;
    timeinfo->tm_min    = minute;
    timeinfo->tm_sec    = sec;

    date = mktime(timeinfo);

    printf("\tUNIX timestamp: %i - temperature: %d\n", date, temp);
}
