#ifndef __CELL_H__
#define __CELL_H__
#define EA 0
#define SO 1
#define WE 2
#define NO 3
#define NE 4
#define SE 5
#define NW 6
#define SW 7
#define TD 8
#include "subject.h"
#include "observer.h"
#include <string>

class Object;
class Cell: public Subject, public Observer {//abstract
  int x;
  int y;
  std::string type; // One of doorway, empty, passage, stairway, tile or wall
  Object* content;
public:
  Cell(int x, int y, char c);
  void notify(Object* o);
  Object* getContent();   //if nullptr means nobody on it
  void setCont(Object* o);   //mutator
};

#endif
