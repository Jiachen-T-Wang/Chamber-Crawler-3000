#ifndef _TILE_H
#define _TILE_H
#include <iostream>
#include "cell.h"
class Object;
class Tile: public Cell{
   std::string type;
   Object *occupy;
public:
   void changeOccupy(Object *occupy);
};

#endif
