#ifndef potion_h
#define potion_h

#include <string>
#include "object.h"

class Potion: public Object {
   
   int effect; // One of 10, 5, -5 or -10
   
   std::string type; // One of Hp, Atk, Def
   
public:
   Potion(int name);
   
   std::string getType();
   
   int getEffect();
   
   bool isPotion() override;
    char symbol() override;
};

#endif
