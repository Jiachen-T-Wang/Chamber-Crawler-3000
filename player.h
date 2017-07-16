#ifndef __PLAYER_H__
#define __PLAYER_H__
#include <iostream>
#include <string>
#include "character.h"

class Enemy;
class Floor;
class Potion;

class Player: public Character{
  Floor* f;
  int score;
  const std::string race;
public:
  Player(int maxHP, int HP, int atk, int def, Floor* f, std::string race);
  void move();
  virtual void usePotion(Potion* p);
  virtual void attack(Enemy* e);
  virtual void PickGold(int gold);
};

#endif
