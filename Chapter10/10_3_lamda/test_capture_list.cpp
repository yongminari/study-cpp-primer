#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::for_each;
using std::string;
using std::vector;

void fcnVal() {
  size_t v1 = 42;
  auto f = [v1] { return v1; };
  v1 = 0;

  auto j = f();

  cout << j << endl;
}

void fcnRef() {
  size_t v1 = 42;
  auto f = [&v1] { return v1; };

  v1 = 0;

  auto j = f();
  cout << j << endl;
}

int main() {
  fcnVal();
  fcnRef();

  auto &os = cout;

  vector<int> iVec(10, 1);
  vector<string> sVec(10, "test");
  os << "-----------------------------" << endl;
  for_each(iVec.begin(), iVec.end(), [&os](const int i) { os << i << endl; });
  for_each(sVec.begin(), sVec.end(),
           [&os](const string &s) { os << s << endl; });

  int a, b, c;
  a = b = c = 0;
  auto lamdaTest1 = [a, b, c]() {
    // ++a, ++b, ++c; // error
    cout << a << b << c << endl;
  };

  auto lamdaTest2 = [a, b, c]() mutable {
    ++a, ++b, ++c;
    cout << a << b << c << endl;
  };

  return 0;
}
