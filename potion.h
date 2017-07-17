#ifndef potion_h
#define potion_h

#include <string>

class Potion {
  int effect; // One of 10, 5, -5 or -10
  std::string type; // One of Hp, Atk, Def

public:
  Potion(int effect, std::string type);
};

#endif
