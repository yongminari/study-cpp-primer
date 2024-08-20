#include "Sales_data.h"
#include "iostream"

int main() {
  Sales_data data1, data2;
  double price = 0.0;

  std::cin >> data1.bookNo >> data1.unit_sold >> price;
  data1.revenue = data1.unit_sold * price;

  std::cin >> data2.bookNo >> data2.unit_sold >> price;
  data2.revenue = data2.unit_sold * price;

  if (data1.bookNo == data2.bookNo) {
    unsigned totalCnt = data1.unit_sold + data2.unit_sold;
    double totalRevenue = data1.revenue + data2.revenue;

    std::cout << data1.bookNo << " " << totalCnt << " " << totalRevenue << " ";
    if (totalCnt != 0) {
      std::cout << totalRevenue / totalCnt << std::endl;
    } else {
      std::cout << "No Sales" << std::endl;
    }

    return 0;
  } else {
    std::cout << "Book No should be same" << std::endl;
    return -1;
  }
  return 0;
}
