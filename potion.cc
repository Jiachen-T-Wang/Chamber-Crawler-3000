#include "header.h"
using namespace std;

Potion::Potion(int effect, std::string type): effect{effect}, type{type} {}

string Potion::getType() {
   return type;
}

int Potion::getEffect() {
   return effect;
}

bool Potion::isPotion(){
   return true;
}

char Potion::symbol(){return 'P';}
