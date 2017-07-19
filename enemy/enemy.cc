#include <iostream>
#include <cstdlib>
#include "enemy.h"
using namespace std;

Enemy::Enemy(int HP, int atk, int def, string type)
	: Character{HP, atk, def}, moveable{false}, type{type} {}

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
		if(p->race == "Goblin"){
			p->incScore(5);
		}
		getPosition()->setCont() = nullptr;
		getPosition()->notifyDead();
	}
}

Enemy::~Enemy() {}

