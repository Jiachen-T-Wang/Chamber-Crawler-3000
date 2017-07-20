#include <climits>
#include "vampire.h"


//has no maximum HP
Vampire::Vampire(Floor* f)
	: Player{INT_MAX, 50, 25, 25, f, "Vampire"}
	, allerge{false} {}

void Vampire::getAllerge(){
	allerge = true;
}

//gains 5 HP every successful attack, wow!
//but if it allerge, then lose 5 HP
//may need to implement another function to handle the case of halfling!!!
void Vampire::attack(Player* p){
	Player::attack(Player* p);
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
		getPosition()->notifyPlayerAttack(damage);
		if (allerge)
			getHurt(5);    
		else
			getHurt(-5);
	}
	else{
		getPosition()->notyfyMiss();
	}
}

void Vampire::beAtkBy(Enemy* e){
	e->attack(this);
	if(checkDead()){
		//游戏结束
	}
}