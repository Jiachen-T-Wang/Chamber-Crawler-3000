#include <iostream>
#include <memory>
#include "floor.h"
#include "players/drow.h"
#include "players/goblin.h"
#include "players/shade.h"
#include "players/troll.h"
#include "players/vampire.h"
#include "textdisplay.h"
#include "object.h"
using namespace std;

Dir stringToDir(string d){
   if (d == "no") return Dir::no;
   else if (d =="so") return Dir::so;
   else if (d =="ea") return Dir::ea;
   else if (d =="se") return Dir::se;
   else if (d =="we") return Dir::we;
   else if (d =="ne") return Dir::ne;
   else if (d =="nw") return Dir::nw;
   else if (d =="sw") return Dir::sw;
}
int main(int argc, const char * argv[]) {
   bool arg = false;
   string fileName;
   if (argc > 1) {
      fileName = argv[1];
      arg = true;
   }
   
   
   shared_ptr<Player> p;
   string race;
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
         exit(0);
      }
   }

   
   for(int i=0; i<5; i++){
      
      if(arg) Floor f {i, p, fileName};
      else Floor f {i, p};
      
      string cmd;
      string direction;
      
      while (cin >> cmd) {
         if (cmd == "no"|| cmd == "so" ||cmd == "ea" ||cmd == "we"
             ||cmd == "ne" ||cmd == "nw" ||cmd == "se" ||cmd == "sw")
            f.move(stringToDir(cmd));
         
         else if (cmd == "u") {
            if(cin >> direction) {
                = p->getPos()->getNeighbour(stringToDir(direction))->getContent();
               
            }
         }
         else if (cmd == "a") { // attack enemy
            
            if(cin >> direction)
               p->attackEnemy(stringToDir(direction));
            
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
