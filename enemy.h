#ifndef __ENEMY_H__
#define __ENEMY_H__

#include "character.h"
#include "player.h"

class Drow;
class Vampire;
class Goblin;

//it should be an abstract class, so make dtor pure virtual
class Enemy: public Character{
   
   bool moveable;
   
public:
   
   Enemy(int HP, int atk, int def, std::string);
   
   bool canMove();
   
   void move();
   
   virtual void beAtkBy(Player* p);
   
   virtual void attack(Player* p);
   virtual void attack(Drow* d);
   virtual void attack(Vampire* v);
   virtual void attack(Goblin* g);
   
   
   virtual ~Enemy()=0;
};

#endif
