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
   else if((x>=65 && x<=75 && x>=16 && x<=18) ||
           (x>=37 && x<=75 && y>=19 && y<=21 )) chambers[2]->addCell(c);
   else if(x>=4 && x<= 24 && y>=15 && y<=21) chambers[3]->addCell(c);
   else if(x>=38 && x<= 49 && y>=10 && y<=12) chambers[4]->addCell(c);
}

std::shared_ptr<Chamber> Floor::randChamber(){
   srand(time(0));
   int x=rand() % chamberNum;
   return chambers[x];
}

void Floor::createObjects(shared_ptr<Player>p){
   //first player
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



/*
 Floor::Floor(int l, Player *p, string fileName){
 
 }
 */


Floor::Floor(int l, shared_ptr<Player>p):level{l}, length{79}, height{25}{
   
   auto td = make_shared<TextDisplay>("emptyCC3K.txt", p, this);
   for(int i=0; i<chamberNum; ++i) {
       chambers.emplace_back(make_shared<Chamber>());
   }
   ifstream fs {"emptyCC3K.txt"};
   string line;
   int j=0;
   while(getline(fs, line)){
      vector <Cell> cellLine;
      for(int i=0; i< length; ++i){
         Cell c {i, j, line[i]};
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
   for(auto cellLine:board){
      for(auto cell:cellLine){
         shared_ptr<Object> o = cell.getContent();
         if(o.get()==nullptr) continue;
         else if(o->isEnemy()) {
            shared_ptr<Enemy> e;
            e.reset((Enemy*)o.get());
            if(p->getPos()->isNeighbour(e->getPos())){
               p->beAtkBy(e);
            } else if(e->isDragon()){
               shared_ptr<Dragon> d;
               d.reset((Dragon*)o.get());
               shared_ptr<DragonHoard> h {d->getHoard()};
               if(p->getPos()->isNeighbour(h->getPos()))
                  p->beAtkBy(d);
            }else {
               if(e->canMove()) e->move();
            }
         }
      }
   }
   // enable enemies to move
   for(auto cellLine:board){
      for(auto cell:cellLine){
         shared_ptr<Object> o = cell.getContent();
         if(o.get()==nullptr) continue;
         else if(o->isEnemy()) {
            shared_ptr<Enemy> e;
            e.reset((Enemy*)o.get());
            e->enableMove();
         }
      }
   }
}



void Floor::display() {
  
   td->displayBoard();
}






