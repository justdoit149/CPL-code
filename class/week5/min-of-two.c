#include <stdio.h>

int main() {
  int a = 0;
  int b = 0;

  scanf("%d%d", &a, &b);
  int min = 0;

  // code style，注意表达式里运算符前后留个空格
  // {}括号不要随便省略
  // ?:三目运算符尽量少用，尤其不要嵌套。
  if (a >= b) {
    min = b;
  } else {
    min = a;
  }

  min = a >= b ? b : a;

  printf("min{%d, %d} = %d\n", a, b, min);

  return 0;
}