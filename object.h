#ifndef __OBJECT_H__
#define __OBJECT_H__
#include <iostream>

class Cell;

class Object{
	Cell* position;
public:
	Object();
	void setPosition(Cell* p);
	Cell* getPosition();
};

#endif
