#include "chamber.h"
#include <cstdlib>
#include <ctime>
#include "cell.h"

Chamber::Chamber(): size{0}{
   
}
Cell *Chamber::randCell(){
   srand(time(0));
   int x=rand() % size;
   return cells[x];
}

Chamber::addCell(Cell *c){
   cells.emplace_back(c);
   size++;
}

void Chamber::addEnemy();
void Chamber::addPotion();
void Chamber::addGold();




