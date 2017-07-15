#include "subject.h"
#include "observer.h"
#include "subscriptions.h"

void Subject::attach(Observer *o) { observers.push_back(o); }

void Subject::notifyObservers(SubscriptionType t) {
  for (int i = 0; i < observers.size(); i++) {
    if (observers[i]->subType() == t) { // if matches
      observers[i]->notify(*this);
    }
  }
}
