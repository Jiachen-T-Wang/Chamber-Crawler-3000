#ifndef __STAIRWAY_H__
#define __STAIRWAY_H__

#include "cell.h"
#include <string>

class Stairway:public Cell{
public:
  Stairway(int x, int y);
  bool canStand() override;
  bool getCanStandByAll() override;
};
#endif
