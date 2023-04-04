#include <stdio.h>
#include <limits.h>
int main() {
  printf("UINT_MAX = %u\n", UINT_MAX);

  unsigned int max = UINT_MAX;
  unsigned int one = 1U;
  unsigned int two = 2U;

  printf("max + one = %u\n", max + one);
  printf("one - two = %u\n", one - two);

  return 0;
}
//有符号溢出：未定义行为
//无符号溢出：回绕现象