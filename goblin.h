#ifndef __GOBLIN_H__
#define __GOBLIN_H__

#include <iostream>
#include <string>
#include "player.h"

class Floor;
class Cell;
class Orcs;

//steals 5 gold from every slain enemy
class Goblin: public Player{
   public:
   	Goblin(Floor* f);
   	void beAtkBy(Enemy* e) override;
};

#endif
