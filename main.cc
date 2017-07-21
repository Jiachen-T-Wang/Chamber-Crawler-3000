#include <iostream>
#include "floor.h"
#include "textdisplay.h"
using namespace std;

int main(int ) {
  string race;
  cin >> race;
  
  string cmd;
  string direction;
   for(int i=0; i<5; i++){
  Floor f(1, "cc3kfloor.txt");
  f.display();
  
  while (true) {
    cin >> cmd;
    if (cmd == "no,so,ea,we,ne,nw,se,sw") { // move

    }
    else if (cmd == "u") { // use potion
      cin >> direction;
      
    }
    else if (cmd == "a") { // attack enemy
      cin >> direction;
      
    }
    else if (cmd == "s, d, v, g, t") { // specify race
      
      
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
