#ifndef __TEXTDISPLAY_H__
#define __TEXTDISPLAY_H__
#include <iostream>
#include <vector>
#include "observer.h"
class Cell;

class TextDisplay: public Observer {
  std::vector<std::vector<char>> theDisplay;
  
 public:
  void getMove(Character* c, int dir) override;
  void display();

  ~TextDisplay();
};

#endif
