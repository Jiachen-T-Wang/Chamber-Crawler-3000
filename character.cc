#include "character.h"

Character(int HP, int atk, int def)
	: HP{HP}, atk{atk}, def{def} {}

void Character::checkDead(){
	return (HP <= 0);
}