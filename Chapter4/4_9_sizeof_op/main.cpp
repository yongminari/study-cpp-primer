#include <iostream>
#include <string>
#include <vector>

struct test {
  int a;
  int b;
  int c;
  int d;
  int e;
};

int main() {
  std::string str;
  std::string str2("abcdefghijklmnopqrstuvwxyz");
  std::vector<int> vecInt;
  std::vector<int> vecInt2{1, 2, 3, 4, 5, 6};
  std::vector<test> vecTest;
  std::vector<test> vecTest2{{1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}};

  std::cout << sizeof str << std::endl;
  std::cout << sizeof vecInt << std::endl;
  std::cout << sizeof str2 << std::endl;
  std::cout << sizeof vecInt2 << std::endl;
  std::cout << sizeof vecTest << std::endl;
  std::cout << sizeof vecTest2 << std::endl;

  return 0;
}
