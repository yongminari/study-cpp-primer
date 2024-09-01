#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

const char *cp = "Hello";

int main() {
  string s1 = cp;
  string s2 = "bellow";

  // table 9.13 first line
  {
    // first column
    s1.replace(s1.begin() + 3, s1.end(), s2);
    cout << s1 << endl;

    // second column
    s1.assign(cp);
    s1.replace(0, 2, s2);
    cout << s1 << endl;

    // third column
    s1.assign(cp);
    s1.insert(3, s2);
    cout << s1 << endl;

    // fourth column
    s1.assign(cp);
    // s1.insert(s1.begin() + 3, "abcdefg"); // error!!
    cout << s1 << endl;
  }

  // table 9.13 second line
  {
    // first column
    s1.assign(cp);
    s1.replace(0, 2, s2, 2, 20);
    cout << s1 << endl;

    // second column
    s1.assign(cp);
    // s1.replace(s1.begin(), s1.begin() + 3, s2, 3, 5); // error!!
    cout << s1 << endl;

    // third column
    s1.assign(cp);
    s1.insert(1, s2, 0, 5);
    cout << s1 << endl;

    // fourth column
    s1.assign(cp);
    // s1.insert(s1.begin(), s2, 0, 5);
    cout << s1 << endl;
  }

  // table 9.13 third line
  {
    // first column
    s1.assign(cp);
    s1.replace(0, 2, s2, 2, 20);
    cout << s1 << endl;

    // second column
    s1.assign(cp);
    // s1.replace(s1.begin(), s1.begin() + 3, s2, 3, 5); // error!!
    cout << s1 << endl;

    // third column
    s1.assign(cp);
    s1.insert(1, s2, 0, 5);
    cout << s1 << endl;

    // fourth column
    s1.assign(cp);
    // s1.insert(s1.begin(), s2, 0, 5);  // error
    cout << s1 << endl;
  }

  // ... etc....

  return 0;
}
