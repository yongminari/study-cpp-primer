#include "QueryResult.h"
#include "TextQuery.h"
#include <fstream>
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::string;

void runQuery(ifstream &infile) {
  TextQuery tq(infile);
  while (true) {
    cout << "Enter word to look for, or q to quit: ";
    string s;
    if (!(cin >> s) || s == "q") {
      break;
    }
    print(cout, tq.query(s)) << endl;
  }
}

// int main() {
//   runQuery(nullptr);
//   return 0;
// }
