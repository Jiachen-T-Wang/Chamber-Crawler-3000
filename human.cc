#include <cmath>
#include "header.h"

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
        gold->setPos(getPos());
        while (1){
            int d = rand() % 8;
            Cell* nb = getPos()->getNeighbour(numToDir(d));
            if(!(nb->getContent()) && nb->canStandByAll()){
                nb->setCont(make_shared<NormalHoard>());
                nb->notifyGold();
                break;
            }
        }
        getPos()->setCont(gold);
        getPos()->notifyDead();
    }
}

char Human::symbol(){return 'H';}
