#ifndef __OBSERVER_H__
#define __OBSERVER_H__
#include "enemy.h"
#include <memory>
class Cell;
class Character;

class Observer {
   
public:
    virtual void displayPlayerMove(Dir dir)=0;
    virtual void displayPlayerAtk(Enemy *e, int damage)=0;
    virtual void displayEnemyAtk(Enemy *e, int damage)=0;
    virtual void displayMiss()=0;
    virtual void displayDead()=0;
    virtual void displayGold()=0;
    virtual void displayCannotMove()=0;
    virtual void displayUsePotion(Potion *p)=0;
  
    virtual ~Observer() = default;
};

#endif
