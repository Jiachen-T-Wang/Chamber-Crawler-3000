#ifndef __FLOOR_H__
#define __FLOOR_H__

#include <iostream>

class Floor{
public:
    Floor(std::string fileName);  //read the map from the txt file
    ~Floor();
};

#endif