#include <cstdlib>
#include <cmath>
#include "character.h"

Character::Character(int HP, int atk, int def)
	: Object{}, HP{HP}, atk{atk}, def{def} {}

int Character::calcDamage(Character* attacker, Character* defender){
	return ceil((100/(100+defender->getDef())) * attacker->getAtk());
}

Character::getHP(){
	return HP;
}

Character::getAtk(){
	return atk;
}

Character::getDef(){
	return def;
}

Character::move(){
		Cell* curP = getPosition();
		curP->notifyObservers(this);
}

void Character::checkDead(){
	return (HP <= 0);
}
