#include "floor.h"
#include <fstream>
#include <string>
#include "header.h"
using namespace std;

void Floor::addToChamber(Cell *c){
   int x = c->getCol();
   int y = c->getRow();
   if(x>=3 && x<=28 && y>=3 && y<=6) chambers[0]->addCell(c);
   else if((x>=39 && x<= 61 && y>=3 && y<=6) || (y==5 && x>=62 && x<=69) ||
           (y==6 && x>=62 && x<=72) || (x>=61 && x<=75 && y>=7 && y<=12))
      chambers[1]->addCell(c);
   else if((x>=65 && x<=75 && y>=16 && y<=18) ||
           (x>=37 && x<=75 && y>=19 && y<=21 )) chambers[2]->addCell(c);
   else if(x>=4 && x<= 24 && y>=15 && y<=21) chambers[3]->addCell(c);
   else if(x>=38 && x<= 49 && y>=10 && y<=12) chambers[4]->addCell(c);
   // cout << "add cell row "<< y<<" col "<<  x << endl;
}

std::shared_ptr<Chamber> Floor::randChamber(){
   //srand(time(NULL));
   int x=rand() % chamberNum;
   return chambers[x];
}

void Floor::createObjects(shared_ptr<Player>p){
   //first player
   srand(time(0));
   std::shared_ptr<Chamber> ch_player = randChamber();
   ch_player->addPlayer(p);
   
   //second stairway
   std::shared_ptr<Chamber> ch_stair = randChamber();
   while(ch_stair.get() == ch_player.get()) ch_stair = randChamber();
   ch_stair->addStair();
   
   for(int i=0; i<postionNum; i++){
      randChamber()->addPotion();
   }
   
   for(int i=0; i<goldNum; i++){
      randChamber()->addGold();
   }
   
   for(int i=0; i<enemyNum; i++){
      randChamber()->addEnemy();
   }
}




void Floor::addNeighbours(Cell &c, Dir dir, int row, int col){
   try{
      c.attachNeighbour(dir, &board.at(row).at(col));
   } catch(out_of_range){
      c.attachNeighbour(dir,nullptr);
   } // the cell at row, col is out of boundary
}




Floor::Floor(int l, Player *p, string fileName): level{l}, length{79}, height{25}{
  
  ifstream fs {fileName};
  string line;
  for (int i = 0; i < l; i++) getline(fs, line);
  int j=0;
  while(getline(fs, line)){
    vector <Cell> cellLine;
    for(int i=0; i< length; ++i){
      if (line[i] == '|' ||
          line[i] == '-' ||
          line[i] == '.' ||
          line[i] == '#' ||
          line[i] == '+' ||
          line[i] == ' ') {
        Cell c {j, i, line[i]};
        c.attach(td);
        cellLine.emplace_back(c);
      }
      else if (line[i] >= '0' && line[i] <= '5') {
        Cell c {j, i, '.'};
        shared_ptr<Potion> p = make_shared<Potion>(line[i] - '0');
        c.setCont(p);
        p->setPos(&c);
        c.attach(td);
        cellLine.emplace_back(c);
      }
      else if (line[i] >= '6' && line[i] <= '9') {
        Cell c {j, i, '.'};
        shared_ptr<Treasure> t;
        if(line[i] == '6') t = make_shared<NormalHoard>();
        else if(line[i] == '7') t = make_shared<SmallGold>();
        else if(line[i] == '8') t = make_shared<MerchantHoard>();
        else t = make_shared<DragonHoard>();
        c.setCont(t);
        t->setPos(&c);
        c.attach(td);
        cellLine.emplace_back(c);
      }
      else if (line[i] == 'H') {
        Cell c {j, i, '.'};
        shared_ptr<Human> h = make_shared<Human>();
        c.setCont(h);
        h->setPos(&c);
        c.attach(td);
        cellLine.emplace_back(c);
      }
      else if (line[i] == 'W') {
        Cell c {j, i, '.'};
        shared_ptr<Dwarf> w = make_shared<Dwarf>();
        c.setCont(w);
        w->setPos(&c);
        c.attach(td);
        cellLine.emplace_back(c);
      }
      else if (line[i] == 'E') {
        Cell c {j, i, '.'};
        shared_ptr<Elf> e = make_shared<Elf>();
        c.setCont(e);
        e->setPos(&c);
        c.attach(td);
        cellLine.emplace_back(c);
      }
      else if (line[i] == 'O') {
        Cell c {j, i, '.'};
        shared_ptr<Orcs> o = make_shared<Orcs>();
        c.setCont(o);
        o->setPos(&c);
        c.attach(td);
        cellLine.emplace_back(c);
      }
      else if (line[i] == 'M') {
        Cell c {j, i, '.'};
        shared_ptr<Merchant> m = make_shared<Merchant>();
        c.setCont(m);
        m->setPos(&c);
        c.attach(td);
        cellLine.emplace_back(c);
      }
      else if (line[i] == 'L') {
        Cell c {j, i, '.'};
        shared_ptr<Halfling> l = make_shared<Halfling>();
        c.setCont(l);
        l->setPos(&c);
        c.attach(td);
        cellLine.emplace_back(c);
      }
      else if (line[i] == 'D') {
        Cell c {j, i, '.'};
        shared_ptr<Dragon> d = make_shared<Dragon>();
        c.setCont(d);
        d->setPos(&c);
        c.attach(td);
        cellLine.emplace_back(c);
      }
      else if (line[i] == '\\') {
        Cell c {j, i, '.'};
        shared_ptr<Stair> s = make_shared<Stair>();
        c.setCont(s);
        s->setPos(&c);
        c.attach(td);
        cellLine.emplace_back(c);
      }
    }
    board.emplace_back(cellLine);
    j++;
  }
}



