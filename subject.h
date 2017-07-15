#ifndef __SUBJECT_H__
#define __SUBJECT_H__
#include <vector>
#include "subscriptions.h"
struct Info;
class Observer;

class Subject {
  std::vector<Observer*> observers;
 public:
  void attach(Observer *o);  
  void notifyObservers(SubscriptionType t);
  virtual Info getInfo() const = 0;
  virtual ~Subject() = default;
};

#endif
