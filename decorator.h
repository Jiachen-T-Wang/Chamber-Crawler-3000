#ifndef __FLIP_H__
#define __FLIP_H__

#include "player.h"

class Decorator: public Player{
protected:
  Player *component;
public:
  Decorator(Player *component);
  virtual ~Decorator();
};

#endif
