#ifndef SERIALPORTWRAPPER_H_
#define SERIALPORTWRAPPER_H_

#include <string>
#include <vector>

using namespace std;

class SerialPortWrapper {
    public:
        static vector<string> listAvailablePorts();

        SerialPortWrapper(string portName, int baudRate);

        void openPort();
        void readLineFromPort(string *line);
        void closePort();

    private:
        string _portName;
        int _baudRate;
        int _portIdx;
};

#endif // SERIALPORTWRAPPER_H_