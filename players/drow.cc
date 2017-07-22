#include "drow.h"
#include "potion.h"

Drow::Drow(std::shared_ptr<Floor> f): Player{150, 150, 25, 15, f, "Drow"} {}

//all potions have their effect magnified by 1.5
void Drow::usePotion(std::shared_ptr<Potion> p){
    if (p->type == "Hp") addHp(1.5 * p->effect);
    else if (p->type == "Atk") atkEffect += (1.5* p->effect);
    else if (p->type == "Def") defEffect += (1.5 * p->effect);
}

void Drow::beAtkBy(std::shared_ptr<Enemy> e){
    e->attack(std::shared_ptr<Drow>(this));
}

