#ifndef __TEXTDISPLAY_H__
#define __TEXTDISPLAY_H__
#include <iostream>
#include <vector>
#include "observer.h"
class Cell;

class TextDisplay: public Observer {
  int height;
  int width;
  std::vector<std::vector<char>> theDisplay;
  
 public:
  TextDisplay(std::string fileName);
   void display();

  ~TextDisplay();
};

#endif
