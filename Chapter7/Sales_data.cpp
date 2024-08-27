#include "Sales_data.h"

double Sales_data::avg_price() const {
  if (unit_sold) {
    return revenue / unit_sold;
  } else {
    return 0;
  }
}
