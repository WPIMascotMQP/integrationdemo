#include "SUtilityDec.h"

#include "SensorData.h"

SUtilityDec::SUtilityDec(Node* chi) : UtilityDec(chi) {

}

SUtilityDec::~SUtilityDec() {

}

double SUtilityDec::getPriority() {
	//return getSensorData().getInput().find('s') != std::string::npos ? 1.0 : 0.1;
	return (GetKeyState('S') & 0x8000) ? 1.0 : 0.1;
}