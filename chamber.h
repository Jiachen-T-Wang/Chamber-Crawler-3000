#ifndef __CHAMBER_H__
#define __CHAMBER_H__

#include <vector>
class Item;
class Enemy;
class Cell;

class Chamber{
  std::vector <std::pair<int,int>> coordinates;
  /*
  std::vector <item *>;
  std::vector <Potion *>;
  std::vector <Treasure *>;
   */
  Cell *stair;
public:
  void createEnemy();
  void createPotion();
  void createTreasure();
  void addPotion(Potion *);
  void addEnemy(Enemy *);
  void addTreasure(Treasure *);
};
#endif
