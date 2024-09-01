#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using std::back_inserter;
using std::cout;
using std::endl;
using std::fill_n;
using std::vector;

int main() {
  vector<int> vec(10);
  fill_n(back_inserter(vec), 30, 99);

  cout << vec.size() << endl;
  for (auto var : vec) {
    cout << var << " ";
  }
  cout << endl;
  return 0;
}
