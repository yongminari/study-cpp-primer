#include <stdio.h>

int main() {
  int arr[100] = {};
  for (int i = 0; i < sizeof arr / sizeof *arr; i++) {
    printf("%d\n", arr[i]);
  }
  return 0;
}
