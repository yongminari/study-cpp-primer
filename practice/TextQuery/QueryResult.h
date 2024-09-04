#ifndef QUERY_RESULT_H
#define QUERY_RESULT_H

#include "TextQuery.h"
#include <memory>
#include <ostream>
#include <string>
#include <strstream>
#include <vector>

class QueryResult {
  friend std::ostream &print(std::ostream &, const QueryResult &);

public:
  QueryResult(std::string s, std::shared_ptr<std::set<TextQuery::line_no>> p,
              std::shared_ptr<std::vector<std::string>> f)
      : sought(s), lines(p), file(f){};
  QueryResult query(const std::string &sought) const;

private:
  std::string sought;
  std::shared_ptr<std::set<TextQuery::line_no>> lines;
  std::shared_ptr<std::vector<std::string>> file;
};

std::ostream &print(std::ostream &, const QueryResult &);

#endif // !QUERY_RESULT_H
