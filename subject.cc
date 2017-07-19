#include <cstdlib>
#include "subject.h"
#include "observer.h"
#include "subscriptions.h"

void Subject::attach(Observer *o) { observers.push_back(o); }

void Subject::notifyObservers() {
  for (int i = 0; i < observers.size(); i++) {
    observers[i]->notify(*this);
  }
}

//this is for move
void notifyMove(Character* man, int dir = -1){
	if (dir < 0){
		while (1){
			int dir = rand() % 8;
			if (!(observers[dir]->getContent())){
				observers[dir]->notify(man);
				break;
			}
		}
	}
	else{
		if(!(observers[dir]->getContent())){
			observers[dir]->notify(man);
		}
		else{
			cout << "you cannot go this direction!!!" << endl;
		}
	}
	observers[TD]->notify();
}

void notifyEnemy(Player* player, int dir){
	Observer* enemy = observers[dir]->getContent();
	enemy->beAtkBy(player);
}

void notifyMiss(){
	observers[TD]->displayMiss();
}

void notifyDead(){
	observers[TD]->displayDead();
}












