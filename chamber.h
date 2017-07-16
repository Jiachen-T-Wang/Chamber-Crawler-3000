#ifndef __CHAMBER_H__
#define __CHAMBER_H__

#include <vector>
class Item;
class Enemy;
class Cell;

class Chamber{
  std::vector <Cell *>cells;
  /*
  std::vector <item *>;
  std::vector <Potion *>;
  std::vector <Treasure *>;
   */
  void createEnemy();
  void createPotion();
  void createTreasure();
 public:
   Chamber();
   void addCell(Cell *);
};
#endif
