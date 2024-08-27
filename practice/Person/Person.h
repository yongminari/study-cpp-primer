#ifndef PERSON_H
#define PERSON_H

#include <ostream>
#include <string>
struct Person {
  std::string getName() const { return name; }
  std::string getAddr() const { return addr; }
  std::string name;
  std::string addr;
};

std::ostream &print(std::ostream &, const Person &);

#endif // PERSON_H
