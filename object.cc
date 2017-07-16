#include "object.h"

Object::Object(): position{nullptr} {}

void Object::setPosition(Cell* p){
	position = p;
}

Cell* Object::getPosition(){
	return position;
}
