#ifndef __OBJECT_H__
#define __OBJECT_H__
#include <iostream>
#include <memory>

class Cell;
class Player;
class Enemy;

class Object{
   
   Cell* position;
   
public:

   Object();
    
   Cell* getPos();
   void setPos(Cell* p);
   
   virtual bool isEnemy();
   virtual bool isPlayer();
   virtual bool isStair();
   virtual bool isPotion();
   virtual bool isTreasure();
   virtual char symbol()=0;
    virtual bool isDragon();
};

#endif
