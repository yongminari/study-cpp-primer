#include "Sales_data.h"

double Sales_data::avg_price() const {
  if (unit_sold) {
    return revenue / unit_sold;
  } else {
    return 0;
  }
}

Sales_data &Sales_data::combine(const Sales_data &rhs) {
  unit_sold += rhs.unit_sold;
  revenue += rhs.revenue;
  return *this;
}
