#include <cmath>
#include "player.h"
#include "enemy.h"
#include "enemies/halfling.h"
#include "character.h"
#include "Treasure/treasure.h"
using namespace std;

Player::Player(int HP, int atk, int def, int maxHP, std::shared_ptr<Floor> f, std::string race)
: Character{HP, atk, def}, maxHP{maxHP}, atkEffect{0}, defEffect{0}, f{f}, score{0}, race{race} {}

int Player::getMaxHP() const { return maxHP; }


bool Player::isPlayer() { return true;}

void Player::addHp(int hpEffect) {
  HP = (getHP() + hpEffect > maxHP) ? maxHP : getHP() + hpEffect;
}

void Player::resetEffect(){
    atkEffect = 0;
    defEffect = 0;
}

// Basic Implementation
void Player::usePotion(Potion* p){
   string type = p->getType();
   int effect =p->getEffect();
  if (type == "Hp") addHp(effect);
  else if (type == "Atk") atkEffect += (effect);
  else if (type == "Def") defEffect += (effect);
}

void Player::moveTo(Dir dir){
    Character::moveTo(dir);
    getPos()->notifyPlayerMove(dir);
}




int Player::realAtk(){
  return (getAtk() + atkEffect < 0) ? 0 : getAtk() + atkEffect;
}

int Player::realDef(){
  return (getDef() + defEffect < 0) ? 0 : getDef() + defEffect;
}

int Player::calcDamage(std::shared_ptr<Enemy> defender){
    return ceil((100/(100+defender->getDef())) * this->realAtk());
}


void Player::attack(std::shared_ptr<Enemy> enemy){
	int damage = calcDamage(enemy);
	enemy->getHurt(damage);
	getPos()->notifyPlayerAttack(damage);
}

void Player::attack(std::shared_ptr<Halfling> h){
	int notMiss = rand() % 2;  
	if (notMiss){
        int damage = calcDamage(h);
		h->getHurt(damage);
		getPos()->notifyPlayerAttack(damage);
	}
	else{
		getPos()->notifyMiss();
	}
}


void Player::beAtkBy(std::shared_ptr<Enemy> enemy){
    enemy->attack(std::shared_ptr<Player>(this));
}




int Player::showScore(){ return score; }

void Player::incScore(int value){ score += value; }

void Player::PickGold(std::shared_ptr<Treasure> gold){
	incScore(gold->getValue());
    shared_ptr<Cell> newp = gold->getPos();
    newp->setCont(nullptr);
}

void Player::roundChange(){}

Player::~Player() {}
