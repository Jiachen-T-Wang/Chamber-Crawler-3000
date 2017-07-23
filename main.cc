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

shared_ptr<Object> fetchNeighbourObject(shared_ptr<Object> p, string dir){
   return p->getPos()-> getNeighbour(stringToDir(dir))->getContent();
}

bool Merchant::angry{false};

int main(int argc, const char * argv[]) {
   bool arg = false;
   string fileName;
   if (argc > 1) {
      fileName = argv[1];
      arg = true;
   }
//    Merchant::angry = false;

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
         p = make_shared<Shade>(nullptr);
         break;
      }
      else if (race == "d") {
          p = make_shared<Drow>(nullptr);

         break;
      }
      else if (race == "v") {
         p = make_shared<Vampire>(nullptr);
         break;
      }
      else if (race == "g") {
         p = make_shared<Goblin>(nullptr);
         break;
      }
      else if (race == "t") {
        p = make_shared<Troll>(nullptr);
         break;
      }
      else if (race == "q") {
         exit(0);
      }
   }

   for(int i=0; i<5; i++){
      
      //    if(arg) Floor f {i, p, fileName};
      //    else
      Floor f {i, p};
      f.display();
      string cmd;
      string direction;
//       Merchant::angry = false;
      
      while (cin >> cmd) {
         if (cmd == "no"|| cmd == "so" ||cmd == "ea" ||cmd == "we"
             ||cmd == "ne" ||cmd == "nw" ||cmd == "se" ||cmd == "sw"){
            p->moveTo(stringToDir(cmd));
         f.gothroughBoard(p);
         }
         else if (cmd == "u") {
            if(cin >> direction) {
               shared_ptr<Object> o =fetchNeighbourObject(p, direction);
               if (o.get() && o->isPotion()){
                  shared_ptr<Potion> drug;
                  drug.reset((Potion*)o.get());
                  p->usePotion(drug);
                  f.gothroughBoard(p);
               }
               // else 不是potion
            }
         }
         else if (cmd == "a") { // attack enemy
            
            if(cin >> direction) {
               shared_ptr<Object> o = fetchNeighbourObject(p, direction);
               if (o.get() && o->isEnemy()){
                  shared_ptr<Enemy> e;
                  e.reset((Enemy*)o.get());
                  e->beAtkBy(p);
                  f.gothroughBoard(p);
               }
            }
         }
         else if (cmd == "f") { // enemies stop moving
            
         }
         else if (cmd == "r") { // restart
            
         }
         else if (cmd == "q") {
            exit(0);
         }
      }
   }
   
}
