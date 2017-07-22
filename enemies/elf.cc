#include "header.h"

Elf::Elf(): Enemy{140, 30, 10, "Elf"} {}

void Elf::attack(std::shared_ptr<Player> p){
	Enemy::attack(p);
	Enemy::attack(p);
}

void Elf::attack(std::shared_ptr<Drow> d){
	Enemy::attack(d);
}


