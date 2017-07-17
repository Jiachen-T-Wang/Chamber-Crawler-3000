#ifndef __FLOOR_H__
#define __FLOOR_H__

#include <iostream>
#include <vector>
#include "cell/cell.h"

class Chamber;
const int postionNum = 10;
const int goldNum = 10;
const int enemyNum = 20;
class Floor{
   int level;
   
   int length;
   int height;
   std::vector<std::vector <Cell>> board;
   std::vector <Chamber *> chambers;
   void addToChamber(Cell *c);
public:
   Floor(int l, std::string fileName);  //read the map from the txt file
};

#endif
