#ifndef __SUBJECT_H__
#define __SUBJECT_H__
#include <vector>

struct Info;
class Observer;

class Subject {
  std::vector<Observer*> observers;
 public:
  void attach(Observer *o);  
  void notifyObservers(Character* man, int dir = -1);  //to move
  void notifyObservers(int dir, Player p);  //to attack
  virtual Info getInfo() const = 0;
  virtual ~Subject() = default;
};

#endif
