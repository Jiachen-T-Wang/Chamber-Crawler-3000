#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include "cell.h"
#include "object.h"
class Character: public Object{
<<<<<<< HEAD
   int HP;
   int atk;
   int def;
   
=======
  int HP;
  int atk;
  int def;
  
>>>>>>> e3fa436a86a302d2e3b22a73f09a2cc6d1747fe6
protected:
   int calcDamage(Character* attacker, Character* defender);
public:
<<<<<<< HEAD
   Character(int HP, int atk, int def);
   int getHP();
   int getAtk();
   int getDef();
   void addHP(int hp);
   void getHurt(int damage);
   void move();
   virtual void attack()=0;
   void checkDead();
=======
  Character(int HP, int atk, int def);
  int getHP();
  int getAtk();
  int getDef();
  void addHP(int hp);
  void getHurt(int damage);
  void move();
  virtual void attack()=0;
  void checkDead();
>>>>>>> e3fa436a86a302d2e3b22a73f09a2cc6d1747fe6
};

#endif


