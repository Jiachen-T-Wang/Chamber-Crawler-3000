#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include "cell.h"
#include "object.h"
class Character: public Object{
   int HP;
   int atk;
   int def;
   
protected:
   
   bool moveTo(std::string dir);
   
public:
   
   Character(int HP, int atk, int def);
   
   int getHP();
   int getAtk();
   int getDef();
   
   void hurt(int damage);
   
   bool checkDead();
   
   virtual void move()=0;
   
   virtual void attack(Character *defender)=0;
   
   virtual void beAtkBy(Character *attacker)=0;
   
};

#endif


