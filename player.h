#ifndef player_h
#define player_h

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
