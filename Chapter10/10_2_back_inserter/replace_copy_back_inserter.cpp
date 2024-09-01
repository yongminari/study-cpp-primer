#include <algorithm>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <vector>

using std::back_inserter;
using std::cout;
using std::endl;
using std::rand;
using std::replace_copy;
using std::vector;

int main() {
  vector<int> vecOrg, vecCpy;

  for (size_t i = 0; i < 10; i++) {
    back_inserter(vecOrg) = 30;
  }

  replace_copy(vecOrg.begin(), vecOrg.end(), back_inserter(vecCpy), 30, 10);

  for (auto var : vecOrg) {
    cout << var << " ";
  }
  cout << endl;

  for (auto var : vecCpy) {
    cout << var << " ";
  }
  cout << endl;

  return 0;
}
