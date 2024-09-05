#ifndef STR_VEC_H
#define STR_VEC_H

#include <cstddef>
#include <initializer_list>
#include <memory>
#include <string>
#include <utility>
class StrVec {
public:
  StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
  StrVec(const StrVec &);
  StrVec(StrVec &&s) noexcept;
  StrVec &operator=(const StrVec &);
  StrVec &operator=(StrVec &&) noexcept;
  StrVec &operator=(std::initializer_list<std::string>);
  ~StrVec();
  void push_back(const std::string &);
  void push_back(std::string &&);
  size_t size() const { return first_free - elements; }
  size_t capacity() const { return cap - elements; }
  std::string *begin() const { return elements; }
  std::string *end() const { return first_free; }
  std::string &operator[](std::size_t n) { return elements[n]; }
  const std::string &operator[](std::size_t n) const { return elements[n]; }

private:
  static std::allocator<std::string> alloc;
  void chk_n_alloc() {
    if (size() == capacity())
      reallocate();
  }
  std::pair<std::string *, std::string *> alloc_n_copy(const std::string *,
                                                       const std::string *);
  void free();
  void reallocate();
  std::string *elements;
  std::string *first_free;
  std::string *cap;
};

#endif // !STR_VEC_H
