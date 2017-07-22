#include "object.h"
#include "cell.h"
#include <memory>


Object::Object(): position{nullptr} {}

Cell* Object::getPos(){
   return position;
}


void Object::setPos(Cell* p){
   if(position) position->setCont(std::shared_ptr<Object>(nullptr));
   position = p;
   p->setCont(std::shared_ptr<Object>(this));
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
