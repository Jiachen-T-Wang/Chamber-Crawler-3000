#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include "cell.h"

class Character: public Object{
  int HP;
  int atk;
  int def;
public:
	Character(int HP, int atk, int def);
  	virtual void move()=0;
  	virtual void attack()=0;
  	void checkDead();
};

#endif 


