#include "MaxYawMaxPitch.h"

#include "Controller.h"

MaxYawMaxPitch::MaxYawMaxPitch() {
	position = new Position(45.0, 20.0);
}

MaxYawMaxPitch::~MaxYawMaxPitch() {

}

int MaxYawMaxPitch::executeC() {
	status = status::running;
	verbose("Execute MaxYawMaxPitch");
	controller.addPosition(position, this);
	return status;
}

int MaxYawMaxPitch::executeP(int stat) {
	if (status != status::running) {
		return status::failure;
	}
	status = stat;
	verbose("Call MawYawMaxPitch Parent");
	return parent->executeP(stat);
}