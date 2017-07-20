#ifndef __CELL_H__
#define __CELL_H__
#include <map>
#include "subject.h"
#include "observer.h"
#include <vector>
enum class Dir;
enum class CellType;
class Object;
class Cell: public Subject, public Observer {//abstract
   
   int row;
   int col;
   CellType type;
   Object* content;
   std::map <Dir, Cell *> neighbours;
   
public:
   
   Cell(int row, int col, char c);
   
   Object* getContent();   // nullptr means nobody on it
   
   void setCont(Object* o);   //mutator
   
   bool getCanStand();   //return true if it can be stand on
   
   bool getCanStandByAll();
   
   void notify();
   
   void attachNeighbour(Dir dir, Cell *c);
   
   Cell *getNeighbour(Dir dir);
};

#endif
