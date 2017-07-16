#ifndef __DROW_H__
#define __DROW_H__

#include <iostream>
#include <string>
#include "player.h"

class Floor;
class Cell;
class Potion;

class Drow: public Player{
   public:
   	Drow(Floor* f);
   	void usePotion(Potion* p) override; //all potions have their effect magnified by 1.5
};

#endif
