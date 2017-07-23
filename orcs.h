#ifndef __ORCS_H__
#define __ORCS_H__

#include "enemy.h"

//does 50% more damage to goblins
class Orcs: public Enemy{
public:
	Orcs();
	void attack(Goblin* g) override;
    char symbol() override;
};

#endif
