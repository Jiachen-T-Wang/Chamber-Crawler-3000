#ifndef __OBSERVER_H__
#define __OBSERVER_H__

class Cell;
class Character;
class Enemy;

class Observer {
   
public:
    virtual void notify()=0;
    virtual void displayPlayerMove()=0;
    virtual void displayPlayerAtk(int damage)=0;
    virtual void displayEnemyAtk(std::shared_ptr<Enemy> e, int damage)=0;
    virtual void displayMiss()=0;
    virtual void dispalyDead()=0;
    
    virtual ~Observer() = default;
};
#endif
