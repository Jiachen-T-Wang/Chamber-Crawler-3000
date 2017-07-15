#ifndef __CELL_H
#define __CELL_H

class Object;
class Cell{
   int x;
   int y;
   Object *type;
public:
   Cell(int x, int y);
   void changeType(Object *type);
};


#endif
