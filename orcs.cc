#include "header.h"

Orcs::Orcs(): Enemy{180, 30, 25, "Orcs"} {}

void Orcs::attack(std::shared_ptr<Goblin> g){
	int notMiss = rand() % 2;  
	if (notMiss){
		int damage = 1.5 * calcDamage(g);
		g->getHurt(damage);
       getPos()->notifyEnemyAttack(this, damage);
	}
	else{
		getPos()->notifyMiss();
	}
}

char Orcs::symbol(){return 'O';}
