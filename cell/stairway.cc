#include "stairway.h"

Stairway::Stairway(int x, int y): x{x}, y{y}, type{"Stairway"} {}

bool Stairway::canStand() override { return false; }

bool Stairway::getCanStandByAll() override { return false; }
