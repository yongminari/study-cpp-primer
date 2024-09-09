#ifndef QUERY_BASE_H
#define QUERY_BASE_H

#include "TextQuery.h"
#include <string>

class Query_base {
  friend class Query;

protected:
  using line_no = TextQuery::line_no;
  virtual ~Query_base() = default;

private:
  virtual QueryResult eval(const TextQuery &) const = 0;
  virtual std::string rep() const = 0;
};

#endif // !QUERY_BASE_H
