#ifndef NOT_QUERY_H
#define NOT_QUERY_H

#include "Query.h"
#include "QueryResult.h"
#include "Query_base.h"
#include "TextQuery.h"

class NotQuery : public Query_base {
  friend Query operator~(const Query &);
  NotQuery(const Query &q) : query(q) {}
  std::string rep() const { return "~(" + query.rep() + ")"; }
  QueryResult eval(const TextQuery &) const;
  Query query;
};

inline Query operator~(const Query &operand) {
  return std::shared_ptr<Query_base>(new NotQuery(operand));
}

#endif // !NOT_QUERY_H
