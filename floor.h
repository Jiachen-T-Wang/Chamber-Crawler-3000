#ifndef __FLOOR_H__
#define __FLOOR_H__

#include <iostream>
#include <vector>
#include "cell.h"

class Chamber;
class TextDisplay;
const int postionNum = 10;
const int goldNum = 10;
const int enemyNum = 20;
const int chamberNum = 5;
class Floor{
   
  int level;
  int length;
  int height;
   
  std::vector<std::vector <Cell>> board;
   
  std::vector <Chamber *> chambers;
   
  TextDisplay *td;
  
  void addToChamber(Cell *c);
   
  Chamber *randChamber();
   
  void createObjects();
   
   void addNeighbours(Cell &c, Dir dir, int row, int col);
  
public:
  Floor(int l, std::string fileName);  //read the map from the txt file
   
  void display();
   
  ~Floor();
};

#endif
