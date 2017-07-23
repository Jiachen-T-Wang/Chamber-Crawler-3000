#include "header.h"

Goblin::Goblin(): Player{110, 15, 20, 110, "Goblin"} {} // type 用？

void Goblin::beAtkBy(Enemy* e){
    e->attack(this);
}
