#include <iostream>

int fact(int val) {
  if (val != 1) {
    return fact(val-1) * val;
  }
  return 1;
}

int main() {
  std::cout << fact(5) << std::endl;
  return 0;
}
