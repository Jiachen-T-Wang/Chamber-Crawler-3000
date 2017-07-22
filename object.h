#ifndef __OBJECT_H__
#define __OBJECT_H__
#include <iostream>

class Cell;

class Object{
   
   std::shared_ptr<Cell> position;

   
public:

   Object();
   std::shared_ptr<Cell> getPos();
   
   void setPos(std::shared_ptr<Cell> p);
   
   virtual bool isEnemy();
   virtual bool isPlayer();
   virtual bool isStair();
   virtual bool isPotion();
   virtual bool isTreasure();
   
};

#endif
