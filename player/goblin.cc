#include "goblin.h"

Goblin::Goblin(Floor* f): Player{110, 110, 15, 20, f, "Goblin"} {} 

void Goblin::beAtkBy(Orcs* e){
	int damage = 1.5 * calcDamage(enemy);
	getHurt(damage);
	if(checkDead()){
		//游戏结束
	}
}

//steals 5 gold from every slain enemy
/*
void Goblin::attack(Enemy* e){
	
}
*/