#include <functional>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

template <typename T, typename F = std::less<T>>
int compare(const T &v1, const T &v2, F f = F()) {
  if (f(v1, v2))
    return -1;
  if (f(v2, v1))
    return 1;

  return 0;
}

template <typename T = int> class Numbers {
public:
  Numbers(T v = 0) : val(v) {}
  T val;
};

int main() {
  cout << compare(1, 100) << endl;
  cout << compare(string("abcd"), string("abce"), std::greater()) << endl;

  Numbers a(10);
  cout << a.val << endl;
  Numbers<float> b(10.5);
  cout << b.val << endl;

  return 0;
}
