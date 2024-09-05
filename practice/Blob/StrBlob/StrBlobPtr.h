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
  StrBlobPtr &operator++();
  StrBlobPtr &operator--();
  StrBlobPtr operator++(int);
  StrBlobPtr operator--(int);
  std::string &operator*() const {
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
  }
  std::string *operator->() const { return &this->operator*(); }

private:
  std::shared_ptr<std::vector<std::string>> check(std::size_t,
                                                  const std::string &) const;
  std::weak_ptr<std::vector<std::string>> wptr;
  std::size_t curr;
};

#endif // !STR_BLOB_PTR_H
