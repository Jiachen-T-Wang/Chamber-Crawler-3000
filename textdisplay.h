#ifndef __TEXTDISPLAY_H__
#define __TEXTDISPLAY_H__
#include <iostream>
#include <vector>
#include "observer.h"
#include "enemy.h"
#include <memory>
class Cell;
class Player;

class TextDisplay: public Observer {
  int height;
  int width;
  std::string words;
  std::vector<std::vector<char>> theDisplay;
  std::shared_ptr<Player> p;
  Floor *f;
  
 protected:
  std::string dirtostr(Dir dir);
  
 public:
  TextDisplay(std::string fileName, std::shared_ptr<Player> p, Floor *f);
  void displayBoard();
  void displayPlayerMove(Dir dir) override;
  void displayPlayerAtk(Enemy *e, int damage) override;
 void displayEnemyAtk(Enemy *e, int damage) override;
  void displayMiss() override;
  void displayDead() override;
  void displayGold() override;    //这个用在Human死的时候四周散落gold
//use potion
  ~TextDisplay();
};

#endif
