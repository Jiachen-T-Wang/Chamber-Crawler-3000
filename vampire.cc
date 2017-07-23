#include <climits>
#include "header.h"


//has no maximum HP
Vampire::Vampire(Floor* f)
	: Player{50, 25, 25, INT_MAX, f, "Vampire"}
	, allerge{false} {}

void Vampire::getAllerge(){
	allerge = true;
}

//gains 5 HP every successful attack, wow!
//but if it allerge, then lose 5 HP
//may need to implement another function to handle the case of halfling!!!
void Vampire::attack(Enemy* e){
	Player::attack(e);
	if (allerge)
		getHurt(5);    
	else
		getHurt(-5);
}

void Vampire::attack(Halfling* h){
	int notMiss = rand() % 2;  
	if (notMiss){
		int damage = calcDamage(h);
		h->getHurt(damage);
		getPos()->notifyPlayerAttack(h, damage);
		if (allerge)
			getHurt(5);    
		else
			getHurt(-5);
	}
	else{
		getPos()->notifyMiss();
	}
}

void Vampire::beAtkBy(Enemy* e){
    e->attack(std::shared_ptr<Vampire>(this));
}
