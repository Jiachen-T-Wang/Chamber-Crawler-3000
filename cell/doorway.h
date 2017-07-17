#ifndef __DOORWAY_H__
#define __DOORWAY_H__

#include "cell.h"
#include <string>

class Doorway:public Cell{
public:
  Doorway(int x, int y);
  bool canStand() override;
};
#endif
