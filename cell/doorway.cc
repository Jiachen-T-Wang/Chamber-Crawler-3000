#include "doorway.h"

Doorway::Doorway(int x, int y): x{x}, y{y}, type{"Doorway"}{}

bool Doorway::canStand() override { return false;}
