#ifndef __OBSERVER_H__
#define __OBSERVER_H__

class Cell;
class Character;

class Observer {
 public:
  virtual void getMove(Character* c, int dir) = 0;
  virtual ~Observer() = default;
};
#endif
