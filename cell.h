#ifndef __CELL_H__
#define __CELL_H__
#include "subject.h"
#include "observer.h"

<<<<<<< HEAD
class Cell: public Subject, public Observer {//abstract
   int x;
   int y;
public:
   Cell(int x, int y);
=======
#include <string>

class Cell{
  int x;
  int y;
  std::string type; // One of doorway, empty, passage, stairway, tile or wall
>>>>>>> bc38184df845b53598517c5d169be011f50ca6b7
};
#endif
