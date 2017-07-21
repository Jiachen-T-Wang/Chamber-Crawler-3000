#ifndef __OBJECT_H__
#define __OBJECT_H__
#include <iostream>

class Cell;

class Object: public std::enable_shared_from_this<Object>{
   
   std::shared_ptr<Cell> position;
   
protected:
   
    std::shared_ptr<Cell> getPos();
   
public:
   
   void setPos(std::shared_ptr<Cell> p);
   
   Object();
   virtual bool isEnemy();
   virtual bool isPlayer();
   virtual bool isStair();
   virtual bool isPotion();
   virtual bool isTreasure();
   
};

#endif
