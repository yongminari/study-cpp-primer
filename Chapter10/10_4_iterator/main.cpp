#include <iostream>
#include <iterator>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::istream_iterator;
using std::ostream_iterator;
using std::vector;

int main() {
  istream_iterator<int> in_iter(cin), eof;
  vector<int> vec(in_iter, eof);

  ostream_iterator<int> out_iter(cout, "\n");

  for (auto v : vec) {
    out_iter = v;
  }
  return 0;
}
