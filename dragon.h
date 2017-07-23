#ifndef __DRAGON_H__
#define __DRAGON_H__

#include "enemy.h"

class DragonHoard;
class Treasure;

class Dragon: public Enemy{
	std::weak_ptr<Treasure> hoard;
public:
    Dragon(std::shared_ptr<Treasure> hoard);
    bool isDragon() override;
    std::weak_ptr<Treasure> getHoard();
    void move() override;
    char symbol() override;
};

#endif
