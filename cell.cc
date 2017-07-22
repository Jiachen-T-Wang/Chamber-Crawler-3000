#include <vector>
#include "header.h"
using namespace std;

Cell::Cell(int row, int col, char c): row{row}, col{col}, content{nullptr}{
   if (c == '.') type = CellType::Tile;
      else if ( c == '-') type = CellType::Wall;
         else if (c == '|') type = CellType::WallVertical;
            else if (c == '+') type = CellType::Doorway;
               else if (c == '#') type = CellType::Passage;
                  else if (c == ' ') type = CellType::Empty;
                     }

int Cell::getCol(){
   return col;
}

int Cell::getRow(){
   return row;
}

std::shared_ptr<Object> Cell::getContent(){
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


void Cell::attachNeighbour(Dir dir, Cell* c){
   neighbours[dir]=c;
}

Cell* Cell::getNeighbour(Dir dir){
   return neighbours[dir];
}

void Cell::spawnPlayer(std::shared_ptr<Player> p){
   p->setPos(this);
}

void Cell::spawnStair(){
   Stair *s = new Stair();
   s->setPos(this);
}

void Cell::spawnEnemy(){
   srand(time(0));
   int x=rand() % 18;
   shared_ptr<Enemy> e(nullptr);
   if(x>=0 && x<4) e = make_shared<Human>();
   else if(x>=4 && x<7) e = make_shared<Dwarf>();
   else if(x>=7 && x<12) e = make_shared<Halfling>();
   else if(x>=12 && x<14) e = make_shared<Elf>();
   else if(x>=14 && x<16) e = make_shared<Orcs>();
   else e = make_shared<Merchant>();
   e->setPos(this);
}

void Cell::spawnPotion(){
   srand(time(0));
   int x=rand() % 6;
   shared_ptr<Potion> p;
   if(x==0) p = make_shared<Potion>(10, "Hp");
   else if(x==1) p = make_shared<Potion>(-10, "Hp");
   else if(x==2) p = make_shared<Potion>(5, "Atk");
   else if(x==3) p = make_shared<Potion>(-5, "Atk");
   else if(x==4) p = make_shared<Potion>(5, "Def");
   else p = make_shared<Potion>(-5, "Def");
   p->setPos(this);
}

void Cell::spawnGold(){
   srand(time(0));
   int x=rand() % 8;
   shared_ptr<Treasure> t;
   if(x==0) t = make_shared<DragonHoard>();
   if(x==1 || x==2) t = make_shared<SmallGold>();
   else t = make_shared<NormalHoard>();
   t->setPos(this);
}

bool Cell::isNeighbour(Cell *c){
   int rowDiff = this->row - c->row;
   int colDiff = this->col - c->col;
   return (rowDiff>=-1 && rowDiff<=1 && colDiff>=-1 && colDiff<=1);
}

char Cell::getSymbol(){
   if(content.get()!=nullptr){
      return content->symbol();
   }
   else if(type==CellType::Tile) return '.';
   else if(type==CellType::Doorway) return '+';
   else if(type==CellType::Empty) return ' ';
   else if(type==CellType::Passage) return '#';
   else if(type==CellType::Wall) return '-';
   else if(type==CellType::WallVertical) return '|';
}





