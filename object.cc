#include "object.h"
#include "cell.h"
Object::Object(): position{nullptr} {}

void Object::setPosition(Cell* p){
   position = p;
   p->setCont(this);
}

Cell* Object::getPosition(){
   return position;
}
