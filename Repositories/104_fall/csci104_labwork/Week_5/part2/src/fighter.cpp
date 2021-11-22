#include "fighter.h"

using namespace std;

Fighter::Fighter(string name) : Player(name) {
	// nothing to do here
}

void Fighter::doAction(Player *target) {
	// TODO
	if(target->getHP() > 75)
	{
		target->setHP(target->getHP() - 75);
	}
	else
	{
		target->setHP(0);
	}
	
}