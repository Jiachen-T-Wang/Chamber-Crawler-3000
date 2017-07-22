#ifndef __CELL_H__
#define __CELL_H__
#include <map>
#include "subject.h"
#include "observer.h"
#include <vector>
#include <memory>
enum class Dir;
enum class CellType;
class Object;
class Player;

class Cell: public Subject {//abstract
   
   int row;
   int col;
   CellType type;
   std::shared_ptr<Object> content;
   std::map <Dir, Cell*> neighbours;
   
public:
   Cell(int row, int col, char c);
   
   int getCol();
   int getRow();
   
   std::shared_ptr<Object> getContent();   // nullptr means nobody on it
    
   void setCont(std::shared_ptr<Object> o);   //mutator
   
   bool canStand();   //return true if it can be stand on
   
   bool canStandByAll();
   
   
   void attachNeighbour(Dir dir, Cell* c);
   
   Cell* getNeighbour(Dir dir);
   
   void spawnPlayer(std::shared_ptr<Player> p);
   void spawnStair();
   void spawnEnemy();
   void spawnPotion();
   void spawnGold();
   
   bool isNeighbour(Cell *c);
   CellType getCellType();
   char getSymbol();
};

#endif
