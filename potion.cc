#include "potion.h"

Potion::Potion(Player *component, int effect, std::string type):
component{component}, effect{effect}, type{type} {}

Potion::~Potion(){
  delete component;
}
