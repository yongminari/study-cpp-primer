#include <iostream>

typedef char *pstring;

using III = int;

int mina() {
  const pstring test = nullptr;
  char buf[100];
  // test = buf;

  const pstring test2 = buf;

  const III a = 100;
  a = 101;

  std::cout << "Hello" << std::endl;
  return 0;
}
