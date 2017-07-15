#ifndef character_h
#define character_h

#include "cell.h"

class Character{
  int HP, atk, def;
public:
  void move();
  void attack();
  void checkDead();
};
#endif 
