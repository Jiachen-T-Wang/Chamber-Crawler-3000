#include <climits>
#include "vampire.h"


//has no maximum HP
Vampire::Vampire(Floor* f): Player{INT_MAX, 50, 25, 25, f, "Vampire"} {}

//gains 5 HP every successful attack, wow!
void Vampire::attack(Enemy* e){
	//insert attack code here
	HP += 5;
}