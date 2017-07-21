#ifndef __VAMPIRE_H__
#define __VAMPIRE_H__

#include <iostream>
#include <string>
#include "player.h"

class Floor;
class Cell;

class Vampire: public Player{
	bool allerge; 
   public:
   	Vampire(Floor* f);
   	void getAllerge();
   	void attack(Enemy* p) override;  //gains 5 HP every successful attack
   	void attack(Halfling* h) override;
   	void beAtkBy(Enemy* e);
};

#endif
