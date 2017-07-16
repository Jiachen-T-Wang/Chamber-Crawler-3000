#include "player.h"

Player::Player(int HP, int atk, int def, int maxHP, Floor* f, std::string race)
	: Character{HP, atk, def}, maxHP{maxHP}, f{f}, score{0}, race{race} {}

void Player::move(int dir){
	Cell* curP = getPosition();
	curP->notifyObservers(this, int dir);
}

void Player::usePotion(Potion* p){

}

void Player::attack(Enemy* e){

}

void Player::PickGold(){
	
}
