#include <iostream>
#include <fstream>
#include <utility>
#include <string>
#include "textdisplay.h"

using namespace std;

TextDisplay::TextDisplay(string fileName) {
  ifstream fs {fileName};
  string line;
  while(getline(fs, line)){
    width = line.length();
    vector <char> charline;
    
    for(int i = 0; i < width; ++i){
      charline.emplace_back(line[i]);
    }
    theDisplay.emplace_back(charline);
    height++;
  }
}
void TextDisplay::getMove(Character* c, int dir){}

void TextDisplay::display() {
  for (int i = 0; i < 25; i++) {
    for (int j = 0; j < 79; j++) {
      cout << theDisplay[i][j];
    }
    cout << endl;
  }
}

TextDisplay::~TextDisplay() {}
