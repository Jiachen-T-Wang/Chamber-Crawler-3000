#ifndef __OBSERVER_H__
#define __OBSERVER_H__
#include "subscriptions.h"
class Subject;
class Cell;

class Observer {
 public:
  virtual void notify(Subject &whoNotified) = 0;  // pass the Cell that called
                                                  // the notify method
  virtual SubscriptionType subType() const = 0;
  virtual ~Observer() = default;
};
#endif
