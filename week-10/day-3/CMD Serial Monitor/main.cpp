#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <conio.h>

#include "SerialPortWrapper.h"

void OpenPort(SerialPortWrapper* serial, bool* isPortOpen);
void ClosePort(SerialPortWrapper* serial, bool* isPortOpen);

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