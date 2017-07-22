#include "header.h"

DragonHoard::DragonHoard(): Treasure{"DragonHoard", 6}, dragon{make_shared<Dragon>(this)} {
    int d = rand() % 8;
<<<<<<< HEAD
    dragon->setPos(getPos()->getNeighbour(dragon->numToDir(d)));
=======
   dragon->setPos(getPos()->getNeighbour(numToDir(d)));
>>>>>>> 73746232d9b54f36e39cf3a4a953def1e98feacc
}

std::shared_ptr<Dragon> DragonHoard::getDragon(){
    return dragon;
}

