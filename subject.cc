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
			int dir = rand() % 8;  //这个可以再转化为NO, NE, ... 现在有点困不想改
			if (!(observers[dir]->getContent())){  //if that direction does not have object
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
	Observer* enemy = observers[dir];
	enemy->beAtkBy(player);
}

void notifyMiss(){
	observers[TD]->Miss();
}










