#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include <memory>
#include "object.h"
#include "dir.h"

class Character: public Object{
    
protected:
    
   int HP;
   int atk;
   int def;
   
public:
   Dir numToDir(int d);
   int getHP();
   int getAtk();
   int getDef();
   
   Character(int HP, int atk, int def);
    
//   virtual bool isPlayer() override;
//   virtual bool isEnemy() override;
    
   virtual void moveTo(Dir dir);
   void getHurt(int damage);
   bool checkDead();
};

#endif


