#include "empty.h"

Empty::Empty(int x, int y): x{x}, y{y}, type{"Empty"} {}

bool Empty::canStand() override { return false; }

bool Empty::getCanStandByAll() override { return false; }
