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
<<<<<<< HEAD
   std::shared_ptr<Treasure> gold;
   
protected:
    Dir numToDir(int d);
   int calcDamage(std::shared_ptr<Player> defender);
=======
   int calcDamage(std::shared_ptr<Player> defender);
    
protected:
    std::shared_ptr<Treasure> gold;
 //   Dir numToDir(int d);
>>>>>>> 39b7e5f54fd21bd79d5cbda9ffbffbac6cd01c02

public:
   Dir numToDir(int d);
   Enemy(int HP, int atk, int def, std::string);
    
    bool isEnemy() override;
   
   bool canMove();
    
  //  bool isPlayer() override;
    //bool isEnemy() override;

   void enableMove();
   virtual void move();

   void changeMove(bool b);
    
    std::string getType();
   
   virtual void beAtkBy(std::shared_ptr<Player> p);
   
   virtual void attack(std::shared_ptr<Player> p);
   virtual void attack(std::shared_ptr<Drow> d);
   virtual void attack(std::shared_ptr<Vampire> v);
   virtual void attack(std::shared_ptr<Goblin> g);
   virtual bool isDragon();
   virtual ~Enemy()=0;
};

#endif
