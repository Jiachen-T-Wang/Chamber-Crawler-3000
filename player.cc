#include <cmath>
#include "player.h"

Player::Player(int HP, int atk, int def, int maxHP, Floor* f, std::string race)
	: Character{HP, atk, def}, maxHP{maxHP}, f{f}, score{0}, race{race} {}

int Player::getMaxHP() const { return maxHP; }

void Player::move(int dir){
	Cell* curP = getPosition();
	curP->notifyObservers(this, int dir);
}

//一会儿做
void Player::usePotion(Potion* p){

}

//
void Player::attack(int dir){
	Cell* curP = getPosition();
	curP->notifyEnemy(this, dir);
}

void Player::beAtkBy(Enemy* enemy){
	int damage = ceil((100/(100+getDef())) * getAtk(enemy));
	getHurt(damage);
	if(checkDead()){
		//游戏结束
	}
}

void Player::PickGold(){
	
}

Player::~Player() {}
