#include "header.h"

Drow::Drow(): Player{150, 25, 15, 150, "Drow"} {}

//all potions have their effect magnified by 1.5
void Drow::usePotion(Potion* p){
    if (p->getType() == "Hp") addHp(1.5 * p->getEffect());
    else if (p->getType() == "Atk") setAtkEffect(1.5 * p->getEffect());
    else if (p->getType() == "Def") setDefEffect(1.5 * p->getEffect());
    getPos()->notifyUsePotion(p);
}

void Drow::beAtkBy(Enemy* e){
    e->attack(this);
}

