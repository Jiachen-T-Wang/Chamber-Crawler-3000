#include "header.h"

Dragon::Dragon(std::shared_ptr<DragonHoard> hoard)
: Enemy{150, 20, 20, "Dragon"}, hoard{std::weak_ptr<DragonHoard>(hoard)} {}


std::weak_ptr<DragonHoard> Dragon::getHoard(){
    return hoard;
}
bool Dragon::isDragon(){
   return true;
}

void Dragon::move(){}

char Dragon::symbol() {return 'D';}

