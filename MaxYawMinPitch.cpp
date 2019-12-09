#include "MaxYawMinPitch.h"

#include "Controller.h"

MaxYawMinPitch::MaxYawMinPitch() {
	position = new Position(45.0, -90.0);
}

MaxYawMinPitch::~MaxYawMinPitch() {

}

int MaxYawMinPitch::executeC() {
	status = status::running;
	verbose("Execute MaxYawMinPitch");
	controller.addPosition(position, this);
	return status;
}

int MaxYawMinPitch::executeP(int stat) {
	if (status != status::running) {
		return status::failure;
	}
	status = stat;
	verbose("Call MaxYawMinPitch Parent");
	return parent->executeP(stat);
}