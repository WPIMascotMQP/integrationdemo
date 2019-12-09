#include "Controller.h"

#include "MasterControlLoop.h"
#include "Node.h"
#include "Position.h"

Node node_controller;
SensorData Controller::data = node_controller.getSensorData();

std::vector<Behaviour*> currentBehaviours;
std::vector<Behaviour*> previousBehaviours;

/**
 CONSTRUCTOR
*/
Controller::Controller() {

}

/**
 DECONSTRUCTOR
*/
Controller::~Controller() {

}

/**
 Adds a position to go to
 @param pos The position
*/
void Controller::addPosition(Position* pos, Behaviour *beh) {
	positions.push_back(pos);
	currentBehaviours.push_back(beh);
}

Position* Controller::getPosition() {
	return position;
}

/**
 Gets the first position and executes it
 @return The status
*/
int Controller::execute() {
	std::vector<Position*>::iterator pos_itr = positions.begin();
	position = *pos_itr;
	positions.clear();
	previousBehaviours = currentBehaviours;
	currentBehaviours.clear();
	return status::success;
}