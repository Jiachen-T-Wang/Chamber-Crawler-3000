#ifndef __FLOOR_H__
#define __FLOOR_H__

#include <iostream>
#include <vector>

class Cell;

class Floor{
    int level;
   std::vector<std::vector <Cell *>> f;
   
public:
    Floor(std::string fileName);  //read the map from the txt file
    
};

#endif
