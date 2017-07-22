#include "header.h"

Goblin::Goblin(Floor* f): Player{110, 110, 15, 20, f, "Goblin"} {} // type 用？

void Goblin::beAtkBy(std::shared_ptr<Enemy> e){
    e->attack(std::shared_ptr<Goblin>(this));
}
