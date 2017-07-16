#include <iostream>
#include <cmath>
#include "enemy.h"

Enemy::Enemy(int HP, int atk, int def)
	: Character{HP, atk, def}, moveable{false} {}

bool Enemy::canMove(){ return moveable; }

void Enemy::attack(Player* p){
	p->beAtkBy(this);
}

//如果死了 通知TD
//Damage(Defender) = ceiling((100/(100+Def(Defender)))*Atk(Attacker))
void Enemy::beAtkBy(Player* p){
	int damage = ceil((100/(100+getDef())) * getAtk(p));
	getHurt(damage);
	if(checkDead()){
		position->notifyDead();
	}
}

Enemy::~Enemy() {}

