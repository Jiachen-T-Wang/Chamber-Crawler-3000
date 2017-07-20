#include <cstdlib>
#include <cmath>
#include "character.h"

Character::Character(int HP, int atk, int def)
: Object{}, HP{HP}, atk{atk}, def{def} {}

int Character::getHP(){
  return HP;
}

int Character::getAtk(){
  return atk;
}

int Character::getDef(){
  return def;
}

void Character::getHurt(int damage){
	HP = HP - damage;
}


bool Character::checkDead(){
  return (HP <= 0);
}
