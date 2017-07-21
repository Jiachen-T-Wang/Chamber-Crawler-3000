#ifndef __DWARF_H__
#define __DWARF_H__

#include "../enemy.h"

class Floor;

//Vampires are allergic to dwarves and lose 5HP rather than gain
class Dwarf: public Enemy{
	
public:
	Dwarf();
	void attack(Vampire* v) override;
	void beAtkBy(Player* p) override;
};

#endif
