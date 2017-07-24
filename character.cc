#include <cstdlib>
#include <cmath>
#include "header.h"

using namespace std;

Dir Character::numToDir(int d){
   switch (d) {
      case 0:
         return Dir::no; break;
      case 1:
         return Dir::ne; break;
      case 2:
         return Dir::nw; break;
      case 3:
         return Dir::so; break;
      case 4:
         return Dir::sw; break;
      case 5:
         return Dir::se; break;
      case 6:
         return Dir::we; break;
      default:
         return Dir::ea;break;
   }
}
void Character::moveTo(Dir dir){
    Cell* neighbour = getPos()->getNeighbour(dir);
   if(neighbour->getContent().get() !=nullptr) return;
    neighbour->setCont(getPos()->getContent());
    getPos()->setCont(nullptr);
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
    if(HP-damage <= 0)
        HP = 0;
    else HP -= damage;
}


bool Character::checkDead(){
  return (HP == 0);
}
/*
bool Character::isEnemy(){
    return false;
}

bool Character::isPlayer(){
    return false;
}
 */
