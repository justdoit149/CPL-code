#include <stdio.h>

#define NUM 10
//宏定义数组大小，方便修改和维护

int main() {
  int numbers[NUM] = {0};

  for (int i = 0; i < NUM; i++) {
    scanf("%d", &numbers[i]);
  }

  int min = numbers[0];
  // (1) i++与++i
  // (2) int i = 1; since C99
  for (int i = 1; i < NUM; i++) {
    if (numbers[i] < min) {
      min = numbers[i];
    }
  }

  printf("min = %d\n", min);
  
  return 0;
}