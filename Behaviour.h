/**
 @file Behaviour.h 
 @class Behaviour
 @brief The encompassing Behaviour object that generates outputed movements
 @details This Behaviour object defines one part of the behaviour that the robot can execute.
 Namely this is the overall beahviour that is able to be scored, generate a list of
 movements for the robot based on sensor data, and passes that information to the master
 control loop.

 @author Jonathan Chang
 @version 0.0.1
 @date 16/11/2019
*/

#ifndef BEHAVIOUR_H
#define BEHAVIOUR_H

#include <string>
#include <vector>

#include "Node.h"
#include "Action.h"
#include "Position.h"

class Movement;

class Behaviour : public Node {
public:
	Behaviour();
    ~Behaviour();

	virtual int executeC();
	virtual int executeP(int stat);
	std::vector<Movement*> generateMovements();

protected:
	std::vector<Action*> actions;
	Position* position;
	
};
#endif