#include <iostream>

int arrType[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

auto func1(int i) -> int (*)[10] {
  if (i < 10) {
    return &arrType;
  } else {
    return nullptr;
  }
}

int main() {
  int(*test)[10] = func1(1);
  for (size_t i = 0; i < 10; ++i) {
    std::cout << (*test)[i] << std::endl;
  }
  return 0;
}
