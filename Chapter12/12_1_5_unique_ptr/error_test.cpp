#include <algorithm>
#include <iostream>
#include <memory>

using std::cout;
using std::endl;
using std::make_unique;
using std::unique_ptr;
using IntP = unique_ptr<int>;

int main() {
#if 0
  unique_ptr<int> uip = make_unique<int>(10);

  unique_ptr<int> uip1 = uip;
  unique_ptr<int> uip2(uip);
#endif

  int ix = 0, *pi = &ix, *pi2 = new int(2048);

  // IntP p0(ix);
  IntP p1(pi);
  IntP p2(pi2);
  IntP p3(&ix);
  IntP p4(new int(2048));
  IntP p5(p2.get());

  return 0;
}
