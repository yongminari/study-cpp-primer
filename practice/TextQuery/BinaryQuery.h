#ifndef BINARY_QUERY_H
#define BINARY_QUERY_H

#include "Query.h"
#include "Query_base.h"
#include <string>
class BinaryQuery : public Query_base {
protected:
  BinaryQuery(const Query &l, const Query &r, std::string s)
      : lhs(l), rhs(r), opSym(s) {}
  std::string rep() const {
    return "" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")";
  }
  Query lhs, rhs;
  std::string opSym;
};

#endif // !BINARY_QUERY_H
