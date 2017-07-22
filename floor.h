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
   void addToChamber(Cell *c);

  int length;
  int height;
   
  std::vector<std::vector <Cell>> board;
   
   std::vector <std::shared_ptr<Chamber>> chambers;
   
   std::shared_ptr<TextDisplay> td;
  
   
   std::shared_ptr<Chamber> randChamber();
   
   void createObjects(std::shared_ptr<Player>p);
   
   void addNeighbours(Cell &c, Dir dir, int row, int col);
  
public:
  // Floor(int l, Player *p, std::string fileName);

  Floor(int l, std::shared_ptr<Player>p);  //read the map from the txt file
   void gothroughBoard(std::shared_ptr<Player>p);

   int getLevel();
   void display();
    friend class TextDisplay;
};

#endif
