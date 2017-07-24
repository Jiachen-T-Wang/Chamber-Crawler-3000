#include <iostream>
#include <memory>
#include "header.h"

using namespace std;

Dir stringToDir(string d){
   if (d == "no") return Dir::no;
   else if (d =="so") return Dir::so;
   else if (d =="ea") return Dir::ea;
   else if (d =="se") return Dir::se;
   else if (d =="we") return Dir::we;
   else if (d =="ne") return Dir::ne;
   else if (d =="nw") return Dir::nw;
   else return Dir::sw;
}

shared_ptr<Object> fetchNeighbourObject(shared_ptr<Player> p, string dir){
   return p->getPos()->getNeighbour(stringToDir(dir))->getContent();
}

bool Merchant::angry{false};
bool Enemy::drop{false};

void printcover() {
   cout << "|-----------------------------------------------------------------------------|" << endl;
   for (int i=0; i<6;i++)
      cout << "|                                                                             |" << endl;
   cout << "|                      The Game of ChamberCrawler3000                         |" << endl;
   cout << "|                                                                             |" << endl;
   cout << "|           s - shade                                                         |" << endl;
   cout << "|           d - Drow                                                          |" << endl;
   cout << "|           v - Vampire                                                       |" << endl;
   cout << "|           g - Goblin                                                        |" << endl;
   cout << "|           t - Troll                                                         |" << endl;
   cout << "|                                                                             |" << endl;
   cout << "|           q - quit                                                          |" << endl;
   for (int i=0; i<8;i++)
      cout << "|                                                                             |" << endl;
   cout << "|-----------------------------------------------------------------------------|" << endl;
   cout << endl << "DESIGNED BY" << endl;
   cout << "Yuxin Zhu" << endl;
   cout << "Tianhao Wang" << endl;
   cout << "Jiayang Fan" << endl;
}

bool oneRound(Floor &f, shared_ptr<Player> p){
   f.gothroughBoard(p);
   f.display();
   if(p->checkDead()) {
      cout <<"u r dead!" <<endl;
      return true;
   }
   p->roundChange();
   if(p->getGoToNext()) return true;
   return false;
}

int main(int argc, const char * argv[]) {
   int levelNum = 5;
   string fileName;
  for (int i = argc - 1; i != 0; i --)
  {
    string temp = argv[i];
    if (temp == "drop") Enemy::canDrop();
    else fileName = argv[i];
  }
   
Restart:
   
   shared_ptr<Player> p;
   string race;
   
   printcover();
   
   while (cin >> race) {
      if (race == "s") {
         p = make_shared<Shade>();
         break;
      }
      else if (race == "d") {
         p = make_shared<Drow>();
         
         break;
      }
      else if (race == "v") {
         p = make_shared<Vampire>();
         break;
      }
      else if (race == "g") {
         p = make_shared<Goblin>();
         break;
      }
      else if (race == "t") {
         p = make_shared<Troll>();
         break;
      }
      else if (race == "q") {
         cout << "bye" <<endl;
         exit(0);
      }
   }
   if(cin.eof()) {
      cout << "bye" <<endl;
      exit(0);
   }
   int level=0;
   string cmd;
   bool enemyMove = true;
   while(level<levelNum){
      p->notGoToNext();
      //    if(arg) Floor f {i, p, fileName};
      //    else
      Floor f {level, p, enemyMove};
      
      string direction;
      //       Merchant::angry = false;
      
      while (cin >> cmd) {
         if (cmd == "no"|| cmd == "so" ||cmd == "ea" ||cmd == "we"
             ||cmd == "ne" ||cmd == "nw" ||cmd == "se" ||cmd == "sw"){
            p.get()->moveTo(stringToDir(cmd));//p
            if(oneRound(f, p)) break;
         }
         else if (cmd == "u") {
            if(cin >> direction) {
               shared_ptr<Object> o =fetchNeighbourObject(p, direction);
               if (o.get() && o->isPotion()){
                  Potion *drug=(Potion*)o.get();
                  p.get()->usePotion(drug);//p
                  o->getPos()->setCont(nullptr);
                  if(oneRound(f,p)) break;
               }
               // else 不是potion
            }
         }
         else if (cmd == "a") { // attack enemy
            
            if(cin >> direction) {
               shared_ptr<Object> o = fetchNeighbourObject(p, direction);
               if (o.get() && o->isEnemy()){
                  Enemy *e =(Enemy*)o.get();
                  e->beAtkBy(p.get());
                  if(oneRound(f,p)) break;
               }
            }
         }
         else if (cmd == "f") { // enemies stop moving
            enemyMove = !enemyMove;
            f.changeEnemyMove();
            f.display();
            
         }
         else if (cmd == "r") { // restart
            goto Restart;
         }
         else if (cmd == "q") {
            cout << "bye" <<endl;
            exit(0);
         }
      }// end cmd while
      if(p->checkDead()) break;
      level++;
   }// end game
   
   if(level==levelNum) cout << "Congratulations! You won!" <<endl;
   cout << "Your score: " << p->showScore() << endl;
   cout << "please choose one of the following options:" << endl;
   cout << "r - restart" << endl;
   cout << "q - quit" <<endl;
   while(cin >> cmd){
      if(cmd=="r") goto Restart;
      else if (cmd == "q") {
         cout <<"bye" << endl;
         exit(0);
      }
      else {
         cout << "please choose one of the following options:" << endl;
         cout << "r - restart" << endl;
         cout << "q - quit" <<endl;
      }
   }
}

