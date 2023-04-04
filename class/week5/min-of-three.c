#include <stdio.h>

int main() {
  int a,b,c,min;

  scanf("%d%d%d", &a, &b, &c);

  if (a > b) {
    if (b > c) {
      min = c;
    } else {
      min = b;
    }
  } else {  
    if (a < c) {
      min = a;
    } else { 
      min = c;
    }
  }

  printf("min{%d, %d, %d} = %d\n", a, b, c, min);

  return 0;
}