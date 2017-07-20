#ifndef __OBJECT_H__
#define __OBJECT_H__
#include <iostream>

class Cell;

class Object{
   
   Cell* position;
   
protected:
   
   void setPos(Cell* p);
   
   Cell* getPos();
   
public:
   
   Object();
   
   
};

#endif
