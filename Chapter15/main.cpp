#include <cstdlib>
#include <iostream>

using std::cout;
using std::endl;

class Bulk {
public:
  virtual void a() { cout << "I'm Base" << endl; }
};

class Derive : public Bulk {
public:
  void a() { cout << "I'm Drived class" << endl; }
};

struct B {
  virtual void f1(int) const;
  virtual void f2();
  void f3();
};

struct D2 : B {
  void f1(int) const final;
};

struct D3 : D2 {
  void f2() override;
  // void f1(int) const override; // error 재정의 불가
};

int main() {
  int a = rand() + 1;
  Bulk item1;
  Derive item2;

  Bulk *item;

  cout << a << endl;
  if (a & 1) {
    item = &item1;
  } else {
    item = &item2;
  }

  item->a();

  return 0;
}
