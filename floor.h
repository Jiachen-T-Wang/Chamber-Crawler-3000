#ifndef __FLOOR_H__
#define __FLOOR_H__

#include <iostream>
#include <vector>
#include "cell.h"

class Floor{
   int level;
   std::vector<std::vector <Cell>> board;
   int length;
   int height;
   
public:
   Floor(std::string fileName);  //read the map from the txt file
};

#endif
