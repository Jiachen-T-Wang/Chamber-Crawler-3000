#ifndef __DECORATOR_H__
#define __DECORATOR_H__

#include "player.h"

class Decorator: public Player{
protected:
  Player *component;
public:
  Decorator(Player *component);
  virtual ~Decorator();
};

#endif
