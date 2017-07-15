#ifndef __ENEMY_H__
#define __ENEMY_H__

#include "character.h"

class Enemy:public Character{
  Bool isHostile;
  Bool moveable;
  int amount;
  Floor *r;
public:
  void move();
  void attack(Player *);
};
#endif
