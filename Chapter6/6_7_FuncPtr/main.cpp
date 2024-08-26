#include <iostream>
#include <string>

bool testFunc(std::string &a, std::string &b) {
  std::cout << a.size() << std::endl;
  std::cout << b.size() << std::endl;
  return false;
}

typedef bool (*funcPtr1)(std::string &, std::string &);
typedef decltype(testFunc) *funcPtr2;

using PF = bool (*)(std::string &, std::string &);

PF retFuncPtr1() { return &testFunc; }
bool (*retFuncPtr2())(std::string &, std::string &) { return &testFunc; }
funcPtr2 retFuncPtr3() { return testFunc; }
auto retFuncPtr4() -> bool (*)(std::string &, std::string &) {
  return testFunc;
}

int main() {
  funcPtr1 called1 = testFunc;
  funcPtr2 called2 = testFunc;

  std::string sampl1, sampl2;
  called1(sampl1, sampl2);
  called2(sampl1, sampl2);
  return 0;
}
