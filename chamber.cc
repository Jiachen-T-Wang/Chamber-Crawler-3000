#include "chamber.h"
#include <cstdlib>
#include <ctime>
#include "cell.h"

Chamber::Chamber(): size{0}{
   
}

Cell *Chamber::randCell(){
   srand(time(0));
   int x=rand() % size;
   while(cells[x]->getContent()){
      srand(time(0));
      int x=rand() % size;
   }
   return cells[x];
}

void Chamber::addCell(Cell *c){
   cells.emplace_back(c);
   size++;
}

void Chamber::addEnemy(){
   randCell()->spawnEnemy();
}
void Chamber::addPotion(){
   randCell()->spawnPotion();
}
void Chamber::addGold(){
   randCell()->spawnEnemy();
}




