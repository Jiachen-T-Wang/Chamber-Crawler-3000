#ifndef __PLAYER_H__
#define __PLAYER_H__
#include <iostream>
#include <string>
#include "character.h"

class Enemy;
class Floor;
class Potion;

class Player: public Character{
  const int maxHP;
  Floor* f;
  int score;
  const std::string race;
public:
  Player(int HP, int atk, int def, int maxHP, Floor* f, std::string race);
  void move();
  /*
  int getHp();
  void setHp();
   */
  virtual int getAttack() = 0;
  virtual int getDefense() = 0;
  virtual void usePotion(Potion* p);
  virtual void attack(Enemy* e);
  virtual void PickGold(int gold);
};

#endif
