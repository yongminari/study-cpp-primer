#include <cstddef>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

template <typename T> class Foo {
public:
  static std::size_t count() { return ctr++; }

private:
  static std::size_t ctr;
};

template <typename T> size_t Foo<T>::ctr = 0;

int main() {
  Foo<string> fs1, fs2;
  cout << fs1.count() << " " << fs2.count() << endl;
  Foo<int> fi1, fi2, fi3;
  cout << fi1.count() << " " << fi2.count() << " " << fi3.count() << endl;
  return 0;
}
