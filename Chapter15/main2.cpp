#include <iostream>

using std::cout;
using std::endl;

struct A {
  virtual void a(int arg1 = 100) { cout << "based: " << arg1 << endl; }
};

struct B : A {
  void a(int arg1) { cout << "derived: " << arg1 << endl; }
};

int main() {
  A a;
  B b;
  A *test;

  a.a();
  // b.a();
  b.a(1);
  test = &a;
  test->a();
  test = &b;
  test->a();

  return 0;
}
