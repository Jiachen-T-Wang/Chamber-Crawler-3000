#include "header.h"

Merchant::Merchant(): Enemy{30, 70, 5, "Merchant"} {
    gold = make_shared<MerchantHoard>();
}

void Merchant::attack(std::shared_ptr<Player> p){
	if(angry){
        Enemy::attack(p);
	}
	else{
		Enemy::move();
	}
}

//static 咋玩
void Merchant::beAtkBy(std::shared_ptr<Player> p){
    p->attack(std::shared_ptr<Merchant>(this));
	angry = true;
}

char Merchant::symbol(){return 'M';}

