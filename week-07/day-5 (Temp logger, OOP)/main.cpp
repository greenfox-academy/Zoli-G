#include <iostream>
#include <string>
#include <vector>
#include <conio.h>

#include "SerialPortWrapper.h"

using namespace std;

typedef struct {
    unsigned int year;
    unsigned int month;
    unsigned int day;

    unsigned int hour;
    unsigned int minute;
    unsigned int second;

    int temperature;
} TempData;

class WeatherServer {
private:
    //Collected data
    TempData record;
    vector<TempData> record_vector;
    //Hardware data
    string COM_PORT;
    int BAUDRATE;
    bool isConnected;
    bool isPortOpen;
    vector<string> ports;
public:
    WeatherServer(string COM_PORT, int BAUDRATE) : COM_PORT(COM_PORT), BAUDRATE(BAUDRATE) {
        isConnected = false;
        isPortOpen = false;
        ports = SerialPortWrapper::listAvailablePorts();

        if (ports.size() == 0) {
            cout << "Weather Server Board not connected, program terminates." << endl;
        } else {
            cout << "COM port found, Weather Server Connection establishing..." << endl;
            isConnected = true;
        }
    }
    ~WeatherServer() {
        cout << "Weather Server shutting down..." << endl;
    }
    bool getConnection() {return isConnected;}
};

//Function Prototypes
void TLMainMenu();
void TLWelcomeScreen();
void TLPromt(bool*);
void TLGoodbye();
void TL_OpenPort(SerialPortWrapper*, bool*);
void TL_ClosePort(SerialPortWrapper*, bool*);
void TL_ListData(SerialPortWrapper*, bool*);
void TL_SaveData(SerialPortWrapper*, vector<string>&, bool*);
bool ValidateSerialData(string&);
//--------------------------------------------------------------------------------------------------
int main() {
    //Create new WeatherServer object
    WeatherServer* WS = new WeatherServer("COM3", 115200);
    //If the board is not detected durint constructor run -> delete instance & exit software
    if (!WS->getConnection()) {
        delete WS;
        exit(0);
    }

    cout << "Hello+";
    
    return 0;
}
//--------------------------------------------------------------------------------------------------
void TLMainMenu() {
    cout << "Temp logger program" << endl;
    cout << "-------------------" << endl << endl;

    //Port enumerator: let's print out how many COM ports are on the PC
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

    //Main menu's "global" variables
    SerialPortWrapper* serial = new SerialPortWrapper("COM3", 115200);  //Serial port object
    bool isPortOpen = false;                                            //Bool var to see if the port is already opened
    char menu;                                                          //Menu keypress
    vector<string> SerialData;                                          //Vector to store the serial data (from STM32 USB)

    TLWelcomeScreen();
    do {
        TLPromt(&isPortOpen);
        while (menu = getch(), menu != 104 && menu != 111 && menu != 115 && menu != 99 && menu != 108 && menu != 101) {}

        switch (menu) {
            case 104 : TLWelcomeScreen(); break; //h (help menu)
            case 111 : TL_OpenPort(serial, &isPortOpen); break; //o (open port)
            case 115 : TL_SaveData(serial, SerialData, &isPortOpen); break; //s
            case 99 : TL_ClosePort(serial, &isPortOpen); break; //c (close port)
            case 108 : TL_ListData(serial, &isPortOpen); break; //l (list)
            default : continue; //who knows...
        }

    } while (menu != 101); //e (exit)
    TLGoodbye();
}
//--------------------------------------------------------------------------------------------------
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
//--------------------------------------------------------------------------------------------------
void TLPromt(bool* port) {
    cout << endl;
    cout << "Press command [" << (*port == true ? "x" : " ") << "]: ";
}
//--------------------------------------------------------------------------------------------------
void TLGoodbye() {
    cout << endl << "Temperature logger exits." << endl;
}
//--------------------------------------------------------------------------------------------------
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
//--------------------------------------------------------------------------------------------------
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
//--------------------------------------------------------------------------------------------------
void TL_ListData(SerialPortWrapper* serial, bool* isPortOpen) {
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
//--------------------------------------------------------------------------------------------------
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
//----------------------------------Checking-serial-data-validity-:-2022.13.35 25:63:12 122--------
bool ValidateSerialData(string& data) {
    //If the string contains any other character than numbers, dots, semicolons and dash(for minus temp) than this is invalid string
    if (data.find_first_not_of("0123456789.:- ") != std::string::npos) {
        cout << "Characters in string";
        return false;
    }
    //Tokenizer engine: 1.make a vector 2.run through the string 3.if delimiter found: .:SPACE -> make a substring
    //from the start to the first delimiter, push it to the vector, than erase this part from the string, 4. reset counter
    vector<string> dataStringTokens;
    for (int i = 0; i < data.size(); ++i) {
        if (data.at(i) == '.' || data.at(i) == ':' || data.at(i) == ' ') {
            dataStringTokens.push_back(data.substr(0, i));
            data.erase(0, i + 1);
            i = 0;
        }
    }
    dataStringTokens.push_back(data); //Put last part of the string to the vector (no delimiter at the end)

    //if the string is not delimeted to 7 parts, than its not valid
    if (dataStringTokens.size() != 7) {cout << "Invalid amount of number"; return false;}

    //Convert strings to integers and check the range, and filter out the invalid dates and temperature records
    if (stoi(dataStringTokens.at(0)) < 1970 || stoi(dataStringTokens.at(0)) > 2017) {cout << "Invalid year"; return false;}
    if (stoi(dataStringTokens.at(1)) < 1 || stoi(dataStringTokens.at(1)) > 12) {cout << "Invalid month"; return false;}
    if (stoi(dataStringTokens.at(2)) < 1 || stoi(dataStringTokens.at(2)) > 31) {cout << "Invalid day"; return false;}

    if (stoi(dataStringTokens.at(3)) < 0 || stoi(dataStringTokens.at(3)) > 24) {cout << "Invalid hour"; return false;}
    if (stoi(dataStringTokens.at(4)) < 0 || stoi(dataStringTokens.at(4)) > 59) {cout << "Invalid minute"; return false;}
    if (stoi(dataStringTokens.at(5)) < 0 || stoi(dataStringTokens.at(5)) > 59) {cout << "Invalid second"; return false;}

    if (stoi(dataStringTokens.at(6)) < -44 || stoi(dataStringTokens.at(6)) > 56) {cout << "Invalid temperature"; return false;}

    //if this point reached, then the string contained valid data, so let's print out:
    for (string s : dataStringTokens) {
        cout << s << "|";
    }
    return true;
}
