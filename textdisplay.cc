#include <iostream>
#include <fstream>
#include <utility>
#include <string>
#include "textdisplay.h"
#include "player.h"

using namespace std;

TextDisplay::TextDisplay(string fileName, shared_ptr<Player> p): height{25}, width{79}, p{p} {
  ifstream fs {fileName};
  string line;
  
  while(getline(fs, line)){
    vector <char> charLine;
    
    for(int i = 0; i < width; ++i){
      charLine.emplace_back(line[i]);
    }
    theDisplay.emplace_back(charLine);
  }
}

void TextDisplay::displayBoard() {
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      cout << theDisplay[i][j];
    }
    cout << endl;
  }
  cout << "Race: " << p->race << " Gold: " << p->showScore();
  cout << "         Floor" << p->showFloor() << endl;
  cout << "HP: " << p->getHP() << endl;
  cout << "Attack: " << p->realAtk() << endl;
  cout << "Defense: " << p->realDef() << endl;
  cout << "Action: ";
}

void TextDisplay::displayPlayerMove(Dir dir) {
  displayBoard();
  cout << "PC moves " << dir << "." << endl;
}

void TextDisplay::displayPlayerAtk(int damage) {
  displayBoard();
}

void TextDisplay::displayMiss() {};
void TextDisplay::displayDead() {};
void TextDisplay::displayGold() {};

TextDisplay::~TextDisplay() {}
