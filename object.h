#ifndef __OBJECT_H__
#define __OBJECT_H__
#include <iostream>

class Cell;

class Object{
   
   Cell* position;
   
protected:
   
   
   
   Cell* getPos();
   
public:
   
   void setPos(Cell* p);
   
   Object();
   
   
};

#endif
