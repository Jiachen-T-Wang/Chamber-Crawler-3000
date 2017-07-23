#include "header.h"

Dragon::Dragon(std::shared_ptr<Treasure> hoard)
: Enemy{150, 20, 20, "Dragon"}, hoard{std::weak_ptr<Treasure>(hoard)} {
    
}


std::weak_ptr<Treasure> Dragon::getHoard(){
    return hoard;
}
bool Dragon::isDragon(){
   return true;
}

void Dragon::move(){}

char Dragon::symbol() {return 'D';}

