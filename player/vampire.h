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
   	Shade(Floor* f);
   	void getAllerge();
   	void attack(int dir) override;  //gains 5 HP every successful attack
};

#endif
