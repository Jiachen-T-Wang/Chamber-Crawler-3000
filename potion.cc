#include "potion.h"

Potion::Potion(Player *component, int effect, std::string type):
component{component}, effect{effect}, type{type} {}

int Potion::getAttack(){
<<<<<<< HEAD
  int result = component->getAttack()
=======
  int result = component->getAttack();
>>>>>>> 46a62f9c68de10edc36513c5193f4c586e8f8537
  if (type == "Atk") result += effect;
  if result < 0 result = 0;
  return result;
}
int Potion::getDefense(){
  int result = component->getDefense();
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
