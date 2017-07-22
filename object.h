#ifndef __OBJECT_H__
#define __OBJECT_H__
#include <iostream>

class Cell;

class Object{
   
   std::shared_ptr<Cell> position;
<<<<<<< HEAD

   
public:
   std::shared_ptr<Cell> getPos();
   
=======
   
public:

   Object();
   std::shared_ptr<Cell> getPos();
>>>>>>> 04f08c9c36732965fbf08819e3d8c9fa993d46de
   void setPos(std::shared_ptr<Cell> p);
   
   virtual bool isEnemy();
   virtual bool isPlayer();
   virtual bool isStair();
   virtual bool isPotion();
   virtual bool isTreasure();
   
};

#endif
