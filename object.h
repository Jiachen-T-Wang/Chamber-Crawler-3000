#ifndef __OBJECT_H__
#define __OBJECT_H__
#include <iostream>

class Cell;

class Object: public std::enable_shared_from_this<Object>{
   
   std::shared_ptr<Cell> position;

   
public:
   std::shared_ptr<Cell> getPos();
   
   void setPos(std::shared_ptr<Cell> p);
   
   Object();
   virtual bool isEnemy();
   virtual bool isPlayer();
   virtual bool isStair();
   virtual bool isPotion();
   virtual bool isTreasure();
   
};

#endif
