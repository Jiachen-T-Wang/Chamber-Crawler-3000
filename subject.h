#ifndef __SUBJECT_H__
#define __SUBJECT_H__
#include <vector>

//struct Info;
class Observer;

class Subject {
<<<<<<< HEAD
<<<<<<< HEAD
  std::vector<Observer*> observers;
 public:
  void attach(Observer *o);  
  void notifyMove(Player* p, std::string dir);  //to move
  void notifyMove(Enemy* e);
  void notifyEnemy(Player* player, int dir);
  void notifyEnemyAttack(Enemy* e, int damage);  //通知TD Enemy攻击了造成damage的伤害
  void notifyMiss();
  void notifyDead();
  virtual Info getInfo() const = 0;
  virtual ~Subject() = default;
=======
=======
>>>>>>> d010c8748af62cbe5b438b69bf9c9c7688fc2305
   
   std::vector<Observer*> observers;
   
public:
   void attach(Observer *o);
   
   void notifyObservers();
   
  // virtual Info getInfo() const = 0;
   
   virtual ~Subject() = default;
<<<<<<< HEAD
>>>>>>> d010c8748af62cbe5b438b69bf9c9c7688fc2305
=======
>>>>>>> d010c8748af62cbe5b438b69bf9c9c7688fc2305
};

#endif
