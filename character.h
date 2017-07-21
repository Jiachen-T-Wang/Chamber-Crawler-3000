#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include "cell.h"
#include "object.h"

class Character: public Object{
   int HP;
   int atk;
   int def;
   
protected:
   
   
public:
<<<<<<< HEAD
    int getHP();
    int getAtk();
    int getDef();
    
    Character(int HP, int atk, int def);
    virtual void moveTo(Dir dir);
=======
   
   Character(int HP, int atk, int def);
<<<<<<< HEAD
>>>>>>> 3f06dca506a3425b099df294628fb302dcd5a78f

    void getHurt(int damage);
   
    bool checkDead();
=======

   void hurt(int damage);
   
   bool checkDead();
>>>>>>> 3f06dca506a3425b099df294628fb302dcd5a78f
   
   };

#endif


