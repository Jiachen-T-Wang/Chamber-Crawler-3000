#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include "cell.h"

class Character{
  int HP, atk, def;
public:
  void move();
  void attack();
  void checkDead();
};
#endif 
