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
    p->attack(this);
	angry = true;
}

char Merchant::symbol(){return 'M';}

