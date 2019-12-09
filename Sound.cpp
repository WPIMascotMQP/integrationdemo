#include "Sound.h"

#include "Controller.h"

Sound::Sound() {

}

Sound::~Sound() {

}

int Sound::executeC() {
	status = status::running;
	verbose("Execute Sound");
	PlaySound("sos - morse - code_daniel - simion.wav", NULL, SND_FILENAME);
	controller.addBehaviour(this);
	return status;
}

int Sound::executeP(int stat) {
	if (status != status::running) {
		return status::failure;
	}
	status = stat;
	verbose("Call Sound Parent");
	return parent->executeP(stat);
}