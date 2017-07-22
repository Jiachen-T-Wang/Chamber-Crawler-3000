#include "merchant.h"

Merchant::Merchant(): Enemy{30, 70, 5, "Merchant"} {
    gold = make_shared<MerchantHoard>();
}

void Merchant::attack(std::shared_ptr<Player> p){
	if(angry){
		Enemy::attack(std::shared_ptr<Player> p)
	}
	else{
		Enemy::move();
	}
}

//static 咋玩
void Merchant::beAtkBy(std::shared_ptr<Player> p){
    Player::beAtkBy(p);
	angry = true;
}

