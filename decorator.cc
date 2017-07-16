#include "decorator.h"

Decorator::Decorator(Player *component): component{component} {}

Decorator::~Decorator() { delete component; }
