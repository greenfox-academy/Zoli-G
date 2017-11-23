#include "SerialPortWrapper.h"

extern "C" {
    #include "rs232/rs232.h"
}

//115200

SerialPortWrapper::SerialPortWrapper(string portName, int baudRate): _portName(portName), _baudRate(baudRate) {
    int portsCount = comEnumerate();
    if (portsCount < 0) {
        throw "ERROR: could not enumerate the ports on the computer. Check your hardware configuration!";
    }

    _portIdx = comFindPort(portName.c_str());
    if (_portIdx < 0) {
        throw "ERROR: No serial port was found with this name!";
    }
};

vector<string> SerialPortWrapper::listAvailablePorts() {
    vector<string> portNames;
    int noPorts = comEnumerate();
    if (noPorts < 0) {
        throw "ERROR: could not enumerate the ports on the computer. Check your hardware configuration!";
    }
    for (int i = 0; i < noPorts; i++) {
        portNames.push_back(comGetPortName(i));
    }
    return portNames;
};

void SerialPortWrapper::openPort() {
    if (!comOpen(_portIdx, _baudRate)) {
        throw "ERROR: could not open port with name " + _portName;
    }
};

void SerialPortWrapper::readLineFromPort(string *line) {

	// Put data into the
    *line = "";
	char ch;
	int bytes = comRead(_portIdx, &ch, 1);

	// If there is no data on the port, exit
	if (bytes <= 0) {
		return;
	}

	// This loop will read until a \n character. If the buffer is too small, then
	// the characters will be discarded after the size limit is reached.
	while (ch != '\n') {
        // Check if we are not near the end of the line (cr character)
        if (ch != '\r') {
            line->append(&ch, 1);
		}
		while (comRead(_portIdx, &ch, 1) == 0);
	}
};

void SerialPortWrapper::closePort() {
    comClose(_portIdx);
};