#include "header.h"

DragonHoard::DragonHoard():
    Treasure{"DragonHoard", 6}
    , dragon{make_shared<Dragon>(std::shared_ptr<DragonHoard>(this))} {
    int d = rand() % 8;
    dragon->setPos(this->getPos()->getNeighbour(dragon->numToDir(d)));
}

std::shared_ptr<Dragon> DragonHoard::getDragon(){
    return dragon;
}

