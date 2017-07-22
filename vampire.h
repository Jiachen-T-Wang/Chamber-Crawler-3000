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
   	void attack(std::shared_ptr<Enemy> p) override;  //gains 5 HP every successful attack
   	void attack(std::shared_ptr<Halfling> h) override;
   	void beAtkBy(std::shared_ptr<Enemy> e) override;
};

#endif
