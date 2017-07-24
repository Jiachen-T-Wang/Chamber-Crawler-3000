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

int main(int argc, const char * argv[]) {
   int levelNum = 5;
   bool arg = false;
   string fileName;
   if (argc > 1) {
      fileName = argv[1];
      arg = true;
   }
   //    Merchant::angry = false;
Restart:
   shared_ptr<Player> p;
   string race;
   cout << "Please choose a race." <<endl;
   cout << "s - shade" << endl;
   cout << "d - Drow" << endl;
   cout << "v - Vampire" << endl;
   cout << "g - Goblin" << endl;
   cout << "t - Troll" << endl;
   cout << "q - quit" << endl;
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
   while(level<levelNum){
      p->notGoToNext();
      //    if(arg) Floor f {i, p, fileName};
      //    else
      Floor f {level, p};
      
      string direction;
      //       Merchant::angry = false;
      
      while (cin >> cmd) {
         if (cmd == "no"|| cmd == "so" ||cmd == "ea" ||cmd == "we"
             ||cmd == "ne" ||cmd == "nw" ||cmd == "se" ||cmd == "sw"){
            p.get()->moveTo(stringToDir(cmd));//p
            f.gothroughBoard(p);
            f.display();
         }
         else if (cmd == "u") {
            if(cin >> direction) {
               shared_ptr<Object> o =fetchNeighbourObject(p, direction);
               if (o.get() && o->isPotion()){
                  Potion *drug=(Potion*)o.get();
                  p.get()->usePotion(drug);//p
                  o->getPos()->setCont(nullptr);
                  f.gothroughBoard(p);
                  f.display();
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
                  f.gothroughBoard(p);
                  f.display();
                  
               }
            }
         }
         else if (cmd == "f") { // enemies stop moving
            
         }
         else if (cmd == "r") { // restart
            goto Restart;
         }
         else if (cmd == "q") {
            cout << "bye" <<endl;
            exit(0);
         }
         if(p->getGoToNext()) break;
         if(p->checkDead()) {
            p->getPos()->notifyPlayerDead();
            break;
         }
      }// end cmd while
      if(p->checkDead()) break;
      level++;
   }// end game
   
   if(level==levelNum) cout << "Congratulations!" <<endl;
   
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

