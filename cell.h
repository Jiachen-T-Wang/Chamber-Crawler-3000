#ifndef __CELL_H__
#define __CELL_H__
#include "subject.h"
#include "observer.h"

class Cell: public Subject, public Observer {//abstract
   int x;
   int y;
public:
   Cell(int x, int y);
};
#endif
