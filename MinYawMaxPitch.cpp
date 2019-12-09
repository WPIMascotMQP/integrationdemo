#include "MinYawMaxPitch.h"

#include "Controller.h"

MinYawMaxPitch::MinYawMaxPitch() {
	position = new Position(45.0, 20.0);
}

MinYawMaxPitch::~MinYawMaxPitch() {

}

int MinYawMaxPitch::executeC() {
	status = status::running;
	verbose("Execute MinYawMaxPitch");
	controller.addPosition(position, this);
	return status;
}

int MinYawMaxPitch::executeP(int stat) {
	if (status != status::running) {
		return status::failure;
	}
	status = stat;
	verbose("Call MinYawMaxPitch Parent");
	return parent->executeP(stat);
}