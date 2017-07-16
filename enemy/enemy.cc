#include <iostream>
#include <cstdlib>
#include "enemy.h"

Enemy::Enemy(int HP, int atk, int def)
	: Character{HP, atk, def}, moveable{false} {}

bool Enemy::canMove(){ return moveable; }

void Enemy::attack(Player* p){
	int notMiss = rand() % 2;
	if (notMiss){
		p->beAtkBy(this);
	}
	else{
		//攻击miss, notify TD 
	}
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

