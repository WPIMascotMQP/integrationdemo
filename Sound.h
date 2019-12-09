#ifndef SOUND_H
#define SOUND_H

#include <Windows.h>
#include <mmsystem.h>

#include "Behaviour.h"

class Sound : public Behaviour {
public:
	Sound();
	~Sound();

	int executeC();
	int executeP(int stat);
private:

};

#endif