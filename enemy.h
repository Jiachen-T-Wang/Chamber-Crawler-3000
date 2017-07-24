#ifndef __ENEMY_H__
#define __ENEMY_H__

#include "character.h"
#include "player.h"
#include "vampire.h"
#include "drow.h"
#include "goblin.h"
#include "treasure.h"
#include "dir.h"

#include <memory>

class Drow;
class Vampire;
class Goblin;

//it should be an abstract class, so make dtor pure virtual
class Enemy: public Character{
   bool moveable;
   std::string type;
   
protected:
    static bool drop;
   int calcDamage(Player* defender);
   std::shared_ptr<Treasure> gold;
    
public:
    static void canDrop();
   Enemy(int HP, int atk, int def, std::string);
    
   bool isEnemy() override;
   
   bool canMove();

   void enableMove();
   virtual void move();
    
   std::string getType();
   
   virtual void beAtkBy(Player* p);
   
   virtual void attack(Player* p);
   virtual void attack(Drow* d);
   virtual void attack(Vampire* v);
   virtual void attack(Goblin* g);
//   virtual bool isDragon();
   virtual ~Enemy()=0;
};

#endif
