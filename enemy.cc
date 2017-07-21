#include <iostream>
#include <cstdlib>
#include <cmath>
#include "enemy.h"
#include "observer.h"
#include "cell.h"
#include "treasure/treasure.h"
#include "treasure/smallGold.h"
#include "treasure/normalhoard.h"
using namespace std;

Enemy::Enemy(int HP, int atk, int def, string type)
: Character{HP, atk, def}, moveable{false}, type{type} {
  int x=rand() % 2;
  if(x){
    gold = make_shared<SmallGold>();
  }
  else{
    gold = make_shared<NormalHoard>();
  }
}

bool Enemy::canMove(){ return moveable; }

void Enemy::move(){
  getPos()->notifyMove(this);
}

int Enemy::calcDamage(Player* defender){
   return ceil((100/(100+defender->realDef())) * this->getAtk());
}

void Enemy::attack(Player* player){
  int notMiss = rand() % 2;
  if (notMiss){
    int damage = calcDamage(player);
    player->hurt(damage);
    getPos()->notifyEnemyAttack(this, damage);
  }
  else{
    getPos()->notifyMiss();
  }
}

void Enemy::attack(Vampire* v){
    attack(static_cast<Player*>(v));
}

void Enemy::attack(Drow* d){
    attack(static_cast<Player*>(d));
}

void Enemy::attack(Goblin* g){
    attack(static_cast<Player*>(g));
}


//如果死了 通知TD
void Enemy::beAtkBy(Player* p){
  p->attack(this);
  if(checkDead()){
    if(p->race == "Goblin"){
      p->incScore(5);
    }
    getPos()->setCont(nullptr);
    getPos()->notifyDead();
  }
}

Enemy::~Enemy() {}

