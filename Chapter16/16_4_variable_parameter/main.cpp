#include <iostream>

using std::cout;
using std::endl;

template <typename... Args> void g(Args... args) {
  cout << sizeof...(Args) << endl;
  cout << sizeof...(args) << endl;
}

int main() {
  g(1, 2, 3, 4, 5);
  g(1, 2, 3);
  return 0;
}
