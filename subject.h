#ifndef __SUBJECT_H__
#define __SUBJECT_H__
#include <vector>
#include "dir.h"

class Observer;
class Enemy;

class Subject {

  std::vector<Observer*> observers;
    
public:
    void notifyPlayerMove(Dir dir);  //to move
    void notifyPlayerAttack(int damage);
    void notifyEnemyAttack(std::shared_ptr<Enemy> e, int damage);
    void notifyMiss();
    void notifyDead();
    void notifyGold();

    void attach(std::shared_ptr<Observer> o);
    virtual ~Subject() = default;
    
};

#endif
