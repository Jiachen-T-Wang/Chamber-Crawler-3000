#ifndef __SHADE_H__
#define __SHADE_H__

#include <iostream>
#include <string>
#include "player.h"

class Floor;
class Cell;

class Shade: public Player{
   public:
   	Shade(Floor* f);
};

#endif
