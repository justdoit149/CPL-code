#include <stdio.h>
//尽量不要用char表示比较小的整数……

int main() {
  // (signed) char on my computer: -128 ~ 127
  // using unsigned char c = 150;
  char c = 150;
  int i = 900;

  printf("%d\n", c);
  printf("i / c = %d\n", i / c);

  return 0;
}