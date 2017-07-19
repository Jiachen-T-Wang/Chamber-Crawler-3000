#include "halfling.h"

Halfling::Halfling(): Enemy{100, 15, 20, "Halfling"} {}

void Halfling::beAtkBy(Player* p){
	p->attack(this);
} 