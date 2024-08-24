#include <iostream>

void f(int (&arr)[5]) {
  for (auto &a : arr) {
    a = 1;
  }
}

void f(int (*arr)[5]) {
  // some code
}

void f(int (*arr)[10]) {
  // some code
}

int main() {
  int test[5] = {};
  int test2[6] = {};
  int test3[10][5] = {};

  f(test);
  f(test3);
  // f(test2); // error
  for (auto t : test) {
    std::cout << t << std::endl;
  }

  return 0;
}
