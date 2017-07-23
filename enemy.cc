#include <iostream>
#include <cstdlib>
#include <cmath>
#include "header.h"

using namespace std;

Dir Enemy::numToDir(int d){
    switch (d) {
        case 0:
            return Dir::no; break;
        case 1:
            return Dir::ne; break;
        case 2:
            return Dir::nw; break;
        case 3:
            return Dir::so; break;
        case 4:
            return Dir::sw; break;
        case 5:
            return Dir::se; break;
        case 6:
            return Dir::we; break;
        default:
            return Dir::ea;break;
    }
}

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
   return ceil((100/(100+defender->realDef())) * this->getAtk());
}

void Enemy::attack(Player* player){
  int notMiss = rand() % 2;
  if (notMiss){
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
    if(p->race == "Goblin"){
      p->incScore(5);
    }
    gold->setPos(getPos());
    getPos()->notifyDead();
  }
}

bool Enemy::isDragon(){
   return false;
}
Enemy::~Enemy() {}

