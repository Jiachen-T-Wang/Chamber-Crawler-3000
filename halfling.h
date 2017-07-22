#ifndef __HALFLING_H__
#define __HALFLING_H__

#include "enemy.h"

//does 50% more damage to goblins
class Halfling: public Enemy{
public:
	Halfling();
	void beAtkBy(std::shared_ptr<Player> p) override;
};

#endif
