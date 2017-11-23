#include <iostream>
#include <string>
#include <vector>

#include "SerialPortWrapper.h"

using namespace std;

void TLMainMenu();
void TLWelcomeScreen();
void TLPromt();
void TLGoodbye();
void TL_OpenPort(SerialPortWrapper* serial, bool* isPortOpen);
void TL_ClosePort(SerialPortWrapper* serial, bool* isPortOpen);
void TL_ListValues(SerialPortWrapper* serial);

int main()
{
/*    vector<string> ports = SerialPortWrapper::listAvailablePorts();
    cout << "Number of found serial ports: " << ports.size() << endl;
    for (unsigned int i = 0; i < ports.size(); i++) {
        cout << "\tPort name: " << ports.at(i) << endl;
    }
*/
    TLMainMenu();
    return 0;
}

void TLMainMenu() {
    cout << "Temp logger program" << endl;
    cout << "-------------------" << endl << endl;

    vector<string> ports = SerialPortWrapper::listAvailablePorts();
    cout << "Number of serial ports found: " << ports.size() << endl;
    for (unsigned int i = 0; i < ports.size(); i++) {
        cout << "\tPort name: " << ports.at(i) << endl;
    }
    if (ports.size() == 0) {
        cout << "Device not connected, program terminates." << endl;
        exit(0);
    }
    
    SerialPortWrapper* serial = new SerialPortWrapper("COM3", 115200);;
    bool isPortOpen = false;
    char menu;
    TLWelcomeScreen();
    do {
        TLPromt();
        cin >> menu;

        switch (menu) {
            case 104 : TLWelcomeScreen(); break; //h
            case 111 : TL_OpenPort(serial, &isPortOpen); break; //o
            case 115 : cout << "s"; break; //s
            case  99 : TL_ClosePort(serial, &isPortOpen); break; //c
            case 108 : TL_ListValues(serial); break; //l
        }

    } while (menu != 'e');
    TLGoodbye();
}

void TLWelcomeScreen() {
    cout << "Temperature Logger Application" << endl;
    cout << "==============================" << endl;
    cout << "Commands:" << endl;
    cout << " h   Show command list" << endl;
    cout << " o   Open port" << endl;
    cout << " s   Start logging / Stop logging" << endl;
    cout << " c   Close port" << endl;
    cout << " l   List after error handling" << endl;
    cout << " e   Exit from the program" << endl;
}

void TLPromt() {
    cout << "Choose commend: ";
}

void TLGoodbye() {
    cout << endl << "Temperature logger exits." << endl;
}

void TL_OpenPort(SerialPortWrapper* serial, bool* isPortOpen) {
    if (*isPortOpen == true) {
        cout << "Port already open." << endl << endl;
        return;
    }
    cout << "Opening port... ";
    serial->openPort();
    *isPortOpen = true;
    cout << "opened." << endl << endl;
}

void TL_ClosePort(SerialPortWrapper* serial, bool* isPortOpen) {
    if (*isPortOpen == false) {
        cout << "Port already closed." << endl << endl;
        return;
    }
    cout << "Closing port... ";
    serial->closePort();
    *isPortOpen = false;
    cout << "closed." << endl << endl;
}

void TL_ListValues(SerialPortWrapper* serial) {
    string line;
    while(1){
        serial->readLineFromPort(&line);
        if (line.length() > 0){
            cout << line << endl;
        }
    }
}
