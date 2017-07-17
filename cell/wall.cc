#include "wall.h"

Wall::Wall(int x, int y): x{x}, y{y}, type{"Wall"} {}

bool Wall::canStand() override { return false; }
