#include <cmath>
#include "player.h"
#include "character.h"

Player::Player(int HP, int atk, int def, int maxHP, Floor* f, std::string race)
: Character{HP, atk, def}, maxHP{maxHP}, atkEffect{0}, defEffect{0}, f{f},
score{0}, race{race} {}

int Player::getMaxHP() const { return maxHP; }

void Player::addHp(int hpEffect) {
  HP = (getHP() + hpEffect > maxHP) ? maxHP : getHP() + hpEfect;
}

void Player::move(int dir){
	Cell* curP = getPosition();
	curP->notifyObservers(this, int dir);
}




// Basic Implementation
void Player::usePotion(Potion* p){
  if (p->type == "Hp") addHp(p->effect);
  else if (p->type == "Atk") atkEffect += (p->effect);
  else if (p->type == "Def") defEffect += (p->effect);
}





int Player::realAtk(){
  return (getAtk() + atkEffect < 0) ? 0 : getAtk() + atkEffect;
}

int Player::realDef(){
  return (getDef() + defEffect < 0) ? 0 : getDef() + defEffect;
}

int Player::calcDamage(Enemy* attacker){
  return ceil((100/(100+this->realDef())) * attacker->getAtk());
}

void Player::attack(int dir){
	Cell* curP = getPosition();
	curP->notifyEnemy(this, dir);
}

void Player::beAtkBy(Enemy* enemy){
	int damage = calcDamage(enemy);
	getHurt(damage);
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
