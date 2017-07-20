#include "object.h"
#include "cell.h"
Object::Object(): position{nullptr} {}

void Object::setPos(Cell* p){
   position->setCont(nullptr);
   position = p;
   p->setCont(this);
}

Cell* Object::getPos(){
   return position;
}
