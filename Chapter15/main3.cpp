#include <iostream>

using std::cout;
using std::endl;

class A {
public:
  int a = 0;
};

class B_1 : public A {
  friend void b_one(B_1 &b) { A *a = &b; }
  void conv(B_1 &b) { A *a = &b; }
};
class B_2 : protected A {
  friend void b_two(B_2 &b) { A *a = &b; }
  void conv(B_2 &b) { A *a = &b; }
};
class B_3 : private A {
  friend void b_three(B_3 &b) { A *a = &b; }
  void conv(B_3 &b) { A *a = &b; }
};

int main() {
  B_1 b1;
  B_2 b2;
  B_3 b3;

  A *a1 = &b1;
  // A *a2 = &b2;
  // A *a3 = &b3;
  return 0;
}

class C_pub : public B_1 {
  friend void ttt1(B_1 *b) { A *a = b; }
  void vvv(B_1 *b) { A *a = b; }
};

class C_prot : public B_2 {
  friend void ttt2(B_2 *b) { A *a = b; }
  void vvv(B_2 *b) { A *a = b; }
};

class C_priv : public B_3 {
  // friend void ttt3(B_3 *b) { A *a = b; }
  // void vvv(B_3 *b) { A *a = b; }
};
