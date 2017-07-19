#ifndef __ELF_H__
#define __ELF_H__

#include "enemy.h"

class Floor;

//gets two attacks against every race except drow
class Elf: public Enemy{
public:
	Elf();
	void attack(Player* p) override;
};

#endif
