
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

constexpr int i = 42;
int j = 0;

int main() {
  const int *p = nullptr;
  constexpr const int *p2 = &i;
  constexpr int *p1 = &j;

  *p1 = 100;

  cout << *p1 << endl;
  cout << *p2 << endl;

  vector<int> vec;

  for (auto e : vec) {
    cout << e << endl;
  }

  return 0;
}
