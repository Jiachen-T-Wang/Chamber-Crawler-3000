#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include "cell.h"
#include "object.h"

class Character: public Object{
   int HP;
   int atk;
   int def;
   
public:
   
   int getHP();
   int getAtk();
   int getDef();
   
   Character(int HP, int atk, int def);
   
   virtual void moveTo(Dir dir);
   
   
   void getHurt(int damage);
   
   bool checkDead();
   
   
   
};

#endif


