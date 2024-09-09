#ifndef BULK_QUOTE_H
#define BULK_QUOTE_H

#include "Disc_quote.h"
#include "Quote.h"
#include <cstddef>
#include <string>

#if 0
// before abstract class
class Bulk_quote : public Quote {
public:
  Bulk_quote() = default;
  Bulk_quote(const std::string &book, double p, std::size_t qty, double disc)
      : Quote(book, p), min_qty(qty), discount(disc) {}
  double net_price(std::size_t) const override;

private:
  std::size_t min_qty = 0;
  double discount = 0.0;
};
#else
// after using abstract class
class Bulk_quote : public Disc_quote {
public:
  Bulk_quote() = default;
  Bulk_quote(const std::string &book, double price, std::size_t qty,
             double disc)
      : Disc_quote(book, price, qty, disc) {}
  double net_price(std::size_t) const override;
  Bulk_quote *clone() const & override { return new Bulk_quote(*this); }
  Bulk_quote *clone() const && override {
    return new Bulk_quote(std::move(*this));
  }

private:
  std::size_t min_qty = 0;
};
#endif

#endif // !BULK_QUOTE_H
