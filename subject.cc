#include <cstdlib>
#include <iostream>
#include "subject.h"
#include "observer.h"
using namespace std;

/*
void Subject::notifyObservers() {
  for (int i = 0; i < observers.size(); i++) {
    observers[i]->notify(*this);
  }
}
*/

//this is for move
/*
void Subject::notifyMove(Character* man, int dir = -1){
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



void Subject::notifyMove(Enemy* e){
	while (1){
		int dir = rand() % 8;
		if (!(observers[dir]->getContent())){
			observers[dir]->getMove(e, dir);
			break;
		}
	}
}

void Subject::notifyEnemyAttack(Enemy* e, int damage){
	observers[TD]->displayEnemyAtk(e, damage);
}

void Subject::notifyMiss(){
	observers[TD]->displayMiss();
 */
}

void Subject::attach(Observer *o) { observers.emplace_back(o); }



void Subject::notifyObservers(){
   for(auto ob:observers) ob->notify();
}










