#include <initializer_list>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::initializer_list;
using std::string;

void error_msg(initializer_list<string> &&li) {
  for (auto l = li.begin(); l != li.end(); ++l) {
    cout << *l << endl;
  }
}

void error_msg2(initializer_list<string> &&li) {
  for (auto &l : li) {
    cout << l << endl;
  }
}

int main() {
  error_msg({"abcd", "efg", "hijk", "lmnop"});
  error_msg2({"abcd", "efg", "hijk", "lmnop", "qrstu", "vwxyz"});
  return 0;
}
