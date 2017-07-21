#include "cell.h"
#include "cellType.h"
#include <vector>
#include "enemies/dragon.h"
#include "enemies/dwarf.h"
#include "enemies/elf.h"
#include "enemies/halfling.h"
#include "enemies/human.h"
#include "enemies/merchant.h"
#include "enemies/orcs.h"
#include "potion.h"
#include "treasure/dragonHoard.h"
#include "treasure/smallGold.h"
#include "treasure/normalhoard.h"
#include "object.h"
using namespace std;

Cell::Cell(int row, int col, char c): row{row}, col{col}, content{nullptr}{
   if (c == '.') type = CellType::Tile;
      else if (c == '|' || c == '-') type = CellType::Wall;
         else if (c == '+') type = CellType::Doorway;
            else if (c == '#') type = CellType::Passage;
               else if (c == '\\') type = CellType::Stairway;
                  else if (c == ' ') type = CellType::Empty;
                     }

int Cell::getCol(){
   return col;
}

int Cell::getRow(){
   return row;
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

void Cell::spawnEnemy(){
   srand(time(0));
   int x=rand() % 18;
   Enemy *e = nullptr;
   if(x>=0 && x<4) e = new Human;
   else if(x>=4 && x<7) e = new Dwarf;
   else if(x>=7 && x<12) e = new Halfling;
   else if(x>=12 && x<14) e = new Elf;
   else if(x>=14 && x<16) e = new Orcs;
   else e = new Merchant;
   e->setPos(this);
}

void Cell::spawnPotion(){
   srand(time(0));
   int x=rand() % 6;
   Potion *p = nullptr;
   if(x==0) p = new Potion{10, "Hp"};
   else if(x==1) p = new Potion{-10, "Hp"};
   else if(x==2) p = new Potion{5, "Atk"};
   else if(x==3) p = new Potion{-5, "Atk"};
   else if(x==4) p = new Potion{5, "Def"};
   else p = new Potion{-5, "Def"};
   p->setPos(this);
}

void Cell::spawnGold(){
   srand(time(0));
   int x=rand() % 8;
   Treasure *t = nullptr;
   if(x==0) t = new DragonHoard;
   if(x==1 || x==2) t = new SmallGold;
   else t = new NormalHoard;
   t->setPos(this);
}









