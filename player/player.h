#ifndef __PLAYER_H__
#define __PLAYER_H__
#include <iostream>
#include <string>
#include "../character.h"

class Enemy;
class Floor;
class Potion;

class Player: public Character{
  const int maxHP;
  int atkEffect; // set to 0 when change floor
  int defEffect; // set to 0 when change floor
  Floor* f;
  int score;

  int calcDamage(Enemy* attacker);

public:
  const std::string race;
  Player(int HP, int atk, int def, int maxHP, Floor* f, std::string race);
  int getMaxHP() const;
  void addHp(int hpEffect);
  void move(string dir);
  virtual void usePotion(Potion* p);
  virtual void attack(int dir);
  int realAtk();
  int realDef();
  virtual void beAtkBy(Enemy* enemy);
  virtual void PickGold(int gold);
  virtual void roundChange();   //每一轮都发生的变化
  std::string showRace() const;
  virtual ~Player() = 0;
};

#endif
