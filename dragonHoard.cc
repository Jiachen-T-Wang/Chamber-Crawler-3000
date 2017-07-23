#include "header.h"

DragonHoard::DragonHoard():
    Treasure{"DragonHoard", 6}
    , dragon{make_shared<Dragon>(std::shared_ptr<Treasure>(this))} {
        while(1){
            int d = rand() % 8;
            Cell* nb = this->getPos()->getNeighbour(dragon->numToDir(d));
            if (nb->getContent().get() == nullptr){
                nb->setCont(dragon);
                dragon->setPos(nb);
                break;
            }
        }
  //  dragon->setPos(this->getPos()->getNeighbour(dragon->numToDir(d)));
}

std::shared_ptr<Dragon> DragonHoard::getDragon(){
    return dragon;
}

