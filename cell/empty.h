#ifndef __EMPTY_H__
#define __EMPTY_H__

#include "cell.h"
#include <string>

class Empty:public Cell{
public:
  Empty(int x, int y);
  bool canStand() override;
};
#endif
