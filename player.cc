#include <cmath>
#include "header.h"
using namespace std;

Player::Player(int HP, int atk, int def, int maxHP, Floor* f, std::string race)
: Character{HP, atk, def}, maxHP{maxHP}, atkEffect{0}, defEffect{0}, f{f}, score{0}, race{race} {}

int Player::getMaxHP() const { return maxHP; }

void Player::setAtkEffect(int effect){
    atkEffect += effect;
}
void Player::setDefEffect(int effect){
    defEffect += effect;
}

bool Player::isPlayer() { return true;}
//bool Player::isEnemy() {return false;}

void Player::addHp(int hpEffect) {
  HP = (getHP() + hpEffect > maxHP) ? maxHP : getHP() + hpEffect;
}

void Player::resetEffect(){
    atkEffect = 0;
    defEffect = 0;
}

// Basic Implementation
void Player::usePotion(std::shared_ptr<Potion> p){
   string type = p->getType();
   int effect =p->getEffect();
  if (type == "Hp") addHp(effect);
  else if (type == "Atk") atkEffect += (effect);
  else if (type == "Def") defEffect += (effect);
}

void Player::moveTo(Dir dir){
    Cell* nb = getPos()->getNeighbour(dir);
    shared_ptr<Object> cont = nb->getContent();
    if(cont && cont->isTreasure()){//cont.get()
        shared_ptr<Treasure> gd;
        gd.reset((Treasure*)cont.get());
        this->PickGold(gd);
    }
    Character::moveTo(dir);
    getPos()->notifyPlayerMove(dir);
}

int Player::showFloor(){
    return f->getLevel();
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
	getPos()->notifyPlayerAttack(enemy, damage);
}

void Player::attack(Halfling* h){
	int notMiss = rand() % 2;  
	if (notMiss){
        int damage = calcDamage(h);
		h->getHurt(damage);
		getPos()->notifyPlayerAttack(h, damage);
	}
	else{
		getPos()->notifyMiss();
	}
}


void Player::beAtkBy(Enemy* enemy){
    enemy->attack(std::shared_ptr<Player>(this));
}

void Player::setFloor(Floor* f){
    this->f = f;
}

int Player::showScore(){ return score; }

void Player::incScore(int value){ score += value; }

void Player::PickGold(std::shared_ptr<Treasure> gold){
	incScore(gold->getValue());
    Cell* newp = gold->getPos();
    newp->setCont(nullptr);
}

void Player::roundChange(){}

char Player::symbol(){return '@';}

Player::~Player() {}
