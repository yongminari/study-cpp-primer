#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>

struct Sales_data {
  std::string bookNo;
  unsigned unit_sold = 0;
  double revenue = 0.0;
};

#endif // SALES_DATA_H
