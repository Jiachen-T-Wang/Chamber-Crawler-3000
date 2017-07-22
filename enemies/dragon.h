#ifndef __DRAGON_H__
#define __DRAGON_H__

#include "../enemy.h"

class DragonHoard;

class Dragon: public Enemy{
	std::shared_ptr<DragonHoard> hoard;
public:
	Dragon(std::shared_ptr<DragonHoard> hoard);
    std::shared_ptr<DragonHoard> getHoard();
    void move() override;
};

#endif
