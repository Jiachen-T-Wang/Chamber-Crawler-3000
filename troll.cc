#include "troll.h"

Troll::Troll(Floor* f): Player{120, 120, 25, 15, f, "Troll"} {}

void Troll::regainHP(){
	HP += 5;
}