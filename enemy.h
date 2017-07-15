#ifndef enemy_h
#define enemy_h

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
