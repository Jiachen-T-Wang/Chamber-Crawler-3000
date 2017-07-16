#ifndef __TROLL_H__
#define __TROLL_H__

#include <iostream>
#include <string>
#include "player.h"

class Floor;
class Cell;

//regains HP every turn 
class Troll: public Player{
   public:
   	Troll(Floor* f);
   	void regainHP();
};

#endif
