#ifndef __TROLL_H__
#define __TROLL_H__

#include <iostream>
#include <string>
#include "../player.h"

class Floor;
class Cell;

//regains HP every turn 
class Troll: public Player{
   public:
   	Troll(std::shared_ptr<Floor> f);
   	void roundChange() override;
};

#endif
