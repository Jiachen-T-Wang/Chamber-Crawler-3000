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
   	Drow();
   	void usePotion(Potion* p) override; //potions have their effect magnified by 1.5
   	void beAtkBy(Enemy* e) override;
};

#endif
