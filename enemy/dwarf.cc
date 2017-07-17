#include "dwarf.h"

Dwarf::Dwarf()
	: Enemy{100, 20, 30} {}

void Dwarf::attack(Player* p){
	if (p->race == "Vampire"){
		p->getAllerge();
	}
	//other code
}