#ifndef __DRAGONHOARD_H__
#define __DRAGONHOARD_H__
#include "treasure.h"

class Dragon;

class DragonHoard : public Treasure {
	std::shared_ptr<Dragon> dragon;
    bool canPick;
 public:
 	DragonHoard();
    std::shared_ptr<Dragon> getDragon();
    void setDragon() override;
    void removeDragon();
    bool canPickUp() override;
};

#endif
