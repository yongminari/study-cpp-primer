#include <iostream>
#include <sstream>
#include <string>

using std::cout;
using std::endl;
using std::ostringstream;
using std::string;

template <typename T> string debug_rep(const T &t) {
  ostringstream ret;
  ret << t;
  return ret.str();
}

template <typename T> string debug_rep(T *p) {
  ostringstream ret;
  ret << "pointer: " << p;
  if (p) {
    ret << " " << debug_rep(*p);
  } else {
    ret << " null pointer";
  }
  return ret.str();
}

string debug_rep(const string &s) { return '"' + s + '"'; }

string debug_rep(char *p) { return debug_rep(string(p)); }

string debug_rep(const char *p) { return debug_rep(string(p)); }

int main() {
  string s("abcd");
  cout << debug_rep(s) << endl;
  cout << debug_rep(&s) << endl;

  const char *test = "abcdefg";
  cout << test << endl;
  cout << debug_rep(test) << endl;
  return 0;
}
