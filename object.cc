#include "object.h"
#include "cell.h"
Object::Object(): position{nullptr} {}

Cell* Object::getPos(){
   return position;
}


void Object::setPos(Cell* p){
   if(position) position->setCont(nullptr);
   position = p;
   p->setCont(this);
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
