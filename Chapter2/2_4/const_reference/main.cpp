#include <iostream>

int main(void) {
  double dval = 3.1415;
  const int &ri = dval;
  const double &rd = dval;

  // int &ri2 = dval; // this code is error

  std::cout << ri << std::endl;

  std::cout << "addr of dval: " << &dval << std::endl;
  std::cout << "addr of ri: " << &ri << std::endl;
  std::cout << "addr of rd: " << &rd << std::endl;
  return 0;
}
