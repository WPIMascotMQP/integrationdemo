#ifndef MAXYAWMINPITCH_H
#define MAWYAWMINPITCH_H

#include "Behaviour.h"
class MaxYawMinPitch : public Behaviour {
public:
	MaxYawMinPitch();
	~MaxYawMinPitch();

	int executeC();
	int executeP(int stat);
private:

};

#endif