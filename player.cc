#include <cmath>
#include "player.h"
#include "character.h"

Player::Player(int HP, int atk, int def, int maxHP, Floor* f, std::string race)
: Character{HP, atk, def}, maxHP{maxHP}, atkEffect{0}, defEffect{0}, f{f},
score{0}, race{race} {}

int Player::getMaxHP() const { return maxHP; }

void Player::addHp(int hpEffect) {
  HP = (getHP() + hpEffect > maxHP) ? maxHP : getHP() + hpEffect;
}

void Player::move(int dir){
	Cell* curP = getPosition();
	curP->notifyMove(this, int dir);
}




// Basic Implementation
void Player::usePotion(Potion* p){
  if (p->getType() == "Hp") addHp(p->getEffect());
  else if (p->getType() == "Atk") atkEffect += (p->getEffect());
  else if (p->getType() == "Def") defEffect += (p->getEffect());
}




int Player::realAtk(){
  return (getAtk() + atkEffect < 0) ? 0 : getAtk() + atkEffect;
}

int Player::realDef(){
  return (getDef() + defEffect < 0) ? 0 : getDef() + defEffect;
}

int Player::calcDamage(Enemy* defender){
  return ceil((100/(100+defender->getDef())) * this->realAtk());
}


void Player::attack(Enemy* enemy){
	int damage = calcDamage(enemy);
	enemy->getHurt(damage);
	getPosition()->notifyPlayerAttack(damage);
}

void Player::attack(Halfling* h){
	int notMiss = rand() % 2;  
	if (notMiss){
		int damage = calcDamage(h);
		h->getHurt(damage);
		getPosition()->notifyPlayerAttack(damage);
	}
	else{
		getPosition()->notyfyMiss();
	}
}


void Player::beAtkBy(Enemy* enemy){

	enemy->attack(this);
	
	if(checkDead()){
		//游戏结束
	}
}




int showScore(){ return score; }

void incScore(int value){ score += value; }

void Player::PickGold(Treasure* gold){
	intScore(gold->getValue());
}

void Player::roundChange(){}

Player::~Player() {}
