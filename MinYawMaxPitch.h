#ifndef MINYAWMAXPITCH_H
#define MINYAWMAXPITCH_H

#include "Behaviour.h"
class MinYawMaxPitch : public Behaviour {
public:
	MinYawMaxPitch();
	~MinYawMaxPitch();

	int executeC();
	int executeP(int stat);
private:

};

#endif