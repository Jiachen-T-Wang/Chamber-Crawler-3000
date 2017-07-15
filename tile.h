#ifndef __TILE_H__
#define __TILE_H__
#include <iostream>
#include "cell.h"

class Object;
class Tile: public Cell{
   Object *occupy;
public:
   void changeOccupy(Object *occupy);
};

#endif
