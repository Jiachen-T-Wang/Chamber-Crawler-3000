#ifndef potion_h
#define potion_h


class Potion{
  int effect; // One of 10, 5, -5 or -10
  std::string type; // One of Hp, Atk, Def
  Player *component;
public:
  Potion(Player *component, int effect, std::string type);
  ~Potion();
};

#endif
