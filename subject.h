#ifndef __SUBJECT_H__
#define __SUBJECT_H__
#include <vector>
#include "dir.h"
#include <memory>
class Observer;
class Enemy;

class Subject {

    std::vector<std::shared_ptr<Observer>> observers;
    
public:
    void notifyPlayerMove(Dir dir);  //to move
    void notifyPlayerAttack(Enemy* e, int damage);
    void notifyEnemyAttack(Enemy* e, int damage);
    void notifyMiss();
    void notifyDead();
    void notifyGold();

    void attach(std::shared_ptr<Observer> o);
    virtual ~Subject() = default;
    
};

#endif
