/**
 @file Controller.h
 @class Controller
 @brief The Controller class breaks ups movements and send commands
 @details This Controller class recieves a list of movements to execute
 and generates commands within parameters for the point to fulfill those
 movements

 @author Jonathan Chang
 @version 0.0.1
 @date 16/11/2019
*/

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <string>
#include <vector>

#include "Behaviour.h"
#include "Movement.h"
#include "SensorData.h"

class Node;
class Controller {
public:
	Controller();
	~Controller();

	void addPosition(Position * movements, Behaviour *beh);
	void addBehaviour(Behaviour* beh);
	Position* getPosition();

	int execute();
protected:
	std::vector<Position*> positions;
	Position* position;
	static SensorData data;

};
#endif