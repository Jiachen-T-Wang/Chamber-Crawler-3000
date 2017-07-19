#include <iostream>
#include <cstdlib>
#include "enemy.h"

Enemy::Enemy(int HP, int atk, int def)
	: Character{HP, atk, def}, moveable{false} {}

bool Enemy::canMove(){ return moveable; }

int Enemy::calcDamage(Player* attacker){
  return ceil((100/(100+this->getDef())) * attacker->realAtk());
}

void Enemy::attack(Player* p){
	int notMiss = rand() % 2;
	if (notMiss){
		p->beAtkBy(this);
	}
	else{
		getPosition()->notyfyMiss();
	}
}

//如果死了 通知TD
void Enemy::beAtkBy(Player* p){
	int damage = calcDamage(p);
	getHurt(damage);
	if(checkDead()){
		getPosition()->setCont() = nullptr;
		getPosition()->notifyDead();
	}
}

Enemy::~Enemy() {}

