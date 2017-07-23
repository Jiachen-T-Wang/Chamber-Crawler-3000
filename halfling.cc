#include "header.h"

Halfling::Halfling(): Enemy{100, 15, 20, "Halfling"} {}

void Halfling::beAtkBy(std::shared_ptr<Player> p){
    p->attack(this);
    if(checkDead()){
        if(p->race == "Goblin"){
            p->incScore(5);
        }
        gold->setPos(getPos());
        getPos()->notifyDead();
    }
}

char Halfling::symbol(){return 'L';}
