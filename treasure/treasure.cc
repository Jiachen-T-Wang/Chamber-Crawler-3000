#include "treasure.h"
using namespace std;

Treasure::Treasure(std::string type, int value)
	: type{type}, value{value} {}

string Treasure::getType() { return type; }

int Treasure::getValue() { return value; }

Treasure::~Treasure() {}