#include <iostream>
#include <utility>
#include "textdisplay.h"
#include "cell.h"
#include "info.h"
using namespace std;

void TextDisplay::getMove(Character* c, int dir){
  
}

void TextDisplay::display() {
  for (int i = 0; i < 25; i++) {
    for (int j = 0; j < 79; j++) {
      cout << theDisplay[i][j];
    }
    cout << endl;
  }
}

TextDisplay::~TextDisplay() {}
