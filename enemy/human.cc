#include <cmath>
#include "human.h"

Human::Human(int HP, int atk, int def)
	: Enemy{HP, atk, def} {}

void Human::beAtkBy(Player* p){
	int damage = calcDamage(p, this);
	getHurt(damage);
	if(checkDead()){
		position->notifyDead();
		Treasure* g1 = new NormalGold();
		Treasure* g2 = new NormalGold();
		position->dropGold(g1, g2);
	}
}