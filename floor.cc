#include <vector>
#include "floor.h"
#include <iostream>
#include "string.h"
#include "cell.h"
#include "chamber.h"
using namespace std;

Floor::addToChamber(Cell *c){
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
Floor::Floor(int l, string fileName):level{l}, length{0}, height{0}{
   for(int i=0; i<5; ++i)
      chambers.emplace_back(new Chamber());
   ifilestream fs {fileName};
   string line;
   while(getline(cin, fs)){
      length = line.length();
      vector <Cell> cellLine;
      for(int i=0; i< length; ++i){
         Cell c {i, height, line[i]};
         cellLine.emplace_back(c);
      }
      board.emplace_back(cellLine);
      for(auto c: cellLine) addToChamber(&c);
      height++;
   }
}








