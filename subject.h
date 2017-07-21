#ifndef __SUBJECT_H__
#define __SUBJECT_H__
#include <vector>

//struct Info;
class Observer;

class Subject {

  std::vector<Observer*> observers;
    
public:
  void notifyMove(std::shared_ptr<Player> p, std::string dir);  //to move
  void notifyMove(std::shared_ptr<Enemy> e);
  void notifyEnemy();
  void notifyEnemyAttack(Enemy* e, int damage);
  void notifyMiss();
  void notifyDead();

    void attach(std::shared_ptr<Observer> o);
    void notifyObservers();
    virtual ~Subject() = default;
};

#endif
