#ifndef BLOB_H
#define BLOB_H

#include <initializer_list>
#include <memory>
#include <string>
#include <utility>
#include <vector>

template <typename> class BlobPtr;
template <typename> class Blob;
template <typename T> bool operator==(const Blob<T> &, const Blob<T> &);

template <typename T> class Blob {
  friend class BlobPtr<T>;
  friend bool operator== <T>(const Blob<T> &, const Blob<T> &);

public:
  using value_type = T;
  using size_type = typename std::vector<T>::size_type;

  // constructor
  Blob();
  Blob(std::initializer_list<T> il);

  // element number of Blob
  size_type size() const { return data->size(); }
  bool empty() const { return data->empty(); }
  void push_back(const T &t) { data->push_back(t); }
  void push_back(const T &&t) { data->push_back(std::move(t)); }
  void pop_back();

  T &back();
  T &operator[](size_type i);

private:
  std::shared_ptr<std::vector<T>> data;
  void check(size_type i, const std::string &msg) const;
};

#endif // !BLOB_H
