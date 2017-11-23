#include <iostream>
#include <string>
#include <vector>
#include <conio.h>

#include "SerialPortWrapper.h"

using namespace std;

void TLMainMenu();
void TLWelcomeScreen();
void TLPromt(bool*);
void TLGoodbye();
void TL_OpenPort(SerialPortWrapper*, bool*);
void TL_ClosePort(SerialPortWrapper*, bool*);
void TL_ListValues(SerialPortWrapper*, bool*);

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
        TLPromt(&isPortOpen);
        menu = getch();

        switch (menu) {
            case 'h' : TLWelcomeScreen(); break;
            case 'o' : TL_OpenPort(serial, &isPortOpen); break;
            case 's' : cout << "s"; break;
            case 'c' : TL_ClosePort(serial, &isPortOpen); break;
            case 'l' : TL_ListValues(serial, &isPortOpen); break;
        }

    } while (menu != 'e');
    TLGoodbye();
}

void TLWelcomeScreen() {
    cout << endl << endl;
    cout << "Temperature Logger Application" << endl;
    cout << "==============================" << endl;
    cout << "Commands:" << endl;
    cout << " h   Show command list" << endl;
    cout << " o   Open port" << endl;
    cout << " s   Start logging / Stop logging" << endl;
    cout << " c   Close port" << endl;
    cout << " l   List after error handling" << endl;
    cout << " e   Exit from the program" << endl;
    cout << endl;
}

void TLPromt(bool* port) {
    cout << "Press command [" << (*port == true ? "x" : " ") << "]: ";
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

void TL_ListValues(SerialPortWrapper* serial, bool* isPortOpen) {
    if (*isPortOpen == false) {
        cout << "Port is closed. Open it first." << endl << endl;
        return;
    }
    char keypressed;
    string line;

    cout << "Press any key to get a new sample, or ESC to exit." << endl;
    while(getch() != 27){
        serial->readLineFromPort(&line);
        if (line.length() > 0){
            cout << line << endl;
        }
    }
}
