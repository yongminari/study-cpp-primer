#include <cstddef>
#include <iostream>

using std::cout;
using std::endl;

class Base {
public:
  std::size_t size() const { return n; }
  void print() { cout << "I called print(): " << a << endl; }

protected:
  std::size_t n;
  int a = 100;
};

class Derive : private Base {
public:
  using Base::size;

protected:
  using Base::n;
};

int main() {
  Derive d;
  d.size();
  // d.print();
  return 0;
}
