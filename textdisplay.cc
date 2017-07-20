#include <iostream>
#include <utility>
#include "textdisplay.h"
#include "cell.h"
#include "info.h"
using namespace std;

void Textdisplay::getMove(Character* c, int dir){
  
}

void TextDisplay::display() {
  for (int i = 0; i < td.gridSize; i++) {
    for (int j = 0; j < td.gridSize; j++) {
      out << td.theDisplay[i][j];
    }
    out << endl;
  }
  return out;
}

TextDisplay::~TextDisplay() {}
