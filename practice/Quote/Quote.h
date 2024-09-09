#ifndef QUOTE_H
#define QUOTE_H

#include <cstddef>
#include <ostream>
#include <string>

class Quote {
public:
  Quote() = default;
  Quote(const std::string &book, double sales_price)
      : bookNo(book), price(sales_price){};
  std::string isbn() const { return bookNo; };
  virtual double net_price(std::size_t n) const { return n * price; };
  virtual Quote *clone() const & { return new Quote(*this); }
  virtual Quote *clone() const && { return new Quote(std::move(*this)); }
  virtual ~Quote() = default;

private:
  std::string bookNo;

protected:
  double price = 0.0;
};

double print_total(std::ostream &, const Quote &, size_t);

#endif // !QUOTE_H
