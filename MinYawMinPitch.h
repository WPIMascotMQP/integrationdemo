#ifndef MINYAWMINPITCH_H
#define MINYAWMINPITCH_H

#include "Behaviour.h"
class MinYawMinPitch : public Behaviour {
public:
	MinYawMinPitch();
	~MinYawMinPitch();

	int executeC();
	int executeP(int stat);
private:

};

#endif