#ifndef __DRAGONHOARD_H__
#define __DRAGONHOARD_H__
#include "treasure.h"

class Dragon;

class DragonHoard : public Treasure {
	std::shared_ptr<Dragon> dragon;
    bool canPick;
    bool bePlayer;
 public:
 	DragonHoard();
    std::shared_ptr<Dragon> getDragon();
    void setDragon(std::shared_ptr<Dragon> dragon) override;
    void setDragon() override;
    void removeDragon();
    bool canPickUp() override;
    char symbol() override;
    void switchPlayer() override;
};

#endif
