#include "cell.h"

Cell::Cell(int x, int y, char c): x{x}, y{y}, content{nullptr}{
   if (c == '.') type = "Tile";
   else if (c == '|' || c == '-') type = "Wall";
   else if (c == '+') type = "Doorway";
   else if (c == '#') type = "Passage";
   else if (c == '\\') type = "Stairway";
   else if (c == ' ') type = "Empty";
}

//if the enemy dead (没经过notify observer, 因为没有其它observer，除了TD，不然太麻烦了)
/*
void Cell::notifyDead(){
   setCont = nullptr;
   Observers[TD]->notify(this);
}

void Cell::notify(Object* o){
	o->setPosition(this);
	setCont() = o;
	Observers[TD]->notify(this);
}
*/
Object* Cell::getContent(){
	return content;
}

void Cell::setCont(Object* o){
	content = o;
}

bool getCanStand() {
  if (type == "Tile" ||
      type == "Doorway" ||
      type == "Passage") return true;
  return false;
}

bool getCanStandByAll() {
  if (type == "Tile") return true;
  return false;
}

