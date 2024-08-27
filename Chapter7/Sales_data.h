#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <istream>
#include <ostream>
#include <string>

struct Sales_data {
  std::string isbn() const { return bookNo; }
  Sales_data &combine(const Sales_data &);
  double avg_price() const;

  std::string bookNo;
  unsigned unit_sold = 0;
  double revenue = 0.0;
};

Sales_data add(const Sales_data &, const Sales_data &);
std::istream &read(std::istream &, Sales_data &);
std::ostream &print(std::ostream &, Sales_data &);

#endif // SALES_DATA_H
