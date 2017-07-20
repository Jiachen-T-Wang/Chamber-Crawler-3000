#include "cell.h"
#include "cellType.h"
#include <vector>
using namespace std;

Cell::Cell(int row, int col, char c): row{row}, col{col}, content{nullptr}{
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

bool Cell::canStand() {
  if (type == CellType::Tile||
      type == CellType::Doorway ||
      type == CellType::Passage) return true;
  return false;
}

bool Cell::canStandByAll() {
  if (type == CellType::Tile) return true;
  return false;
}

void Cell::notify(){
   }

void Cell::attachNeighbour(Dir dir, Cell *c){
   neighbours[dir]=c;
}
Cell *Cell::getNeighbour(Dir dir){
   return neighbours[dir];
}
