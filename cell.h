#ifndef __CELL_H__
#define __CELL_H__
#include <map>
#include "subject.h"
#include "observer.h"
#include <vector>

enum class Dir;
enum class CellType;
class Object;
class Player;
class Cell: public Subject, public Observer {//abstract
   
   int row;
   int col;
   CellType type;
   std::shared_ptr<Object> content;
   std::map <Dir, std::shared_ptr<Cell>> neighbours;
   
public:
   Cell(int row, int col, char c);
   
   int getCol();
   int getRow();
   
   std::shared_ptr<Object> getContent();   // nullptr means nobody on it
   void setCont(std::shared_ptr<Object> o);   //mutator
   
   bool canStand();   //return true if it can be stand on
   
   bool canStandByAll();
   
   
   void attachNeighbour(Dir dir, std::shared_ptr<Cell> c);
   
   std::shared_ptr<Cell> getNeighbour(Dir dir);
   
   void spawnPlayer(Player *p);
   void spawnStair();
   void spawnEnemy();
   void spawnPotion();
   void spawnGold();
};

#endif
