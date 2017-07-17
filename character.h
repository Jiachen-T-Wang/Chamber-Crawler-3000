#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include "cell.h"
#include "object.h"
class Character: public Object{
  int HP;
  int atk;
  int def;
  
protected:
  int calcDamage(Character* attacker, Character* defender);
public:
  Character(int HP, int atk, int def);
  int getHP();
  int getAtk();
  int getDef();
  void addHP(int hp);
  void getHurt(int damage);
  void move();
  virtual void attack()=0;
  void checkDead();
};

#endif


