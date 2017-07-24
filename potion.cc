#include "header.h"
using namespace std;

Potion::Potion(int name) {
  if(name==0) {effect = 10; type = "Hp"; }
  else if(name==1) {effect = 5; type = "Atk"; }
  else if(name==2) {effect = 5; type = "Def"; }
  else if(name==3) {effect = -10; type = "Hp"; }
  else if(name==4) {effect = -5; type = "Atk"; }
  else {effect = -5; type = "Def"; }
}

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
