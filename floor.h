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
   
  void createObjects(Player *p);
   
   void addNeighbours(Cell &c, Dir dir, int row, int col);
  
public:
   Floor(int l, Player *p);
<<<<<<< HEAD
  Floor(int l, Player *p, std::string fileName);  //read the map from the txt file
  void display();
   void gothroughBoard(Player *p);
  ~Floor();
=======
   Floor(int l, Player *p, std::string fileName);  //read the map from the txt file
   int getLevel();
   void display();
   
   ~Floor();
>>>>>>> 6ebfa93a9337091e3a8fb67c3f1d9c71141a7d7a
};

#endif
