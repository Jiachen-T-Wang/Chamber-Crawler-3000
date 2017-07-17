#include "goblin.h"

Goblin::Goblin(Floor* f): Player{110, 110, 15, 20, f, "Goblin"} {} 

//steals 5 gold from every slain enemy
void Goblin::attack(Enemy* e){
	
}