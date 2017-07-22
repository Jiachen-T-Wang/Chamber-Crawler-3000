#include <cmath>
#include "header.h"

Human::Human()
	: Enemy{140, 20, 20, "Human"} {
        gold = make_shared<NormalHoard>();
    }

void Human::beAtkBy(std::shared_ptr<Player> p){
    p->attack(std::shared_ptr<Human>(this));
    if(checkDead()){
        if(p->race == "Goblin"){
            p->incScore(5);
        }
        getPos()->setCont(gold);
        while (1){
            int d = rand() % 8;
            Cell* nb = getPos()->getNeighbour(numToDir(d));
            if(!(nb->getContent())){
                nb->setCont(make_shared<NormalHoard>());
                nb->notifyGold();
                break;
            }
        }
        getPos()->notifyDead();
    }
}
