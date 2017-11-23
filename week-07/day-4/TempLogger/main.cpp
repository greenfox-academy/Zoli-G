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
void TL_SaveData(SerialPortWrapper*, vector<string>&, bool*);
bool ValidateSerialData(string&);

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
    vector<string> SerialData;

    TLWelcomeScreen();
    do {
        TLPromt(&isPortOpen);
        while (menu = getch(), menu != 104 && menu != 111 && menu != 115 && menu != 99 && menu != 108 && menu != 101) {}

        switch (menu) {
            case 104 : TLWelcomeScreen(); break;
            case 111 : TL_OpenPort(serial, &isPortOpen); break;
            case 115 : TL_SaveData(serial, SerialData, &isPortOpen); break;
            case 99 : TL_ClosePort(serial, &isPortOpen); break;
            case 108 : TL_ListValues(serial, &isPortOpen); break;
            default : continue;
        }

    } while (menu != 101);
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
    cout << endl;
    cout << "Press command [" << (*port == true ? "x" : " ") << "]: ";
}

void TLGoodbye() {
    cout << endl << "Temperature logger exits." << endl;
}

void TL_OpenPort(SerialPortWrapper* serial, bool* isPortOpen) {
    if (*isPortOpen == true) {
        cout << "Port already open." << endl;
        return;
    }
    cout << "Opening port... ";
    serial->openPort();
    *isPortOpen = true;
    cout << "opened." << endl;
}

void TL_ClosePort(SerialPortWrapper* serial, bool* isPortOpen) {
    if (*isPortOpen == false) {
        cout << "Port already closed." << endl;
        return;
    }
    cout << "Closing port... ";
    serial->closePort();
    *isPortOpen = false;
    cout << "closed." << endl;
}

void TL_ListValues(SerialPortWrapper* serial, bool* isPortOpen) {
    if (*isPortOpen == false) {
        cout << "Port is closed. Open it first." << endl;
        return;
    }
    string line;
    char keypressed;

    cout << "Printing Serial Data... press ESC to exit:" << endl;
    while(1){
        serial->readLineFromPort(&line);
        if (line.length() > 0){
            cout << line << " -> ";
            ValidateSerialData(line);
            cout << endl;
        }
        if (kbhit() && (keypressed = getch(), keypressed == 27)) break;
    }
}

void TL_SaveData(SerialPortWrapper* serial, vector<string>& vector, bool* isPortOpen) {
if (*isPortOpen == false) {
        cout << "Port is closed. Open it first before saving." << endl;
        return;
    }
    string line;
    char keypressed;
    unsigned int counter = 1;

    cout << "Saving Serial Data... press ESC to exit:" << endl;
    while(1){
        serial->readLineFromPort(&line);
        if (line.length() > 0){
            cout << counter << " -> " << line << endl;
            vector.push_back(line);
            ++counter;
        }
        if (kbhit() && (keypressed = getch(), keypressed == 27)) break;
    }
    cout << vector.size() << " data sample saved from Serial Port." << endl;
}

bool ValidateSerialData(string& data) {
    if (data.find_first_not_of("0123456789.:- ") != std::string::npos) {
        cout << "Characters in string";
        return false;
    }
    vector<string> dataStringTokens;
    for (int i = 0; i < data.size(); ++i) {
        if (data.at(i) == '.' || data.at(i) == ':' || data.at(i) == ' ') {
            dataStringTokens.push_back(data.substr(0, i));
            data.erase(0, i + 1);
            i = 0;
        }
    }
    dataStringTokens.push_back(data);

    if (dataStringTokens.size() != 7) {cout << "Invalid amount of number"; return false;}

    if (stoi(dataStringTokens.at(0)) < 1970 || stoi(dataStringTokens.at(0)) > 2017) {cout << "Invalid year"; return false;}
    if (stoi(dataStringTokens.at(1)) < 1 || stoi(dataStringTokens.at(1)) > 12) {cout << "Invalid month"; return false;}
    if (stoi(dataStringTokens.at(2)) < 1 || stoi(dataStringTokens.at(2)) > 31) {cout << "Invalid day"; return false;}

    if (stoi(dataStringTokens.at(3)) < 0 || stoi(dataStringTokens.at(3)) > 24) {cout << "Invalid hour"; return false;}
    if (stoi(dataStringTokens.at(4)) < 0 || stoi(dataStringTokens.at(4)) > 59) {cout << "Invalid minute"; return false;}
    if (stoi(dataStringTokens.at(5)) < 0 || stoi(dataStringTokens.at(5)) > 59) {cout << "Invalid second"; return false;}

    if (stoi(dataStringTokens.at(6)) < -44 || stoi(dataStringTokens.at(6)) > 56) {cout << "Invalid temperature"; return false;}

    for (string s : dataStringTokens) {
        cout << s << "|";
    }
}
