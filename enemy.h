#ifndef __ENEMY_H__
#define __ENEMY_H__

#include "character.h"

//it should be an abstract class, so make dtor pure virtual
class Enemy: public Character{
  bool moveable;
public:
  Enemy(int HP, int atk, int def);
  bool canMove();
  virtual void attack(Player* p);
  virtual void beAtkBy(Player* p);
  virtual ~Enemy()=0;
};

#endif
