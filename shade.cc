#include "header.h"

Shade::Shade(Floor* f): Player{125, 25, 25, 125, f, "Shade"} {}

int Shade::showScore(){
	int random = rand() % 2;
	return (1+0.5*random) * Player::showScore();
}
