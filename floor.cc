#include <vector>
#include "floor.h"
#include <iostream>
#include <fstream>
#include <string>
#include "cell.h"
#include "chamber.h"
using namespace std;

void Floor::addToChamber(Cell *c){
  int x = c->getCol();
  int y = c->getRow();
  if(x>=3 && x<=28 && y>=3 && y<=6) chambers[0]->addCell(c);
  else if((x>=39 && x<= 61 && y>=3 && y<=6) || (y==5 && x>=62 && x<=69) ||
          (y==6 && x>=62 && x<=72) || (x>=61 && x<=75 && y>=7 && y<=12))
    chamber[1]->addCell(c);
  else if((x>=65 && x<=75 && x>=16 && x<=18) ||
          (x>=37 && x<=75 && y>=19 && y<=21 )) chamber[2]->addCell(c);
  else if(x>=4 && x<= 24 && y>=15 && y<=21) chamber[3]->addCell(c);
  else if(x>=38 && x<= 49 && y>=10 && y<=12) chamber[4]->addCell(c);
  
}

Chamber *Floor::randChamber(){
  srand(time(0));
  int x=rand() % chamberNum;
  return chambers[x];
}

void Floor::createEnemy(){
  for(int i=0; i<enemyNum; i++){
    randChamber()->addEnemy();
  }
}

void Floor::createPotion(){
  for(int i=0; i<postionNum; i++){
    randChamber()->addPotion();
  }
}

void Floor::createGold(){
  for(int i=0; i<goldNum; i++){
    randChamber()->addGold();
  }
}

void Floor::addNeighbours(Cell &c, string dir, int row, int col){
   try{
      c.attachNeighbour(dir, &board.at(row).at(col));
   } catch(out_of_range){
      c.attachNeighbour(dir,nullptr);
   } // the cell at row, col is out of boundary
}

Floor::Floor(int l, string fileName):level{l}, length{79}, height{25}{
  td = new TextDisplay(fileName);
  for(int i=0; i<chamberNum; ++i) {
    chambers.emplace_back(new Chamber());
  }
  ifstream fs {fileName};
  string line;
  while(getline(fs, line)){
    vector <Cell> cellLine;
    for(int i=0; i< length; ++i){
      cellLine.emplace_back({i, height, line[i]});
    }
    board.emplace_back(cellLine);
    
    for(auto c: cellLine) { addToChamber(&c); }
  }
   for(int row=0; r<height; ++row){
      for (int col=0; c< length; ++col){
         Cell &cell =board[row][col];
         addNeighbours(cell, "no", row-1, col);
         addNeighbours(cell, "so", row+1, col);
         addNeighbours(cell, "ea", row, col+1);
         addNeighbours(cell, "we", row, col-1);
         addNeighbours(cell, "ne", row-1, col+1);
         addNeighbours(cell, "nw", row-1, col-1);
         addNeighbours(cell, "se", row+1, col+1);
         addNeighbours(cell, "sw", row+1, col-1);
        
      }
   }

  createEnemy();
  createPotion();
  createGold();
}

void Florr::display() {
  td->display();
}

Floor::~Floor() {
  delete td;
}






