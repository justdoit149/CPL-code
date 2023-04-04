// 隐式类型转换发生情况：
// 1.算术表达式和逻辑表达式中，类型提升（例：1+2.3）
// 2.定义初始化、赋值
// 3.函数调用、返回时
// 后两种若数值和类型不符，会做类型转换（转换成定义/声明的类型）。

#include <limits.h>
#include <stdio.h>

int SquareInt(int num);
double SquareDouble(double num);

int main() {
  // narrowing conversion (still in the range)
  int i = 3.14159;

  // out of the range: undefined behavior!!!
  int j = UINT_MAX;

  // arguments; narrowing conversion
  double k = 3.14159;
  SquareInt(k);

  // return value; narrowing conversion
  int m = SquareDouble(k);

  return 0;
}

int SquareInt(int num) {
  return num * num;
}

double SquareDouble(double num) {
  return num * num;
}