#ifndef __SUBJECT_H__
#define __SUBJECT_H__
#include <vector>

struct Info;
class Observer;
class Player;
class Enemy;

class Subject {
  std::vector<Observer*> observers;
   
 public:
  void attach(Observer *o);
   void notifyObservers();
  virtual Info getInfo() const = 0;
  virtual ~Subject() = default;
};

#endif
