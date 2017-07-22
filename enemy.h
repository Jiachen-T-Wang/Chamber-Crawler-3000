#ifndef __ENEMY_H__
#define __ENEMY_H__

#include "character.h"
#include "player.h"
#include "players/vampire.h"
#include "players/drow.h"
#include "players/goblin.h"
#include "treasure/treasure.h"
#include "dir.h"

#include <memory>

class Drow;
class Vampire;
class Goblin;

//it should be an abstract class, so make dtor pure virtual
class Enemy: public Character{
   bool moveable;
   std::string type;
   std::shared_ptr<Treasure> gold;
   int calcDamage(std::shared_ptr<Player> defender);
    
protected:
    Dir numToDir(int d);

public:
   
   Enemy(int HP, int atk, int def, std::string);
    bool isEnemy() override;
   
   bool canMove();

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
