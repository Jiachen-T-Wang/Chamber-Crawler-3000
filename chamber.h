#ifndef __CHAMBER_H__
#define __CHAMBER_H__

#include <vector>
class Item;
class Enemy;
class Cell;

class Chamber{
   
   int size;
   
   std::vector <Cell *>cells;
   
   Cell *randCell();

public:
   Chamber();
   
   void addCell(Cell *);
   void addPlayer();
   void addStair();
   void addEnemy();
   void addPotion();
   void addGold();
};
#endif
