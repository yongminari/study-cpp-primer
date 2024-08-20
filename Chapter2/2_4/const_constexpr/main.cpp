#include <iostream>

int main() {
  const int *pi = nullptr;

  int i = 100;

  constexpr int *pi2 = &i;

  // pi2 = &i; // error code

  std::cout << i << std::endl;

  // *pi2 = 101;

  return 0;
}
