#include "header.h"

Halfling::Halfling(): Enemy{100, 15, 20, "Halfling"} {}

void Halfling::beAtkBy(Player* p){
    p->attack(this);
    if(checkDead()){
        if(p->race == "Goblin"){
            p->incScore(5);
        }
        gold->setPos(getPos());
        getPos()->setCont(gold);
        getPos()->notifyDead();
    }
}

char Halfling::symbol(){return 'L';}