Floor::Floor(int l, shared_ptr<Player>p, bool enemyMove):level{l}, length{79}, height{25}, enemyMove{enemyMove}{
   
   p->setFloor(this);
   td = make_shared<TextDisplay>("emptyCC3K.txt", p, this);
   for(int i=0; i<chamberNum; ++i) {
      chambers.emplace_back(make_shared<Chamber>());
   }
   ifstream fs {"emptyCC3K.txt"};
   string line;
   int j=0;
   while(getline(fs, line)){
      vector <Cell> cellLine;
      for(int i=0; i< length; ++i){
         Cell c {j, i, line[i]};
         c.attach(td);
         cellLine.emplace_back(c);
      }
      board.emplace_back(cellLine);
      j++;
   }
   
   
   // link cell to corresponding chamber
   for(int i=0;i<height; i++) {
      for(int j=0; j<length; j++)
         addToChamber(&board[i][j]);
         }
   
   
   
   
   
   // add neighbors to cell
   for(int row=0; row<height; ++row){
      for (int col=0; col< length; ++col){
         Cell &cell =board[row][col];
         addNeighbours(cell, Dir::no, row-1, col);
         addNeighbours(cell, Dir::so, row+1, col);
         addNeighbours(cell, Dir::ea, row, col+1);
         addNeighbours(cell, Dir::we, row, col-1);
         addNeighbours(cell, Dir::ne, row-1, col+1);
         addNeighbours(cell, Dir::nw, row-1, col-1);
         addNeighbours(cell, Dir::se, row+1, col+1);
         addNeighbours(cell, Dir::sw, row+1, col-1);
         
      }
   }
   
   // randomly create objects on the floor
   createObjects(p);
   display();
}




int Floor::getLevel(){return level;}

void Floor::gothroughBoard(shared_ptr<Player>p){
   for(int i=0; i<height; i++){
      for(int j=0; j<length; j++){
         Cell &cell = board[i][j];
         shared_ptr<Object> o=cell.getContent();
         if(o.get()==nullptr) continue;
         else if(o->isEnemy()) {
            Enemy *e =(Enemy *)o.get();
            if(p->getPos()->isNeighbour(e->getPos())){
               p->beAtkBy(e);
               //dragon
               
            } else if(e->isDragon()){
               Dragon *d = (Dragon*)e;
               DragonHoard *h = d->getHoard();
               if(p->getPos()->isNeighbour(h->getPos()))
                  p->beAtkBy(e);
            
            }else {
               if(e->canMove() && enemyMove) e->move();
            }
            //   e.reset(static_cast<Object*>(e.get()));//cast back
         }
      }
   }
   // enable enemies to move
   
   for(int i=0; i<height; i++){
      for(int j=0; j<length; j++){
         Cell &cell = board[i][j];
         shared_ptr<Object> o=cell.getContent();
         if(o.get()==nullptr) continue;
         else if(o->isEnemy()) {
            Enemy *e =(Enemy *)o.get();
            e->enableMove();
         }
      }
   }
}



void Floor::display() {
   
   td->displayBoard();
}

bool Floor::getEnemyMove(){
   return enemyMove;
}
void Floor::changeEnemyMove(){
   enemyMove = !enemyMove;
}






