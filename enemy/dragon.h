#ifndef __DRAGON_H__
#define __DRAGON_H__

#include "enemy.h"

class DragonHoard;
//does 50% more damage to goblins
class Orcs: public Enemy{
	DragonHoard* hoard;
public:
	Dragon();
};

#endif
