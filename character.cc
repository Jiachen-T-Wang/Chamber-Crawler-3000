#include <cstdlib>
#include "character.h"

Character::Character(int HP, int atk, int def)
	: Object{}, HP{HP}, atk{atk}, def{def} {}

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

}

void Character::checkDead(){
	return (HP <= 0);
}