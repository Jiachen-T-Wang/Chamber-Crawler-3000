#include "elf.h"

Elf::Elf(): Enemy{140, 30, 10, "Elf"} {}

void Elf::attack(Player* p){
	if (p->race != "drow"){
		Enemy::attack(p);
		Enemy::attack(p);
	}
	else{
		Enemy::attack(p);
	}
}
