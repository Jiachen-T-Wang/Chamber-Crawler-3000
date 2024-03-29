#include <cmath>
#include "header.h"
using namespace std;

Player::Player(int HP, int atk, int def, int maxHP, std::string race)
: Character{HP, atk, def}, maxHP{maxHP}, atkEffect{0}, defEffect{0}, f{nullptr}, score{0}, goToNext{false},race{race} {}

void Player::changeFloor(){
   goToNext = true;
   resetEffect();
}
int Player::getMaxHP() const { return maxHP; }

void Player::setAtkEffect(int effect){
   atkEffect += effect;
}
void Player::setDefEffect(int effect){
   defEffect += effect;
}

bool Player::isPlayer() { return true;}

void Player::addHp(int hpEffect) {
   HP = (getHP() + hpEffect > maxHP) ? maxHP : getHP() + hpEffect;
}

void Player::resetEffect(){
   atkEffect = 0;
   defEffect = 0;
}

void Player::usePotion(Potion* p){
   string type = p->getType();
   int effect =p->getEffect();
   if (type == "Hp") addHp(effect);
   else if (type == "Atk") atkEffect += (effect);
   else if (type == "Def") defEffect += (effect);
   getPos()->notifyUsePotion(p);
}

void Player::moveTo(Dir dir){
   Cell* nb = getPos()->getNeighbour(dir);
   shared_ptr<Object> cont = nb->getContent();
    
   if(cont.get() && cont->isTreasure()){
      Treasure* gd = (Treasure*)cont.get();
       if(gd->canPickUp()){
           this->PickGold(gd);
           nb->setCont(nullptr);
       }
       else{
           gd->switchPlayer();
  //         getPos()->setInvisible(true);
           getPos()->setCont(nullptr);
           setPos(nb);
           
           getPos()->notifyPlayerMove(dir);
           return;
       }
   }
    
   if(cont.get() && cont->isStair()){
      changeFloor();
   } else if((nb->getContent() == nullptr && nb->canStand())){
       if(getPos()->getContent()->isTreasure()){
           Treasure* gd = (Treasure*)getPos()->getContent().get();
           gd->switchPlayer();
           setPos(nb);
           nb->setCont(std::shared_ptr<Player>(this));
       }
       else{
           Character::moveTo(dir);
           getPos()->notifyPlayerMove(dir);
       }
   }
   
   else{
      getPos()->notifyCannotMove();
   }

}

int Player::showFloor(){
   return f->getLevel();
}


int Player::realAtk(){
   return (getAtk() + atkEffect < 0) ? 0 : getAtk() + atkEffect;
}

int Player::realDef(){
   return (getDef() + defEffect < 0) ? 0 : getDef() + defEffect;
}

int Player::calcDamage(Enemy* defender){
   return ceil((100 * this->realAtk()/(100+defender->getDef())) );
}


void Player::attack(Enemy* enemy){
   int damage = calcDamage(enemy);
   enemy->getHurt(damage);
   getPos()->notifyPlayerAttack(enemy, damage);
}

void Player::attack(Halfling* h){
   int notMiss = rand() % 2;
   if (notMiss){
      int damage = calcDamage(h);
      h->getHurt(damage);
      getPos()->notifyPlayerAttack(h, damage);
   }
   else{
      getPos()->notifyMiss();
   }
}


void Player::beAtkBy(Enemy* enemy){
   enemy->attack(this);
}

void Player::setFloor(Floor* f){
   this->f = f;
}

int Player::showScore(){ return score; }

int Player::getGold(){ return score;}

void Player::incScore(int value){ score += value; }

void Player::PickGold(Treasure* gold){
   incScore(gold->getValue());
}

void Player::roundChange(){}

char Player::symbol(){return '@';}

bool Player::getGoToNext(){
   return goToNext;
}
void Player::notGoToNext(){
   goToNext = false;
}

Player::~Player() {}
