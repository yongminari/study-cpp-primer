#include <iostream>
#include <ostream>
#include <string>
using std::cout;
using std::endl;

template <typename T> int compare(const T &v1, const T &v2) {
  if (v1 < v2) {
    return -1;
  } else if (v2 < v1) {
    return 1;
  }
  return 0;
}

template <typename T> T customAbs(const T &v1) { return v1 < 0 ? v1 * -1 : v1; }

int main() {
  cout << compare(10, 20) << endl;
  cout << compare(std::string("abcdef"), std::string("abcde")) << endl;
  cout << customAbs(-1.34) << endl;
  cout << customAbs(1) << endl;
  cout << customAbs(-1001424518241) << endl;
  return 0;
}
