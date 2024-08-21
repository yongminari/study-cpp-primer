#include <iostream>
#include <iterator>
#include <ostream>

int main() {
  int arr[100] = {};

  for (auto beg = std::begin(arr); beg != std::end(arr); ++beg) {
    std::cout << *beg << std::endl;
  }

  for (auto &v : arr) {
    std::cout << v << " ";
  }

  return 0;
}
