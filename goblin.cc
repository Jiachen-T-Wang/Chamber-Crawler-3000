#include "header.h"

Goblin::Goblin(): Player{110, 15, 20, 110, "Goblin"} {}

void Goblin::beAtkBy(Enemy* e){
    e->attack(this);
}
