#include "Person.h"
#include <ostream>

using std::ostream;

ostream &print(ostream &os, const Person &item) {
  os << item.getName() << " " << item.getAddr();
  return os;
}
