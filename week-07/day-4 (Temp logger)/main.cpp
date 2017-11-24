#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <conio.h>

#include "SerialPortWrapper.h"

using namespace std;

//Function Prototypes
void TLMainMenu();
void TLWelcomeScreen();
void TLPromt(bool*);
void TLGoodbye();
void TL_OpenPort(SerialPortWrapper*, bool*);
void TL_ClosePort(SerialPortWrapper*, bool*);
void TL_ListData(SerialPortWrapper*, bool*);
void TL_SaveData(SerialPortWrapper*, vector<string>&, bool*);
bool ValidateSerialData(string);
void TL_SaveToFile(vector<string>&);
//--------------------------------------------------------------------------------------------------
int main() {
    TLMainMenu();
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
        while (menu = getch(), menu != 104 && menu != 111 && menu != 115 && menu != 99 && menu != 108 && menu != 101 && menu != 102) {}

        switch (menu) {
            case 104 : TLWelcomeScreen(); break; //h (help menu)
            case 111 : TL_OpenPort(serial, &isPortOpen); break; //o (open port)
            case 115 : TL_SaveData(serial, SerialData, &isPortOpen); break; //s
            case 99 : TL_ClosePort(serial, &isPortOpen); break; //c (close port)
            case 108 : TL_ListData(serial, &isPortOpen); break; //l (list)
            case 102 : TL_SaveToFile(SerialData); break;
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
    cout << " f   Save data extracted from menu 's' to file (data.txt)" << endl;
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
    cout << endl << endl << "Temperature logger exits." << endl;
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
            cout << line;
            cout << " -> " << (ValidateSerialData(line) == false ? "(Data discarded)" : "(OK!)");
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
        if (line.length() > 16 && ValidateSerialData(line) == true){
            cout << endl;
            cout << counter << " -> " << line << " ";
            vector.push_back(line);
            ++counter;
        } else if (line.length() > 16) {cout << ".";}
        if (kbhit() && (keypressed = getch(), keypressed == 27)) break;
    }
    cout << endl << vector.size() << " data sample saved from Serial Port. Press 'f' to save to the default file." << endl;
}
//----------------------------------Checking-serial-data-validity-:-2022.13.35 25:63:12 122--------
bool ValidateSerialData(string data) {
    //If the string contains any other character than numbers, dots, semicolons and dash(for minus temp) than this is invalid string
    if (data.find_first_not_of("0123456789.:- ") != std::string::npos) {
        //cout << "Characters in string";
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
    if (dataStringTokens.size() != 7) {
        //cout << "Invalid amount of number";
        return false;
    }

    //Convert strings to integers and check the range, and filter out the invalid dates and temperature records
    vector<unsigned int> dateLow(6); dateLow = {1970, 1, 1, 0, 0, 0};
    vector<unsigned int> dateHigh(6); dateHigh = {2017, 12, 31, 23, 59, 59};
    for (int i = 0; i < 6; ++i) {
        if (stoi(dataStringTokens.at(i)) < dateLow.at(i) || stoi(dataStringTokens.at(i)) > dateHigh.at(i)) {
            //cout << "Invalid data.";
            return false;
        }
    }
    //Check temperature data too
    if (stoi(dataStringTokens.at(6)) < -44 || stoi(dataStringTokens.at(6)) > 56) {
        //cout << "Invalid temperature";
        return false;
    }
    return true;
}
//--------------------------------------------------------------------------------------------------
void TL_SaveToFile(vector<string>& vector) {
    if (vector.size() == 0) {
        cout << "No serial data saved to memory. Run 's' command first." << endl;
        return;
    }

    ofstream outfile;
    outfile.open("SerialData.txt", fstream::app);

    for (string s : vector) {
        outfile << s << endl;
    }
    cout << vector.size() << " task saved to file. Look for 'SerialData.txt' in local directory." << endl;
    outfile.close();
}