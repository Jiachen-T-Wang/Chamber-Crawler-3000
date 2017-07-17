#ifndef __PASSAGE_H__
#define __PASSAGE_H__

#include "cell.h"
#include <string>

class Passage:public Cell{
public:
  Passage(int x, int y);
  bool canStand() override;
};
#endif
