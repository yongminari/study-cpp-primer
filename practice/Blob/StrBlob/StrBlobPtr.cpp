#include "StrBlobPtr.h"
#include <cstddef>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

using std::shared_ptr;
using std::string;
using std::vector;

shared_ptr<vector<string>> StrBlobPtr::check(std::size_t i,
                                             const string &msg) const {
  auto ret = wptr.lock();
  if (!ret) {
    throw std::runtime_error("Unbound StrBlobPtr");
  }
  if (i >= ret->size()) {
    throw std::out_of_range(msg);
  }
  return ret;
}

string &StrBlobPtr::deref() const {
  auto p = check(curr, "dereference past end");
  return (*p)[curr];
}

StrBlobPtr &StrBlobPtr::incr() {
  check(curr, "increment past end of StrBlobPtr");
  ++curr;
  return *this;
}

StrBlobPtr &StrBlobPtr::operator++() {
  check(curr, "increment past end of StrBlobPtr");
  ++curr;
  return *this;
}
StrBlobPtr &StrBlobPtr::operator--() {
  --curr;
  check(curr, "decrement pas begin of StrBlobPtr");
  return *this;
}

StrBlobPtr StrBlobPtr::operator++(int) {
  StrBlobPtr ret = *this;
  ++*this;
  return ret;
}
StrBlobPtr StrBlobPtr::operator--(int) {
  StrBlobPtr ret = *this;
  --*this;
  return ret;
}
