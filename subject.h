#ifndef __SUBJECT_H__
#define __SUBJECT_H__
#include <vector>

//struct Info;
class Observer;

class Subject {

  std::vector<Observer*> observers;

   /*
  void notifyMove(Player* p, std::string dir);  //to move
  void notifyMove(Enemy* e);
  void notifyEnemy(Player* player, int dir);
  void notifyEnemyAttack(Enemy* e, int damage);  //通知TD Enemy攻击了造成damage的伤害
  void notifyMiss();
  void notifyDead();
*/

   
public:
   void attach(Observer *o);
   
   void notifyObservers();
   
  // virtual Info getInfo() const = 0;
   
   virtual ~Subject() = default;

};

#endif
