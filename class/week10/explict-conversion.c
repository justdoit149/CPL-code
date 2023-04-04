#include <stdio.h>
#include <limits.h>

int main() {
  double pi = 3.14159;
  
  printf("%f\n",pi - (int) pi);
  // below: obtain its fractional part

  int num = 1000000000;
  printf("LLONG_MAX = %lld\n", LLONG_MAX);
  // long long llint = num * num;
  long long llint = (long long) num * num;
  //若不强制转换，num*num得到的是int类型，已经越界了，再赋给llint已经晚了。
  printf("i = %lld\n", llint);

  return 0;
}