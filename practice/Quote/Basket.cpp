#include "Basket.h"
#include <ostream>

using std::endl;
using std::ostream;

double Basket::total_receip(std::ostream &os) const {
  double sum = 0.0;
  for (auto iter = items.cbegin(); iter != items.cend();
       iter = items.upper_bound(*iter)) {
    sum += print_total(os, **iter, items.count(*iter));
  }
  os << "Total Sale: " << sum << endl;
  return sum;
}
