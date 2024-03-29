#include "header.h"

DragonHoard::DragonHoard():
Treasure{"DragonHoard", 6}, dragon{nullptr}, canPick{false}, bePlayer{false} {}

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

void DragonHoard::setDragon(Dragon* dragon){
    this->dragon = std::shared_ptr<Dragon>(dragon);
    dragon->setHoard(this);
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
        return 'G';
}

void DragonHoard::switchPlayer(){
    if(bePlayer)
        bePlayer = false;
    else
        bePlayer = true;
}

