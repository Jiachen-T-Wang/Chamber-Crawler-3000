#include "merchant.h"

Merchant::Merchant(): Enemy{30, 70, 5, "Merchant"} {
    gold = make_shared<MerchantHoard>();
}

void Merchant::attack(Player* p){
	if(angry){
		Enemy::attack(Player* p)
	}
	else{
		Enemy::move();
	}
}

//static 咋玩
void Merchant::beAtkBy(Player* p){
    Player::beAtkBy(p);
	angry = true;
}

