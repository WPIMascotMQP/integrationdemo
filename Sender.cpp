#include "Sender.h"

#include "Node.h"

/*Serial serial_snd("portName");
Serial Sender::serial = serial_snd;*/

Sender::Sender() {
	
}

Sender::~Sender() {

}

int Sender::sendMessage(std::string mes) {
	char data[256];
	strcpy_s(data, DATA_SIZE, mes.c_str());
	std::cout << "Sending Message: " << data << std::endl;
	//return serial.WriteData(data, mes.length + 1) ? status::success : status::failure;
	return status::success;
}

std::string Sender::recieveMessage(std::string input) {
	int result = -1;
	char data[256];
	data[255] = '\0';
	std::cout << "Waiting for Message" << std::endl;
	/*while (result == -1 && !(GetKeyState('R') & 0x8000)) {//&& input.find("w") != std::string::npos) {
		//result = serial.ReadData(data, DATA_SIZE);
		Sleep(1000/7.5/4);
	}*/
	Sleep(1000);
	std::string str(data);
	return str;
}