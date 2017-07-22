#include <iostream>
#include "dir.h"
#include <cstdlib>
#include <cmath>
#include "enemy.h"
#include "player.h"
#include "observer.h"
#include "cell.h"
#include "treasure/treasure.h"
#include "treasure/smallGold.h"
#include "treasure/normalhoard.h"

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
: Character{HP, atk, def}, moveable{false}, type{type} {
  int x=rand() % 2;
  if(x){
    gold = make_shared<SmallGold>();
  }
  else{
    gold = make_shared<NormalHoard>();
  }
}

bool Enemy::isEnemy() { return true;}

bool Enemy::canMove(){ return moveable; }

void Enemy::enableMove(){
   moveable = true;
}
void Enemy::move(){
    while(1){
        int d = rand() % 8;
        Cell* nb = getPos()->getNeighbour(numToDir(d));
        if(!nb || !(nb->canStand())){
            Character::moveTo(numToDir(d));
            break;
        }
    }

    int dir = rand() % 8;
    Character::moveTo(numToDir(dir));
    moveable = false;
}

int Enemy::calcDamage(std::shared_ptr<Player> defender){
   return ceil((100/(100+defender->realDef())) * this->getAtk());
}

void Enemy::attack(std::shared_ptr<Player> player){
  int notMiss = rand() % 2;
  if (notMiss){
    int damage = calcDamage(player);
    player->getHurt(damage);
    getPos()->notifyEnemyAttack(std::shared_ptr<Enemy>{this}, damage);
  }
  else{
    getPos()->notifyMiss();
  }
}

void Enemy::attack(std::shared_ptr<Vampire> v){
    attack(std::shared_ptr<Player>(v));
}

void Enemy::attack(std::shared_ptr<Drow> d){
    attack(std::shared_ptr<Player>(d));
}

void Enemy::attack(std::shared_ptr<Goblin>(g)){
    attack(std::shared_ptr<Player>(g));
}

void Enemy::beAtkBy(std::shared_ptr<Player> p){
  p->attack(std::shared_ptr<Enemy>(this));
  if(checkDead()){
    if(p->race == "Goblin"){
      p->incScore(5);
    }
    getPos()->setCont(gold);
    getPos()->notifyDead();
  }
}

bool Enemy::isDragon(){
   return false;
}
Enemy::~Enemy() {}

