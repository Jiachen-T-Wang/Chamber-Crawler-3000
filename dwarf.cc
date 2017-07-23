#include "header.h"

Dwarf::Dwarf()
	: Enemy{100, 20, 30, "Dwarf"} {}

void Dwarf::attack(Vampire* v){
	int notMiss = rand() % 2;  
	if (notMiss){
		v->getAllerge();
		int damage = calcDamage(v);
		v->getHurt(damage);
		getPos()->notifyEnemyAttack(this, damage);
	}
	else{
		getPos()->notifyMiss();
	}
}

char Dwarf::symbol(){ return 'W';}


