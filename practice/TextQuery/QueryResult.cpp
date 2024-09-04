#include "QueryResult.h"
#include "TextQuery.h"
#include <cstddef>
#include <memory>
#include <ostream>
#include <set>
#include <string>

using std::endl;
using std::ostream;
using std::set;
using std::shared_ptr;
using std::string;

QueryResult TextQuery::query(const string &sought) const {
  static shared_ptr<set<line_no>> nodata(new set<line_no>);

  auto loc = wm.find(sought);
  if (loc == wm.end()) {
    return QueryResult(sought, nodata, file);
  } else {
    return QueryResult(sought, loc->second, file);
  }
}

string make_plural(std::size_t num, const string a, const string b) {
  if (num > 1) {
    return a + b;
  }
  return a;
}

ostream &print(std::ostream &os, const QueryResult &qr) {
  os << qr.sought << "occurs" << qr.lines->size() << ""
     << make_plural(qr.lines->size(), "time", "s") << endl;

  for (auto num : *qr.lines) {
    os << "\t(line " << num + 1 << ")" << *(qr.file->begin() + num) << endl;
  }
  return os;
}
