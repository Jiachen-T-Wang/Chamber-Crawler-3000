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
<<<<<<< HEAD
    void notifyPlayerAttack(Enemy* e, int damage);
    void notifyEnemyAttack(Enemy* e, int damage);
=======
    void notifyPlayerAttack(Enemy *e, int damage);
    void notifyEnemyAttack(Enemy *e, int damage);
>>>>>>> 796fcab1c92d652deb719bd59f12f522e8c7416c
    void notifyMiss();
    void notifyDead();
    void notifyGold();

    void attach(std::shared_ptr<Observer> o);
    virtual ~Subject() = default;
    
};

#endif
