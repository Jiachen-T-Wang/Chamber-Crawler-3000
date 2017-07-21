#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include "cell.h"
#include "object.h"

class Character: public Object{
   int HP;
   int atk;
   int def;
   
public:
<<<<<<< HEAD
   
   int getHP();
   int getAtk();
   int getDef();
   
   Character(int HP, int atk, int def);
   
   virtual void moveTo(Dir dir);
   
   
   void getHurt(int damage);
   
   bool checkDead();
   
   
   
=======
    int getHP();
    int getAtk();
    int getDef();
    
    Character(int HP, int atk, int def);
    virtual void moveTo(Dir dir);
    void getHurt(int damage);
    bool checkDead();
    
>>>>>>> 93d1771e119f472d3dc88bc0c3e1d7cbd5320d4a
};

#endif


