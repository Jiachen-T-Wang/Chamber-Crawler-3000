#include "elf.h"

Elf::Elf(): Enemy{140, 30, 10, "Elf"} {}

void Elf::attack(Player* p){
	Enemy::attack(p);
	Enemy::attack(p);
}

void Elf::attack(Drow* d){
	Enemy::attack(d);
}


