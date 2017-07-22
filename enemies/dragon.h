#ifndef __DRAGON_H__
#define __DRAGON_H__

#include "../enemy.h"

class DragonHoard;

class Dragon: public Enemy{
	std::weak_ptr<DragonHoard> hoard;
public:
<<<<<<< HEAD
	Dragon(std::shared_ptr<DragonHoard> hoard);
    std::shared_ptr<DragonHoard> getHoard();
   bool isDragon();
=======
	Dragon(std::weak_ptr<DragonHoard> hoard);
    std::weak_ptr<DragonHoard> getHoard();
    void move() override;
>>>>>>> 6ebfa93a9337091e3a8fb67c3f1d9c71141a7d7a
};

#endif
