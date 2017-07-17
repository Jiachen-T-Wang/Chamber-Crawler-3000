#ifndef __WALL_H__
#define __WALL_H__

#include "cell.h"
#include <string>

class Wall:public Cell{
public:
  Wall(int x, int y);
  bool canStand() override;
  bool getCanStandByAll() override;
};
#endif
