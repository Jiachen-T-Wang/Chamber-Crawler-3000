#ifndef __OBJECT_H__
#define __OBJECT_H__
#include <iostream>

class Cell;

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
   
};

#endif
