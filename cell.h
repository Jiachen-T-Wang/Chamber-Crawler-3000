#ifndef __CELL_H__
#define __CELL_H__

#include <string>

class Cell{
  int x;
  int y;
  std::string type; // One of doorway, empty, stairway, tile or wall
};
#endif
