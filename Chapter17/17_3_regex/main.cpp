#include <iostream>
#include <regex>
#include <string>

using std::cout;
using std::endl;
using std::regex;
using std::regex_search;
using std::smatch;
using std::sregex_iterator;
using std::string;

int main() {
  string pattern("[^c]ei");
  pattern = "[a-zA-Z]*" + pattern + "[a-zA-Z]*";
  regex r(pattern);

  smatch results;
  string test_str = "receipt freind theif receive deice dein";
  // if (regex_search(test_str, results, r))
  //   cout << results.str() << endl;
  // cout << r.mark_count() << endl;

  for (sregex_iterator it(test_str.begin(), test_str.end(), r), end_it;
       it != end_it; ++it) {
    cout << "match: " << it->str() << endl;
    cout << "prefix: " << it->prefix().str().substr() << endl;
    cout << "suffix: " << it->suffix().str().substr() << endl;
  }
  return 0;
}
