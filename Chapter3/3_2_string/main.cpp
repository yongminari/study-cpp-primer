#include <iostream>
#include <string>

using std::string;

int main() {
  string a{"Abcdef"};
  string b = "What: " + a;
  std::cout << a << std::endl;

  std::cout << a + ", " + "Hijklmn" << std::endl;
  std::cout << "what: " + a << std::endl;
  // std::cout << "what" + " the" + a << std::endl;
  return 0;
}
