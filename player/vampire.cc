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
void Vampire::attack(int dir){
	Player::attack(dir);
	if (allerge)
		getHurt(5);    
	else
		getHurt(-5);
}

void Vampire::beAtkBy(Enemy* enemy){
	if(enemy->type == "Dwarf"){
		getAllerge();
	}
	Player::beAtkBy(Enemy* enemy);
}