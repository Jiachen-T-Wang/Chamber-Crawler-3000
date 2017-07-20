#include "potion.h"
using namespace std;

Potion::Potion(int effect, std::string type): effect{effect}, type{type} {}

string Potion::getType() {
   return type;
}

int Potion::getEffect() {
   return effect;
}

bool isPotion(){
   return true;
}
