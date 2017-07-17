#include "cell.h"

Cell::Cell(int x, int y, char c): x{x}, y{y}, content{nullptr}{
   if (c == '.') Tile(x, y);
   else if (c == '|' || c == '-') Wall(x, y);
   else if (c == '+') Doorway(x, y);
   else if (c == '#') Passage(x ,y);
   else if (c == '\\') Stairway(x, y);
   else if (c == ' ') Empty(x, y);
}

//if the enemy dead (没经过notify observer, 因为没有其它observer，除了TD，不然太麻烦了)
void Cell::notifyDead(){
   setCont = nullptr;
   Observers[TD]->notify(this);
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



