#include "cell.h"

Cell::Cell(int x, int y, char c): x{x}, y{y}, content{nullptr}{
  if (c == '.') type = "tile";
    else if (c == '|' || c == '-') type = "wall";
      else if (c == '+') type = "doorway";
        else if (c == '#') type = "passage";
          else if (c == '\\') type = "stairway";
            else if (c == ' ') type = "empty";
                   
}
