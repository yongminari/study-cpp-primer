#include "Bulk_quote.h"
#include <cstddef>

double Bulk_quote::net_price(size_t cnt) const {
  if (cnt >= min_qty) {
    return cnt * (1 - discount) * price;
  } else {
    return cnt * price;
  }
}
