#include <iostream>

int test[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

decltype(test) *func(int i) {
  if (i > 0) {
    return &test;
  }
  return nullptr;
}

int main() {
  decltype(test) *tmp = func(1);
  for (auto i : *tmp) {
    std::cout << i << std::endl;
  }
  return 0;
}
