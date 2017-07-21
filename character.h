#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include "cell.h"
#include "object.h"

class Character: public Object{
   int HP;
   int atk;
   int def;
   
protected:
   
   void moveTo(Dir dir);
   
   int getHP();
   int getAtk();
   int getDef();
   
public:
   
   Character(int HP, int atk, int def);

   void hurt(int damage);
   
   bool checkDead();
   
   };

#endif


