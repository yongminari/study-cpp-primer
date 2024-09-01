#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::stable_sort;
using std::string;
using std::vector;

int sz = 3;

int main() {
  vector<string> vec = {"a",     "abcd", "bbea", "ccaaaaeedd", "abbcc", "aecz",
                        "zebra", "zet",  "zara", "yong",       "yongho"};

  stable_sort(vec.begin(), vec.end(),
              [](const string &a, const string &b) -> decltype(vec.size()) {
                if (a.size() > 3 || b.size() > 3) {
                  cout << a << " " << b << endl;
                }
                return a.size() < b.size();
              });

  for (auto &str : vec) {
    cout << str << endl;
  }

  return 0;
}
