#include "cell.h"

Cell::Cell(int x, int y, char c): x{x}, y{y}, content{nullptr}{
   if (c == '.') type = "tile";
   else if (c == '|' || c == '-') type = "wall";
   else if (c == '+') type = "doorway";
   else if (c == '#') type = "passage";
   else if (c == '\\') type = "stairway";
   else if (c == ' ') type = "empty";
}

void Cell::notify(Object* o){
	o->setPosition(this);
	setCont() = o;
	Observers[TD]->notify(this);
}

Object* Cell::getContent(){
	return content;
}

void Cell::getCont(Object* o){
	content = o;
}



