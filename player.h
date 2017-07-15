#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "character.h"

class Player:public Character{
  Floor *f;
  int score;
public:
  void move();
  void usePotion(Potion *);
  void attack(Enem *);
  void PickGold(int);
};
#endif
