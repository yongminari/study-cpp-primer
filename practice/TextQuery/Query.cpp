#include "Query.h"
#include "WordQuery.h"
#include <ostream>

using std::ostream;

ostream &operator<<(std::ostream &os, const Query &query) {
  return os << query.rep();
}

inline Query::Query(const std::string &s) : q(new WordQuery(s)) {}
