#ifndef MAXYAWMAXPITCH_H
#define MAXYAWMAXPITCH_H

#include "Behaviour.h"
class MaxYawMaxPitch : public Behaviour {
public:
	MaxYawMaxPitch();
	~MaxYawMaxPitch();

	int executeC();
	int executeP(int stat);
private:

};

#endif