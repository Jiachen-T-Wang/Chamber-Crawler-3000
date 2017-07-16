#ifndef __CELL_H__
#define __CELL_H__
#include "subject.h"
#include "observer.h"
#include <string>

class Object;
class Cell: public Subject, public Observer {//abstract
  int x;
  int y;
  std::string type; // One of doorway, empty, passage, stairway, tile or wall
  Object *content;
public:
  Cell(int x, int y, char c);
  void notify(Subject &);
};

#endif
