#include <cstdlib>
#include <cmath>
#include "character.h"
using namespace std;

bool Character::moveTo(string dir){
   position->
}

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

void Character::hurt(int damage){
	HP -= damage;
}


bool Character::checkDead(){
  return (HP <= 0);
}
