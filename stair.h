#ifndef _STAIR_H
#define _STAIR_H

#include "object.h"

class Stair: public Object{
   
public:
   Stair();
   bool isStair() override;
   
};
#endif
