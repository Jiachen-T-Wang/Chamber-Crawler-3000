#include <cmath>
#include "human.h"

Human::Human()
	: Enemy{140, 20, 20, "Human"} {
        gold = make_shared<NormalHoard>();
    }

void Human::beAtkBy(Player* p){
    p->attack(this);
    if(checkDead()){
        if(p->race == "Goblin"){
            p->incScore(5);
        }
        getPos()->setCont(gold);
        getPos()->notifyDead();
    }
}