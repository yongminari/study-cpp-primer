#include <iostream>

struct test {
  int a = 10;
  int funcA() { return a; }
};

test getObj(test t) { return t; }
test *getObj(test *t) { return t; }
// test &getObj(test &t) { return t; }

int main() {
  test oAA;
  test *pAA = &oAA;
  test &rAA = oAA;

  std::cout << getObj(oAA).funcA() << std::endl;
  std::cout << getObj(pAA)->funcA() << std::endl;
  // std::cout << getObj(rAA)->funcA() << std::endl;

  return 0;
}
