#include <array>
#include <deque>
#include <iostream>
#include <list>
#include <string>
#include <vector>

using std::array;
using std::cout;
using std::deque;
using std::endl;
using std::list;
using std::string;
using std::vector;

int main() {
  //
  list<string> authors = {"Milton", "Shakespeare", "Austen"};
  vector<const char *> articles = {"a", "an", "the"};

  list<string> list2(authors);
  // deque<string> authList<authors>; // error
  auto list3(authors);
  decltype(list3) list4(list3);
  deque<string> authDeque(list4.begin(), list4.end());

  for (auto &var : authDeque) {
    cout << var << endl;
  }

  list<string> cToStr(articles.begin(), articles.end());

  array<int, 10> a;

  auto b = a.size();
  array<int, 10>::size_type c = a.size();

  int i = 0;
  for (auto &var : a) {
    var = ++i;
  }

  for (auto var : a) {
    cout << var << endl;
  }

  list2.assign({"abcd", "efg"});
  for (const auto &var : list2) {
    cout << var << endl;
  }
  list2 = {"hijk", "lmnop"};
  for (const auto &var : list2) {
    cout << var << endl;
  }

  return 0;
}
