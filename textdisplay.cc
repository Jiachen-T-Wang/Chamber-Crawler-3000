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
  string firstLine = "Race: " + p->race + " Gold: " + std::to_string(p->getGold());
  int len = firstLine.length();
  for (int i = 0; i < 72 - len; i++) firstLine += " ";
  cout << firstLine << "Floor " << p->showFloor() << endl;
  cout << "HP: " << p->getHP() << endl;
  cout << "Attack: " << p->realAtk() << endl;
  cout << "Defense: " << p->realDef() << endl;
  cout << "Action: " << words << endl;
  words = "";
}

void TextDisplay::displayPlayerMove(Dir dir) {
  words += "PC moves " + dirtostr(dir) + ". ";
}

void TextDisplay::displayPlayerAtk(Enemy *e, int damage) {
  words += "PC delt " + std::to_string(damage) + " damage to " + e->getType() + "! ";
}

void TextDisplay::displayEnemyAtk(Enemy *e, int damage){
  words += e->getType() + " delt " + std::to_string(damage) + " damage to PC! ";
}

void TextDisplay::displayMiss() {
  words += "MISS! ";
};
void TextDisplay::displayDead() {
  words += "PC has slain an enemy! ";
};
void TextDisplay::displayGold() {
  words += "Human drops extra gold! ";
};

void TextDisplay::displayCannotMove() {
  words += "PC cannot move in this way! ";
}

void TextDisplay::displayUsePotion(Potion *p) {
  words += "PC has used a potion ";
  int Effect = p->getEffect();
  if (Effect > 0) {
    words += "and gains ";
  } else {
    Effect *= -1;
    words += "and loses ";
  }
  words += std::to_string(Effect);
  if (p->getType() == "Atk") words += " Attack! ";
  else if (p->getType() == "Def") words += " Defense! ";
  else words += " HP! ";
}

void TextDisplay::displayPlayerDead() {
  words += "You Are DEAD! ";
}

TextDisplay::~TextDisplay() {}
