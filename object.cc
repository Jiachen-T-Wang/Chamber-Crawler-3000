#include "header.h"
#include <memory>


Object::Object(): position{nullptr} {}

Cell* Object::getPos(){
   return position;
}

void Object::setPos(Cell* p){
   position = p;
}

bool Object::isEnemy(){
   return false;
}

bool Object::isPlayer(){
   return false;
}

bool Object::isStair(){
   return false;
}

bool Object::isPotion(){
   return false;
}

bool Object::isTreasure(){
   return false;
}

bool Object::isDragon(){
    return false;
}