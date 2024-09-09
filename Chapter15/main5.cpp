#include <iostream>

using std::cout;
using std::endl;

class Base {
public:
  virtual int a(int) { return aa; }

private:
  int aa = 10;
};

class D1 : Base {
public:
  using Base::a;
  int a(int ret1, int ret2) { return ret1 + ret2; }
  int a() { return 0; }
};

int main() {
  D1 d;
  cout << d.a() << endl;
  cout << d.a(3, 5) << endl;
  cout << d.a(3) << endl;
  return 0;
}
