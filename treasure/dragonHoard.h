#ifndef __DRAGONHOARD_H__
#define __DRAGONHOARD_H__
#include "treasure.h"

class Dragon;

class DragonHoard : public Treasure {
	std::shared_ptr<Dragon> dragon;
 public:
 	DragonHoard();
};

#endif
