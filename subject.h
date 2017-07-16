#ifndef __SUBJECT_H__
#define __SUBJECT_H__
#include <vector>

struct Info;
class Observer;

class Subject {
  std::vector<Observer*> observers;
 public:
  void attach(Observer *o);  
  void notifyObservers();
  void notifyObservers(int dir);  //notify the neighbor in the specific direction (for move & attack)
  void notifyObservers(int dir, Player p);
  virtual Info getInfo() const = 0;
  virtual ~Subject() = default;
};

#endif
