#include <stdio.h>
//不要轻易混用有符号和无符号类型
//有符号会被转化为无符号再参与运算（-1 --> UINT_MAX）（计基）
//无符号常用于位运算等底层运算，尽量少用
//定义新的数据类型：
//typedef int NNN
//即NNN代表int类型

int main() {
  int array[] = {0, 1, 2, 3, 4};
  int i = -1;

  size_t size = sizeof array;
  //size_t实际上是一种无符号整型
  printf("The size of the array is %zu\n", size);

  if (i <= size) {
    printf("i <= sizeof array\n");
  } else {
    printf("i > sizeof array\n");
  }

  return 0;
}