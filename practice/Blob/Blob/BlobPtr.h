#ifndef BLOB_PTR_H
#define BLOB_PTR_H

#include "Blob.h"

#include <cstddef>
#include <memory>
#include <string>
#include <vector>

template <typename T> class BlobPtr {
public:
  BlobPtr() : curr(0) {}
  BlobPtr(Blob<T> &a, size_t sz = 0) : wptr(a.data), curr(0) {}
  T &operator*() const {
    auto p = check(curr, "deference past end");
    return (*p)[curr];
  }
  BlobPtr &operator++();
  BlobPtr &operator--();
  BlobPtr operator++(int);

private:
  std::shared_ptr<std::vector<T>> check(std::size_t, const std::string &) const;
  std::weak_ptr<std::vector<T>> wptr;
  std::size_t curr;
};

#endif // !BLOB_PTR_H
