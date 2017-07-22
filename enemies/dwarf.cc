#include "header.h"

Dwarf::Dwarf()
	: Enemy{100, 20, 30, "Dwarf"} {}

Dwarf::attack(std::shared_ptr<Vampire> v){
	int notMiss = rand() % 2;  
	if (notMiss){
		v->getAllerge();
		int damage = calcDamage(v);
		v->getHurt(damage);
		getPosition()->notifyEnemyAttack(std::shared_ptr<Dwarf>{this}, damage);
	}
	else{
		getPosition()->notyfyMiss();
	}
}


