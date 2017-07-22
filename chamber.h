#ifndef __CHAMBER_H__
#define __CHAMBER_H__
#include <memory>
#include <vector>
class Item;
class Enemy;
class Cell;
class Player;

class Chamber{
   
   int size;
   
   std::vector <Cell *>cells;
   
   Cell *randCell();

public:
   Chamber();
   
   void addCell(Cell *c);
   void addPlayer(std::shared_ptr<Player>p);
   void addStair();
   void addEnemy();
   void addPotion();
   void addGold();
};
#endif
