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
#include "stair.h"
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

std::weak_ptr<Object> Cell::getContent(){
   return content;
}

void Cell::setCont(std::shared_ptr<Object> o){
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


void Cell::attachNeighbour(Dir dir, std::shared_ptr<Cell> c){
   neighbours[dir]=c;
}

<<<<<<< HEAD
std::shared_ptr<Cell> Cell::getNeighbour(Dir dir){
   
=======
Cell* Cell::getNeighbour(Dir dir){
>>>>>>> 6ebfa93a9337091e3a8fb67c3f1d9c71141a7d7a
   return neighbours[dir];
}

void Cell::spawnPlayer(std::shared_ptr<Player> p){
   p->setPos(std::shared_ptr<Cell>(this));
}

void Cell::spawnStair(){
   Stair *s = new Stair();
   s->setPos(this);
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

bool Cell::isNeighbour(Cell *c1, Cell *c2){
   int rowDiff = c1->row - c2->row;
   int colDiff = c1->col - c2->col;
   return (rowDiff>=-1 && rowDiff<=1 && colDiff>=-1 && colDiff<=1);
}







