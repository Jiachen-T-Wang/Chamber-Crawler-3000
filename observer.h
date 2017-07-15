#ifndef __OBSERVER_H__
#define __OBSERVER_H__

class Subject;
class Cell;

class Observer {
 public:
  virtual void notify(Subject &whoNotified) = 0;  // pass the Cell that called
                                                  // the notify method
  virtual ~Observer() = default;
};
#endif
