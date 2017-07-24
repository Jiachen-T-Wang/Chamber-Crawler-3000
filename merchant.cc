#include "header.h"

Merchant::Merchant(): Enemy{30, 70, 5, "Merchant"} {
    gold = make_shared<MerchantHoard>();
}

void Merchant::attack(Player* p){
	if(angry){
        Enemy::attack(p);
	}
	else{
		Enemy::move();
	}
}

//static 咋玩
void Merchant::beAtkBy(Player* p){
    angry = true;
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

char Merchant::symbol(){return 'M';}

