#include "object.h"
#include "cell.h"
#include <memory>


Object::Object(): position{nullptr} {}

std::shared_ptr<Cell> Object::getPos(){
   return position;
}


void Object::setPos(std::shared_ptr<Cell> p){
   if(position) position->setCont(nullptr);
   position = p;
   p->setCont(shared_from_this());
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
