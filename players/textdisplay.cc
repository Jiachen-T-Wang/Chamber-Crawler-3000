#include <iostream>
#include <fstream>
#include <utility>
#include <string>
#include "textdisplay.h"

using namespace std;

TextDisplay::TextDisplay(string fileName) {
  ifstream fs {fileName};
  string line;
  height = 0;
  
  while(getline(fs, line)){
    width = line.length();
    vector <char> charLine;
    
    for(int i = 0; i < width; ++i){
      charLine.emplace_back(line[i]);
    }
    theDisplay.emplace_back(charLine);
    height++;
  }
}
void TextDisplay::getMove(Character* c, int dir){}

void TextDisplay::display() {
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      cout << theDisplay[i][j];
    }
    cout << endl;
  }
}

TextDisplay::~TextDisplay() {}
