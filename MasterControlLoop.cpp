#include <iostream>
#include <Windows.h>

#include "BehaviourTree.h"
#include "Controller.h"
#include "Sequence.h"
#include "MasterControlLoop.h"
#include "Parallel.h"
#include "Sender.h"
#include "Utility.h"
#include "UtilityDec.h"
#include "SUtilityDec.h"
#include "PUtilityDec.h"

#include "MaxYawMaxPitch.h"
#include "MaxYawMinPitch.h"
#include "MinYawMaxPitch.h"
#include "MinYawMinPitch.h"

extern std::vector<Behaviour*> previousBehaviours;

int main(int argc, char* argv[]) {
	BehaviourTree bt;
	Sequence sq;
	Parallel pl;
	Utility ut;

	MaxYawMaxPitch xyxp;
	MaxYawMinPitch xynp;
	MinYawMaxPitch nyxp;
	MinYawMinPitch nynp;

	SUtilityDec sud;
	PUtilityDec pud;

	sq.addChild(&nynp);
	sq.addChild(&xynp);
	sq.addChild(&nyxp);
	sq.addChild(&xyxp);
	sq.reset();

	pl.addChild(&sq);
	pl.reset();
	
	sud.setChild(&sq);
	pud.setChild(&pl);

	ut.addChild(&sud);
	ut.addChild(&pud);

	bt.setRoot(&ut);

	previousBehaviours.push_back(&bt);

	Controller* controller = &Node::controller;
	SensorData* data = &Node::data;
	Sender sender;

	std::string input = "";
	/*std::getline(std::cin, input);
	data->setInput(input);*/
	while (input.find("x") == std::string::npos && !(GetKeyState('X') & 0x8000)) {
		executeBehaviours(input);
		controller->execute();

		Position* position = controller->getPosition();
		char output[50];
		sprintf_s(output, "(%5.2f, %5.2f)", position->getYawPosition(), position->getPitchPosition());
		sender.sendMessage(output);
		sender.recieveMessage(input);

		/*std::getline(std::cin, input);
		data->setInput(input);*/
	}
}

void executeBehaviours(std::string input) {
	std::vector<Behaviour*>::iterator itr = previousBehaviours.begin();
	while(itr != previousBehaviours.end()) {
		Behaviour* behaviour = *itr;
		int result = (input.find("f") == std::string::npos) ? behaviour->executeP(status::success) : behaviour->executeP(status::failure);
		itr++;
	}
	previousBehaviours.clear();
}