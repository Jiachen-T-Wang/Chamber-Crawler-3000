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

void Dragon::beAtkBy(Player* p){
    p->attack(this);
    if(checkDead()){
        if(p->race == "Goblin"){
            p->incScore(5);
        }
        hoard->removeDragon();
 //       gold->setPos(getPos());
        getPos()->setCont(nullptr);
        getPos()->notifyDead();
    }
}

