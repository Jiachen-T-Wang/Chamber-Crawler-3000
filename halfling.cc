#include "header.h"

Halfling::Halfling(): Enemy{100, 15, 20, "Halfling"} {}

void Halfling::beAtkBy(std::shared_ptr<Player> p){
    p->attack(std::shared_ptr<Halfling>(this));
    if(checkDead()){
        if(p->race == "Goblin"){
            p->incScore(5);
        }
        getPos()->setCont(gold);
        getPos()->notifyDead();
    }
}

char Halfling::symbol(){return 'L';}
