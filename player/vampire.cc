#include <climits>
#include "vampire.h"


//has no maximum HP
Vampire::Vampire(Floor* f)
	: Player{INT_MAX, 50, 25, 25, f, "Vampire"}
	, allerge{false} {}

//gains 5 HP every successful attack, wow!
//but if it allerge, then lose 5 HP
void Vampire::attack(Enemy* e){
	//insert attack code here
	if (allerge)
		HP -= 5;    //改成setHP()？
	else
		HP += 5;
}