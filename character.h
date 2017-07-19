#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include "cell.h"
#include "object.h"
class Character: public Object{
  int HP;
  int atk;
  int def;
  
public:
  Character(int HP, int atk, int def);
  int getHP();
  int getAtk();
  int getDef();
  void getHurt(int damage);
  virtual void move();
  virtual void attack()=0;
  virtual void beAtkBy()=0;
  void checkDead();
};

#endif


