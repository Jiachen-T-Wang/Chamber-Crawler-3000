#include <iostream>
#include <memory>
#include "floor.h"
#include "players/drow.h"
#include "players/goblin.h"
#include "players/shade.h"
#include "players/troll.h"
#include "players/vampire.h"


#include "textdisplay.h"
using namespace std;

int main(int argc, const char * argv[]) {
  if (argc == 1) {
    // read map
  } else {
    Floor f(1, "cc3kfloor.txt");
    f.display();
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
  };
  
  string cmd;
  string direction;
  
  while (cin >> cmd) {
    if (cmd == "no,so,ea,we,ne,nw,se,sw") { // move

    }
    else if (cmd == "u") { // use potion
      cin >> direction;
      
    }
    else if (cmd == "a") { // attack enemy
      cin >> direction;
      
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
