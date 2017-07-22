#include "shade.h"

Shade::Shade(Floor* f): Player{125, 125, 25, 25, f, "Shade"} {}

int Shade::showScore(){
	int random = rand() % 2;
	return (1+0.5*random) * Player::showScore();
}
