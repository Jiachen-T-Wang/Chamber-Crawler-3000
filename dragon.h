#ifndef __DRAGON_H__
#define __DRAGON_H__

#include "enemy.h"

class DragonHoard;

class Dragon: public Enemy{
	std::weak_ptr<DragonHoard> hoard;
public:
    Dragon(std::shared_ptr<DragonHoard> hoard);
    bool isDragon() override;
	Dragon(std::weak_ptr<DragonHoard> hoard);
    std::weak_ptr<DragonHoard> getHoard();
    void move() override;
};

#endif
