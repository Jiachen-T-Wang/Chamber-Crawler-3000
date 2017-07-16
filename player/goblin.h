#ifndef __GOBLIN_H__
#define __GOBLIN_H__

#include <iostream>
#include <string>
#include "player.h"

class Floor;
class Cell;

//steals 5 gold from every slain enemy
class Goblin: public Player{
   public:
   	Goblin(Floor* f);
   	void attack(Enemy* e) override;
};

#endif