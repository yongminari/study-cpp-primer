#ifndef AND_QUERY_H
#define AND_QUERY_H

#include "BinaryQuery.h"
#include "Query.h"
#include "QueryResult.h"
#include "Query_base.h"
#include "TextQuery.h"
class AndQuery : public BinaryQuery {
  friend Query operator&(const Query &, const Query &);
  AndQuery(const Query &left, const Query &right)
      : BinaryQuery(left, right, "&") {}
  QueryResult eval(const TextQuery &) const;
};

inline Query operator&(const Query &lhs, const Query &rhs) {
  return std::shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}

#endif // !AND_QUERY_H
