#include <iostream>
#include <fstream>
#include <utility>
#include <string>
#include "header.h"

using namespace std;

string TextDisplay::dirtostr(Dir dir) {
  switch (dir) {
    case Dir::no:
      return "North"; break;
    case Dir::ne:
      return "Northeast"; break;
    case Dir::nw:
      return "Northwest"; break;
    case Dir::so:
      return "South"; break;
    case Dir::sw:
      return "Southwest"; break;
    case Dir::se:
      return "Southeast"; break;
    case Dir::we:
      return "West"; break;
    default:
      return "East";break;
  }
}

TextDisplay::TextDisplay(string fileName, shared_ptr<Player> p, Floor *f):
height{25}, width{79}, words{""}, p{p}, f{f} {
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
      theDisplay[i][j] = f->board[i][j].getSymbol();
      
      cout << theDisplay[i][j];
    }
    cout << endl;
  }
  cout << "Race: " << p->race << " Gold: " << p->showScore();
  cout << "         Floor " << p->showFloor() << endl;
  cout << "HP: " << p->getHP() << endl;
  cout << "Attack: " << p->realAtk() << endl;
  cout << "Defense: " << p->realDef() << endl;
  cout << "Action: " << words;
  words = "";
}

void TextDisplay::displayPlayerMove(Dir dir) {
  words += "PC moves " + dirtostr(dir) + ".";
}

void TextDisplay::displayPlayerAtk(Enemy *e, int damage) {
  words += "PC delt " + std::to_string(damage) + " damage to " + e->getType() + "!";
}

void TextDisplay::displayEnemyAtk(Enemy *e, int damage){
  words += "enemy atk";
}

void TextDisplay::displayMiss() {
  words += "PC has missed a shot!";
};
void TextDisplay::displayDead() {
  words += "PC has slain an enemy!";
};
void TextDisplay::displayGold() {
  words += "PC has slain an enemy!";
};

TextDisplay::~TextDisplay() {}
