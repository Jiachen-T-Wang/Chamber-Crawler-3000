#ifndef potion_h
#define potion_h

#include <string>
#include "player/player.h"
#include "decorator.h"

class Player;
class Potion: public Decorator{
  int effect; // One of 10, 5, -5 or -10
  std::string type; // One of Hp, Atk, Def
  Player *component;
public:
  Potion(Player *component, int effect, std::string type);
  int getAttack() override;
  int getDefense() override;
  void setHp();
  ~Potion();
};

#endif
