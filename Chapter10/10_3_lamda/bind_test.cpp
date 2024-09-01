#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

using std::bind;
using std::cout;
using std::endl;
using std::for_each;
using std::string;
using std::vector;
using namespace std::placeholders;

void print_over_val(int a, int &num) {
  if (a > num) {
    cout << a << endl;
    num += 3;
    cout << "increment" << num << endl;
  }
}

void print_string_w_num(int num, const string &str) {
  cout << str << ": " << num << endl;
}

void bind_test(int a, int b) {
  cout << "------" << endl;
  cout << a << endl;
  cout << "------" << endl;
  cout << b << endl;
  cout << "------" << endl;
  // cout << c << endl;
  // cout << "------" << endl;
}

void bind_test2(int a, int b, int c) {
  cout << "------" << endl;
  cout << a << endl;
  cout << "------" << endl;
  cout << b << endl;
  cout << "------" << endl;
  cout << c << endl;
  cout << "------" << endl;
}

int main() {
  int a = 1;
  int b = 2;
  int c = 3;

  auto newCall = bind(print_over_val, _1, a);

  vector<int> vec;
  for (decltype(vec.size()) i = 0; i != 10; i++) {
    vec.push_back(i);
  }

  for_each(vec.begin(), vec.end(), newCall);
  cout << "Am I changed?" << ": " << a << endl;

  auto newRefCall = bind(print_over_val, _1, std::ref(a));
  for_each(vec.begin(), vec.end(), newRefCall);
  cout << "Am I changed?" << ": " << a << endl;

  // auto f = bind(bind_test, _1, a);
  // auto g = bind(bind_test2, a, _2, _1);
  // g(b, c);

  vector<string> strVec{"abcd", "efgh", "ijkl", "mnop", "qrst", "uvwx", "yz"};

  auto str = bind(print_string_w_num, c, _1);
  for (auto &var : strVec) {
    str(var);
  }
  for_each(strVec.begin(), strVec.end(), bind(print_string_w_num, a, _1));

  return 0;
}
