#include <iostream>
#include <list>
#include <string>
#include <utility>
#include <vector>

using std::cout;
using std::endl;
using std::list;
using std::string;
using std::vector;

int main() {
  list<string> slist1(100);
  cout << slist1.size() << endl;

  slist1.assign(10, "What the!!");
  cout << slist1.size() << endl;

  vector<int> swapTestOrg = {1, 2, 3, 4, 5};
  vector<int> swapTestCpy = {6, 7, 8, 9, 10};

  auto orgBeg = swapTestOrg.begin();
  auto cpyBeg = swapTestCpy.begin();

  cout << "orgBeg + 1: " << *(orgBeg + 1) << endl;
  cout << "cpyBeg + 1: " << *(cpyBeg + 1) << endl;

  std::swap(swapTestOrg, swapTestCpy);

  cout << "orgBeg + 1: " << *(orgBeg + 1) << endl;
  cout << "cpyBeg + 1: " << *(cpyBeg + 1) << endl;
  return 0;
}
