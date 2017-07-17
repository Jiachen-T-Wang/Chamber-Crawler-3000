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

//
void Player::attack(int dir){
	Cell* curP = getPosition();
	curP->notifyEnemy(this, dir);
}

void Player::beAtkBy(Enemy* enemy){
	int damage = ceil((100/(100+getDef())) * getAtk(enemy));
	getHurt(damage);
	if(checkDead()){
		//游戏结束
	}
}

void Player::PickGold(){
	
}

void Player::roundChange(){}

Player::~Player() {}
