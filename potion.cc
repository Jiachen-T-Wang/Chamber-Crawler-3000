#include "potion.h"

Potion::Potion(Player *component, int effect, std::string type):
component{component}, effect{effect}, type{type} {}


int Potion::getAttack(){
  int result = getAttack()
  if (type == "Atk") result += effect;
  if result < 0 result = 0;
  return result;
}
int Potion::getDefense(){
  int result = getDefense()()
  if (type == "Def") result += effect;
  if result < 0 result = 0;
  return result;
}
void Potion::setHp(){
  // needs implementation
}

Potion::~Potion(){
  delete component;
}
