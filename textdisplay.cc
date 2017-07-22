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
  cout << "PC moves " << dirtostr(dir) << "." << endl;
}

void TextDisplay::displayPlayerAtk(std::shared_ptr<Enemy> e, int damage) {
  displayBoard();
  cout << "PC has made" << damage << "damage to " << e->getType() << "!" << endl;
}

void TextDisplay::displayEnemyAtk(std::shared_ptr<Enemy> e, int damage){
   cout << "enemy atk" <<endl;
}

void TextDisplay::displayMiss() {
  displayBoard();
  cout << "PC has missed a shot!" << endl;
};
void TextDisplay::displayDead() {
  displayBoard();
  cout << "PC has slain an enemy!" << endl;
};
void TextDisplay::displayGold() {
  displayBoard();
  cout << "PC has slain an enemy!" << endl;
};

TextDisplay::~TextDisplay() {}
