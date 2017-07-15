#ifndef __FLOOR_H__
#define __FLOOR_H__

#include <iostream>
#include <vector>;

class Floor{
	int level;
	
public:
    Floor(std::string fileName);  //read the map from the txt file
    ~Floor();
};

#endif