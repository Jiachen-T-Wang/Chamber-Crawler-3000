#include <cstdlib>
#include <cmath>
#include "character.h"

Character::Character(int HP, int atk, int def)
: Object{}, HP{HP}, atk{atk}, def{def}, atkEffect{0}, defEffect{0} {}

int Character::calcDamage(Character* attacker, Character* defender){
  return ceil((100/(100+defender->getDef())) * attacker->getAtk());
}

int Character::getHP(){
  return HP;
}

int Character::getAtk(){
  return (atk + atkEffect < 0) ? 0 : atk + atkEffect;
}

int Character::getDef(){
  return (def + defEffect < 0) ? 0 : def + defEffect;
}

void Character::move(){
  Cell* curP = getPosition();
  curP->notifyObservers(this);
}

void Character::checkDead(){
  return (HP <= 0);
}
