#include "MinYawMinPitch.h"

#include "Controller.h"

MinYawMinPitch::MinYawMinPitch() {
	position = new Position(-45.0,-90.0);
}

MinYawMinPitch::~MinYawMinPitch() {

}

int MinYawMinPitch::executeC() {
	status = status::running;
	verbose("Execute MinYawMinPitch");
	controller.addPosition(position, this);
	return status;
}

int MinYawMinPitch::executeP(int stat) {
	if (status != status::running) {
		return status::failure;
	}
	status = stat;
	verbose("Call MinYawMinPitch Parent");
	return parent->executeP(stat);
}