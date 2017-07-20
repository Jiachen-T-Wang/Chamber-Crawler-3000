#include "cell.h"
#include "cellType.h"
#include <vector>
Cell::Cell(int x, int y, char c): x{x}, y{y}, content{nullptr}{
   if (c == '.') type = CellType::Tile;
   else if (c == '|' || c == '-') type = CellType::Wall;
   else if (c == '+') type = CellType::Doorway;
   else if (c == '#') type = CellType::Passage;
   else if (c == '\\') type = CellType::Stairway;
   else if (c == ' ') type = CellType::Empty;
}

Object* Cell::getContent(){
	return content;
}

void Cell::setCont(Object* o){
	content = o;
}

bool Cell::getCanStand() {
  if (type == CellType::Tile||
      type == CellType::Doorway ||
      type == CellType::Passage) return true;
  return false;
}

bool Cell::getCanStandByAll() {
  if (type == CellType::Tile) return true;
  return false;
}

void Cell::notify(Player *p){
   content->attack(p);
}
void Cell::attachNeighbour(Cell *c){
   neighbours.emplace_back(c);
}
