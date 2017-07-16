#include <iostream>
#include "enemy.h"

Enemy::Enemy(int HP, int atk, int def)
	: Character{HP, atk, def}, moveable{false} {}

bool Enemy::canMove(){ return moveable; }

void Enemy::attack(Player* p){
	p->beAtkBy(this);
}

//如果死了 通知TD
void Enemy::beAtkBy(Player* p){
	int damage = calcDamage(p, this);
	getHurt(damage);
	if(checkDead()){
		position->notifyDead();
	}
}

Enemy::~Enemy() {}

