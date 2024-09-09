#include "AndQuery.h"
#include "QueryResult.h"
#include "TextQuery.h"
#include <algorithm>
#include <iterator>
#include <memory>
#include <set>

using std::inserter;
using std::make_shared;
using std::set;
using std::set_intersection;

QueryResult AndQuery::eval(const TextQuery &text) const {
  auto left = lhs.eval(text), right = rhs.eval(text);
  auto ret_lines = make_shared<set<line_no>>();
  set_intersection(left.begin(), left.end(), right.begin(), right.end(),
                   inserter(*ret_lines, ret_lines->begin()));
  return QueryResult(rep(), ret_lines, left.get_file());
}
