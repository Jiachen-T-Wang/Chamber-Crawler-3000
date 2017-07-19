#ifndef __ENEMY_H__
#define __ENEMY_H__

#include "../character.h"

class Player;

//it should be an abstract class, so make dtor pure virtual
class Enemy: public Character{
  bool moveable;

  int calcDamage(Player* attacker);
public:
  const std::string type;
  Enemy(int HP, int atk, int def);
  bool canMove();

  virtual void attack(Player* p);
  virtual void attack(Drow* d);
  
  virtual void beAtkBy(Player* p);
  virtual ~Enemy()=0;
};

#endif
