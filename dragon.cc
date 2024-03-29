#include "header.h"

Dragon::Dragon(DragonHoard* hoard)
: Enemy{150, 20, 20, "Dragon"}, hoard{hoard} {}

Dragon::Dragon()
: Enemy{150, 20, 20, "Dragon"}, hoard{nullptr} {}

DragonHoard* Dragon::getHoard(){
    return hoard;
}

void Dragon::setHoard(DragonHoard* hoard){
    this->hoard = hoard;
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
        getPos()->setCont(nullptr);
        getPos()->notifyDead();
    }
}

