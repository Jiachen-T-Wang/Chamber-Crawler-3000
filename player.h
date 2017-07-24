#ifndef __PLAYER_H__
#define __PLAYER_H__
#include <iostream>
#include <string>
#include "character.h"
#include "potion.h"

class Enemy;
class Floor;
class Halfling;
class Treasure;

class Player: public Character{
    const int maxHP;
    int atkEffect; // set to 0 when change floor
    int defEffect; // set to 0 when change floor
    Floor* f;
    int score;
    bool goToNext;
   
protected:
    int calcDamage(Enemy* defender);
   
public:
    int getGold();                
    bool isPlayer() override;
    const std::string race;
    bool getGoToNext();
    void notGoToNext();
    void changeFloor();
    Player(int HP, int atk, int def, int maxHP, std::string race);
    int getMaxHP() const;
    void addHp(int hpEffect);
    void moveTo(Dir dir) override;
   
    void setAtkEffect(int effect);
    void setDefEffect(int effect);
   
    int realAtk();
    int realDef();
    void resetEffect();
    int showFloor();
    virtual int showScore();
    virtual void incScore(int value);
    virtual void usePotion(Potion* p);
   
    virtual void attack(Enemy* p);
    virtual void attack(Halfling* h);
   
    virtual void beAtkBy(Enemy* enemy);
    virtual void PickGold(Treasure* gold);
    virtual void roundChange();   //每一轮都发生的变化
    void setFloor(Floor* f);
    char symbol() override;
    virtual ~Player() = 0;
};

#endif
