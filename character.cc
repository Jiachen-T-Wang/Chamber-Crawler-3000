#include <cstdlib>
#include <cmath>
#include "character.h"

using namespace std;

void Character::moveTo(Dir dir){
   Cell *neighbor = getPos()->getNeighbour(dir);
   setPos(neighbor);
   getPos()->notifyObservers();
}

int Character::getHP(){
   return HP;
}

int Character::getAtk(){
   return atk;
}

int Character::getDef(){
   return def;
}


Character::Character(int HP, int atk, int def):
Object{}, HP{HP}, atk{atk}, def{def} {}

void Character::hurt(int damage){
	HP -= damage;
}


bool Character::checkDead(){
  return (HP <= 0);
}
