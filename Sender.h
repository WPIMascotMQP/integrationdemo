/**
 @file Sender.h
 @class Sender
 @brief The Sender Object that handles communications with the serial processor
 @details This Sender Object handles communications with the serial processor
 In this case it is assumed to be an Ardino

 @author Jonathan Chang
 @version 0.0.1
 @date 09/12/2019 14:13:30
*/


#ifndef SENDER_H
#define SENDER_H

#include <string>
#include <Windows.h>

#include "SerialClass.h"

class Sender {
public:
	Sender();
	~Sender();

	int sendMessage(std::string mes);
	std::string recieveMessage(std::string input);

private:
	//static Serial serial;
	static const unsigned int DATA_SIZE = 255;
};

#endif