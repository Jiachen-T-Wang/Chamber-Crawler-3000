#ifndef __PLAYER_H__
#define __PLAYER_H__
#include <iostream>
#include <string>
#include "../character.h"

class Enemy;
class Floor;
class Potion;
class Halfling;

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

  int realAtk();
  int realDef();
  virtual int showScore();
  virtual void incScore(int value);
  virtual void usePotion(Potion* p);
  
  virtual void attack(Player* p);
  virtual void attack(Halfling* h);

  virtual void beAtkBy(Enemy* enemy);
  virtual void PickGold(Treasure* gold);
  virtual void roundChange();   //每一轮都发生的变化
  virtual ~Player() = 0;
};

#endif
