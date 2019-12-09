/**
 @file Positon.h
 @class Position
 @brief The Position Object that defines the kinematic location of the robot
 @details This Position Object defines the required kinematic location of robot
 in both a 3D space as well as intended encoder values

 @author Jonathan Chang
 @version 0.0.1
 @date 16/11/2019 16:18:30 
*/

#ifndef POSITION_H
#define POSITION_H

#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

class Position {

public:
	Position(double ya, double pit);
	Position() : Position(0.0, 0.0) {};
	~Position();

	void setYawPosition(double ya);
	void setPitchPosition(double pit);
	double getYawPosition();
	double getPitchPosition();

	bool operator==(const Position& pos2) {
		return (yaw_position == pos2.yaw_position) &&
			(pitch_position == pos2.pitch_position);
	};

	friend std::ostream& operator<< (std::ostream& out, Position& pos) {
		char output[50];
		sprintf_s(output, "( %5.2f, %5.2f)", pos.getYawPosition(), pos.getPitchPosition());
		out << output;
		return out;
	}
private:
	double yaw_position;
	double pitch_position;

};
#endif