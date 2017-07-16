#include "human.h"

Human::Human(int HP, int atk, int def)
	: Enemy{HP, atk, def} {}

void Human::beAtkBy(Player* p){
	int damage = calcDamage(p, this);
}