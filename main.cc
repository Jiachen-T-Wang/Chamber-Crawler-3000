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
  
  string race;
  while (cin >> race) {
    if (race == "s") {
      shared_pointer_player = make_shared<Shade>();
      break;
    }
    else if (race == "d") {
      shared_pointer_player = make_shared<Drow>();
      break;
    }
    else if (race == "v") {
      shared_pointer_player = make_shared<Vampire>();
      break;
    }
    else if (race == "g") {
      shared_pointer_player = make_shared<Goblin>();
      break;
    }
    else if (race == "t") {
      shared_pointer_player = make_shared<Troll>();
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
      break;
    }
  }
}
