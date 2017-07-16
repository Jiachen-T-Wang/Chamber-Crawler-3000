#include "player.h"

Player::Player(int maxHP, int HP, int atk, int def, Floor* f, std::string race)
	: Character{maxHP, HP, atk, def}, f{f}, score{0}, race{race} {}

void Player::move(){

}

void Player::usePotion(Potion* p){

}

void Player::attack(Enemy* e){

}

void Player::PickGold(){
	
}
