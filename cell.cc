#include "cell.h"
Cell::Cell(int x, int y): x{x}, y{y}, type{nullptr}{}
void Cell::changeType(Object *type){
   this->type = type;
