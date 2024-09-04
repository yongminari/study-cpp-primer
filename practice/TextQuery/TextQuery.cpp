#include "TextQuery.h"
#include <cstdio>
#include <fstream>
#include <memory>
#include <set>
#include <sstream>
#include <string>

using std::ifstream;
using std::istringstream;
using std::set;
using std::string;

TextQuery::TextQuery(ifstream &is) {
  string text;
  while (getline(is, text)) {
    file->push_back(text);
    int n = file->size() - 1;
    istringstream line(text);
    string word;
    while (line >> word) {
      auto &lines = wm[word];
      if (!lines) {
        lines.reset(new set<line_no>);
      }
      lines->insert(n);
    }
  }
}
