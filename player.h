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
  int getMaxHP() const;
  void move(string dir);
  virtual void usePotion(Potion* p);
  virtual void attack(Enemy* e) override;
  virtual void PickGold(int gold);
  virtual ~Player() = 0;
};

#endif
