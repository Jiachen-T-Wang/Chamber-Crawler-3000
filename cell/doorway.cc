#include "doorway.h"

Doorway::Doorway(int x, int y): x{x}, y{y}, type{"Doorway"}{}

bool Doorway::canStand() override { return true; }

bool Doorway::getCanStandByAll() override { return false; }
