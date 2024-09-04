#ifndef STR_BLOB_PTR_H
#define STR_BLOB_PTR_H

#include "StrBlob.h"
#include "string"
#include "vector"
#include <cstddef>
#include <memory>
#include <string>

class StrBlobPtr {

public:
  StrBlobPtr() : curr(0){};
  StrBlobPtr(StrBlob &a, std::size_t sz = 0) : wptr(a.data), curr(sz){};
  std::string &deref() const;
  StrBlobPtr &incr();

private:
  std::shared_ptr<std::vector<std::string>> check(std::size_t,
                                                  const std::string &) const;
  std::weak_ptr<std::vector<std::string>> wptr;
  std::size_t curr;
};

#endif // !STR_BLOB_PTR_H
