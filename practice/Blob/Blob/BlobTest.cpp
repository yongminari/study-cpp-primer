#include "Blob.h"
#include <string>

using std::string;

void test() {
  Blob<int> ia;
  Blob<int> ia2 = {0, 1, 2, 3, 4};

  Blob<string> names;
  Blob<double> prices;

  Blob<string> articles = {"a", "an", "the"};
}
