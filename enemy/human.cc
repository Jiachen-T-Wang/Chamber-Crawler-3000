#include <cmath>
#include "human.h"

Human::Human()
	: Enemy{140, 20, 20, "Human"} {}

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