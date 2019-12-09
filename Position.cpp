#include "Position.h"

/**
 CONSTRUCTOR
 @param ya The yaw position
 @param pit The pitch position
*/
Position::Position(double ya, double pit) {
	yaw_position = ya;
	pitch_position = pit;
}

/**
 DECONSTRUCTOR
*/
Position::~Position() {

}

/**
 Sets the Yaw position
 @param ya The Yaw position
*/
void Position::setYawPosition(double ya) {
	yaw_position = ya;
}

/**
 Gets the Yaw position
 @return The Yaw position
*/
double Position::getYawPosition() {
	return yaw_position;
}

/**
 Sets the Pitch position
 @param pit The PItch position
*/
void Position::setPitchPosition(double pit) {
	pitch_position = pit;
}

/**
 Sets the Pitch position
 @return The PItch position
*/
double Position::getPitchPosition() {
	return pitch_position;
}