#include "merchant.h"

Merchant::Merchant(): Enemy{30, 70, 5, "Merchant"} {}

void Merchant::attack(Player* p){
	if(angry){
		Enemy::attack(Player* p)
	}
	else{
		Enemy::move();
	}
}

void Merchant::beAtkBy(Player* p){
    Player::beAtkBy(p);
//	angry = true;
    
}

