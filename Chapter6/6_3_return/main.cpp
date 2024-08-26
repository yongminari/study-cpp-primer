#include <iostream>

typedef int arrT1[10];
using arrT2 = int[10];

int testArr[10];
arrT1 testArr1;
arrT2 testArr2;

arrT1 *func1(int i) {
  if (i < 10) {
    return &testArr;
  } else if (i < 20) {
    return &testArr1;
  } else {
    return &testArr2;
  }
  return nullptr;
}

arrT2 *func2(int i) {
  if (i < 10) {
    return &testArr;
  } else if (i < 20) {
    return &testArr1;
  } else {
    return &testArr2;
  }
  return nullptr;
}

int (*func3(int i))[10] {
  if (i < 10) {
    return &testArr;
  } else if (i < 20) {
    return &testArr1;
  } else {
    return &testArr2;
  }
  return nullptr;
}

int main() {
  int(*retTest1)[10] = func1(10);
  arrT1 *retTest2 = func2(20);
  arrT2 *retTest3 = func3(30);
  std::cout << "what?" << std::endl;
  return 0;
}
