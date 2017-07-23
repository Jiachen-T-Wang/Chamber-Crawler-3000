#include <cstdlib>
#include <iostream>
#include "header.h"
#define TD 0
using namespace std;

void Subject::notifyPlayerMove(Dir dir){
    observers[TD]->displayPlayerMove(dir);
}

<<<<<<< HEAD
void Subject::notifyPlayerAttack(Enemy* e, int damage){
    observers[TD]->displayPlayerAtk(e, damage);
}

void Subject::notifyEnemyAttack(Enemy* e, int damage){
=======
void Subject::notifyPlayerAttack(Enemy *e, int damage){
    observers[TD]->displayPlayerAtk(e, damage);
}

void Subject::notifyEnemyAttack(Enemy *e, int damage){
>>>>>>> 796fcab1c92d652deb719bd59f12f522e8c7416c
	observers[TD]->displayEnemyAtk(e, damage);
}

void Subject::notifyMiss(){
	observers[TD]->displayMiss();
}

void Subject::notifyDead(){
    observers[TD]->displayDead();
}

void Subject::notifyGold(){
    observers[TD]->displayGold();
}
 

void Subject::attach(std::shared_ptr<Observer> o) { observers.emplace_back(o); }











