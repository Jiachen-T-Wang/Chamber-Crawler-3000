#include <cstdlib>
#include <cmath>
#include "character.h"

using namespace std;

void Character::moveTo(Dir dir){
    std::shared_ptr<Cell> neighbour = getPos()->getNeighbour(dir);
   if(neighbour->getContent()!=nullptr) return;
    setPos(neighbour);
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

void Character::getHurt(int damage){
	HP -= damage;
}


bool Character::checkDead(){
  return (HP <= 0);
}
