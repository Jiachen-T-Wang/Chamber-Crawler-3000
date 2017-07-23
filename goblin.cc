#include "header.h"

Goblin::Goblin(Floor* f): Player{110, 110, 15, 20, f, "Goblin"} {} // type 用？

void Goblin::beAtkBy(Enemy* e){
    e->attack(this);
}
