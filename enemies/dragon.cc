#include "dragon.h"

void Dragon::Dragon(std::shared_ptr<DragonHoard> hoard)
	: Enemy{150, 20, 20, "Dragon"}, hoard{hoard} {}


std::shared_ptr<DragonHoard> Dragon::getHoard(){
    return hoard;
}
bool Dragon::isDragon(){
   return true;
}

