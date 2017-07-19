#include "dwarf.h"

Dwarf::Dwarf()
	: Enemy{100, 20, 30, "Dwarf"} {}

Dwarf::attack(Vampire* v){
	int notMiss = rand() % 2;  
	if (notMiss){
		v->getAllerge();
		int damage = calcDamage(v);
		v->getHurt(damage);
		getPosition()->notifyEnemyAttack(damage);
	}
	else{
		getPosition()->notyfyMiss();
	}
}
