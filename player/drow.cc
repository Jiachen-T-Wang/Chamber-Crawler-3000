#include "drow.h"
#include "potion.h"

Drow::Drow(Floor* f): Player{150, 150, 25, 15, f, "Drow"} {}

//all potions have their effect magnified by 1.5
void Drow::usePotion(Potion* p){
  if (p->type == "Hp") addHp(p->effect);
  if (p->type == "Atk") atkEffect += p->effect;
}
