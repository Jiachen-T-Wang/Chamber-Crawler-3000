#ifndef __TILE_H__
#define __TILE_H__

#include "cell.h"
#include <string>

class Tile:public Cell{
public:
  Tile(int x, int y);
  bool canStand() override;
  bool getCanStandByAll() override;
};
#endif
