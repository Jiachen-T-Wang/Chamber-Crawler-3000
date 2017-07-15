#ifndef chamber_h
#define chamber_h

#include <vector>
class Item;
class Enemy;
class Cell;

class Chamber{
  std::vector <std::pair<int,int>> coordiantes;
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
