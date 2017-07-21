#include <iostream>
#include <cstdlib>
#include "enemy.h"
using namespace std;

Enemy::Enemy(int HP, int atk, int def, string type)
	: Character{HP, atk, def}, moveable{false}, type{type} {}

bool Enemy::canMove(){ return moveable; }

void Enemy::move(){
	getPosition()->notifyMove(this);
}

int Enemy::calcDamage(Player* defender){
  return ceil((100/(100+defender->realDef())) * this->getAtk());
}

int Enemy::calcDamage(Goblin* defender){
	calcDamage(defender);
}

void Enemy::attack(Player* player){
	int notMiss = rand() % 2;  
	if (notMiss){
		int damage = calcDamage(player);
		player->getHurt(damage);
		getPosition()->notifyEnemyAttack(damage);
	}
	else{
		getPosition()->notyfyMiss();
	}
}

void Enemy::attack(Vampire* v){
	attack(v);
}

void Enemy::attack(Drow* d){
	attack(d);
}

void Enemy::attack(Goblin* g){
	attack(g);
}


//如果死了 通知TD
void Enemy::beAtkBy(Player* p){

	p->attack(this);

	if(checkDead()){
		if(p->race == "Goblin"){
			p->incScore(5);
		}
		getPosition()->setCont() = nullptr;
		getPosition()->notifyDead();
	}
}

Enemy::~Enemy() {}

