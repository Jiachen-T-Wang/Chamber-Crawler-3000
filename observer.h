#ifndef __OBSERVER_H__
#define __OBSERVER_H__
#include "enemy.h"
#include <memory>
class Cell;
class Character;

class Observer {
   
public:
    virtual void displayPlayerMove(Dir dir)=0;
    virtual void displayPlayerAtk(std::shared_ptr<Enemy> e, int damage)=0;
    virtual void displayEnemyAtk(std::shared_ptr<Enemy> e, int damage)=0;
    virtual void displayMiss()=0;
    virtual void displayDead()=0;
    virtual void displayGold()=0;    //这个用在Human死的时候四周散落gold
    
    virtual ~Observer() = default;
};

#endif
