#include "character.h"

Character(int maxHP, int HP, int atk, int def)
	: maxHP{maxHP}, HP{HP}, atk{atk}, def{def} {}

void Character::checkDead(){
	return (HP <= 0);
}