#include "orcs.h"

Orcs::Orcs(): Enemy{180, 30, 25, "Orcs"} {}

void Orcs::attack(Goblin* g){
	int notMiss = rand() % 2;  
	if (notMiss){
		int damage = 1.5 * calcDamage(player);
		player->getHurt(damage);
		getPosition()->notifyEnemyAttack(damage);
	}
	else{
		getPosition()->notyfyMiss();
	}
}