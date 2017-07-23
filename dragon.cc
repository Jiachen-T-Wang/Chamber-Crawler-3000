#include "header.h"

Dragon::Dragon(DragonHoard* hoard)
: Enemy{150, 20, 20, "Dragon"}, hoard{hoard} {}


DragonHoard* Dragon::getHoard(){
    return hoard;
}

bool Dragon::isDragon(){
   return true;
}

void Dragon::move(){}

char Dragon::symbol() {return 'D';}

