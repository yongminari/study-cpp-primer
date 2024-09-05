#include "StrVec.h"
#include <initializer_list>
#include <iterator>
#include <memory>
#include <string>
#include <utility>

using std::initializer_list;
using std::make_move_iterator;
using std::pair;
using std::string;
using std::uninitialized_copy;

void StrVec::push_back(const string &s) {
  chk_n_alloc();
  alloc.construct(first_free++, s);
}

void StrVec::push_back(string &&s) {
  chk_n_alloc();
  alloc.construct(first_free++, std::move(s));
}

pair<string *, string *> StrVec::alloc_n_copy(const string *b,
                                              const string *e) {
  auto data = alloc.allocate(e - b);
  return {data, uninitialized_copy(b, e, data)};
}

void StrVec::free() {
  if (elements) {
    for (auto p = first_free; p != elements; alloc.destroy(--p))
      ;
    alloc.deallocate(elements, cap - elements);
  }
}

StrVec::StrVec(const StrVec &s) {
  auto newdata = alloc_n_copy(s.begin(), s.end());
  elements = newdata.first;
  first_free = cap = newdata.second;
}

StrVec::StrVec(StrVec &&s) noexcept
    : elements(s.elements), first_free(s.first_free), cap(s.cap) {
  s.elements = s.first_free = s.cap = nullptr;
}

StrVec::~StrVec() { free(); }

StrVec &StrVec::operator=(const StrVec &rhs) {
  auto data = alloc_n_copy(rhs.begin(), rhs.end());
  free();
  elements = data.first;
  first_free = cap = data.second;
  return *this;
}

StrVec &StrVec::operator=(StrVec &&rhs) noexcept {
  if (this != &rhs) {
    free();
    elements = rhs.elements;
    first_free = rhs.first_free;
    cap = rhs.cap;
    rhs.elements = rhs.first_free = rhs.cap = nullptr;
  }
  return *this;
}

StrVec &StrVec::operator=(initializer_list<string> il) {
  auto data = alloc_n_copy(il.begin(), il.end());
  free();
  elements = data.first;
  first_free = cap = data.second;
  return *this;
}

void StrVec::reallocate() {
#if 0
  auto newcapacity = size() ? 2 * size() : 1;
  auto newdata = alloc.allocate(newcapacity);
  auto dest = newdata;
  auto elem = elements;
  for (size_t i = 0; i < size(); i++) {
    alloc.construct(dest++, std::move(*elem++));
  }
  free();
  elements = newdata;
  first_free = dest;
  cap = elements + newcapacity;
#else
  auto newcapacity = size() ? 2 * size() : 1;
  auto first = alloc.allocate(newcapacity);

  auto last = uninitialized_copy(make_move_iterator(begin()),
                                 make_move_iterator(end()), first);
  free();
  elements = first;
  first_free = last;
  cap = elements + newcapacity;
#endif
}
