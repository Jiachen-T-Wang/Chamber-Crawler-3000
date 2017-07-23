#include "header.h"

Troll::Troll(): Player{120, 25, 15, 120, "Troll"} {}

void Troll::roundChange(){
	addHp(5);
}

