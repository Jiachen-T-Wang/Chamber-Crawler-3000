#include "dragon.h"

void Dragon::Dragon(std::shared_ptr<DragonHoard> hoard)
	: Enemy{150, 20, 20}, hoard{hoard} {}

