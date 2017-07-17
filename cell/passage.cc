#include "passage.h"

Passage::Passage(int x, int y): x{x}, y{y}, type{"Passage"} {}

bool Passage::canStand() override { return true; }

bool Passage::getCanStandByAll() override { return false; }
