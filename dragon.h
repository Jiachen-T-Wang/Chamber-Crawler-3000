#ifndef __DRAGON_H__
#define __DRAGON_H__

#include "enemy.h"

class DragonHoard;
class Treasure;

class Dragon: public Enemy{
	DragonHoard* hoard;
public:
    Dragon(DragonHoard* hoard);
    bool isDragon() override;
    DragonHoard* getHoard();
    void move() override;
    char symbol() override;
};

#endif
