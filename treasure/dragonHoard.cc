#include "dragonHoard.h"

DragonHoard::DragonHoard(): Treasure{"DragonHoard", 6}, dragon{make_weak(this)} {
    int d = rand() % 8;
    dragon->setPos(getPos()->getNeighbour(numToDir(d)));
}

std::shared_ptr<Dragon> DragonHoard::getDragon(){
    return dragon;
}

