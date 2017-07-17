#include "tile.h"

Tile::Tile(int x, int y): x{x}, y{y}, type{"Tile"} {}

bool Tile::canStand() override { return true; }
