#ifndef PERSON_H
#define PERSON_H

#include <string>
struct Person {
  std::string getName() const { return name; }
  std::string getAddr() const { return addr; }
  std::string name;
  std::string addr;
};

#endif // PERSON_H
