#include <vector>
#include "floor.h"
#include <iostream>
#include "string.h"
using namespace std;

Floor::Floor(string fileName):length{0}, height{0}{
   ifilestream fs {fileName};
   string line;
   while(getline(cin, fs)){
      length = line.length();
      vector <Cell *> cellLine;
      for(int i=0; i< length; ++i){
         Cell c {i, height, line[i]};
         cellLine.emplace_back(c);
      }
      board.emplace_back(cellLine);
      height++;
   }
}








