#include "header.h"

DragonHoard::DragonHoard():
Treasure{"DragonHoard", 6}, dragon{nullptr}, canPick{false}, bePlayer{false} {
  //  dragon->setPos(this->getPos()->getNeighbour(dragon->numToDir(d)));
}

void DragonHoard::setDragon(){
    dragon =  make_shared<Dragon>(this);
    while(1){
        int d = rand() % 8;
        Cell* nb = this->getPos()->getNeighbour(dragon->numToDir(d));
        if (nb->getContent().get() == nullptr && nb->canStandByAll()){
            nb->setCont(dragon);
            dragon->setPos(nb);
            break;
        }
    }
}

std::shared_ptr<Dragon> DragonHoard::getDragon(){
    return dragon;
}

bool DragonHoard::canPickUp(){
    return canPick;
}

void DragonHoard::removeDragon(){
    canPick = true;
}



char DragonHoard::symbol(){
    if(bePlayer)
        return '@';
    else
        return 'D';
}

void DragonHoard::switchPlayer(){
    if(bePlayer)
        bePlayer = false;
    else
        bePlayer = true;
}

