#include <cstdlib>
#include <iostream>
#include "subject.h"
#include "observer.h"
using namespace std;

void Subject::attach(Observer *o) { observers.emplace_back(o); }











