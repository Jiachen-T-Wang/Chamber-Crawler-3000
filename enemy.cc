#include <iostream>
#include <cstdlib>
#include <cmath>
#include "header.h"

using namespace std;


Enemy::Enemy(int HP, int atk, int def, string type)
: Character{HP, atk, def}, moveable{true}, type{type} {
  int x=rand() % 2;
  if(x){
    gold = make_shared<SmallGold>();
  }
  else{
    gold = make_shared<NormalHoard>();
  }
}

std::string Enemy::getType(){return type;}

bool Enemy::isEnemy() { return true;}

bool Enemy::canMove(){ return moveable; }

void Enemy::enableMove(){
   moveable = true;
}
void Enemy::move(){
    while(1){
        int d = rand() % 8;
        Cell* nb = getPos()->getNeighbour(numToDir(d));
        if((nb->getContent().get() == nullptr) && (nb->canStandByAll())){
            Character::moveTo(numToDir(d));
            break;
        }
    }
    moveable = false;
}

int Enemy::calcDamage(Player* defender){
   return ceil((100 * this->getAtk()/(100+defender->realDef())));
}

void Enemy::attack(Player* player){
  int notMiss = rand() % 2;
  if (notMiss == 1){
    int damage = calcDamage(player);
    player->getHurt(damage);
    getPos()->notifyEnemyAttack(this, damage);
  }
  else{
    getPos()->notifyMiss();
  }
}

void Enemy::attack(Vampire* v){
    attack((Player*)(v));
}

void Enemy::attack(Drow* d){
    attack((Player*)(d));
}

void Enemy::attack(Goblin* g){
    attack((Player*)(g));
}

void Enemy::beAtkBy(Player* p){
  p->attack(this);
  if(checkDead()){
    getPos()->notifyDead();
    if(p->race == "Goblin"){
      p->incScore(5);
    }
    if(drop){
        gold->setPos(getPos());
        getPos()->setCont(gold);
    }
    else{
        p->incScore(gold->getValue());
        getPos()->setCont(nullptr);
    }
  }
}

void Enemy::canDrop(){
    drop = true;
}

Enemy::~Enemy() {}

