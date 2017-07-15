#ifndef __WALL_H__
#define __WALL_H__
#include <iostream>
#include "cell.h"

class Object;
class Wall: public Cell{
   std::string type;
};

#endif