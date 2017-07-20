#include <vector>
#include "floor.h"
#include <iostream>
#include <fstream>
#include <string>
#include "cell.h"
#include "chamber.h"
using namespace std;

void Floor::addToChamber(Cell *c){
  int x = c->getX();
  int y = c->getY();
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

void Floor::addNeighbours(Cell &c, int row, int col){
   try{
      c.attachNeighbour(&theGrid.at(row).at(col));
   } catch(out_of_range){} // the cell at row, col is out of boundary
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
   for(int r=0; r<height; ++r){
      for (int c=0; c< length; ++c){
         addNeighbours(board[r][c], r-1, c+1);
        // 聪明的你会写 笨笨的我睡了 
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






