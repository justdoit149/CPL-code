#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <stdbool.h>

#define LEN 100
int numbers[LEN] = {0};

int main() {
  srand(time(NULL));
  for (int i = 0; i < LEN; i++) {
    numbers[i] = rand() % LEN;
  }
  //根据时间生成伪随机数
  //srand为伪随机数生成器（rand）设置种子
  //void srand(unsigned int seed)
  //使用seed来初始化通过调用rand函数产生的伪随机数序列
  //rand生成的一般是个比较大的数，可以通过取模来限制随机数的范围
  //头：<stdlib.h>
  
  // set a clock
  clock_t start = clock();

  // `swapped` is for optimization
  //如果内层循环进行一圈下来，swapped还是0，那么说明没有交换，也就是说已经排好，可以直接终止。
  bool swapped = true;
  for (int i = 0; i < LEN && swapped; i++) {
    swapped = false;
    for (int j = 0; j < LEN - 1 - i; j++) {
      if (numbers[j] > numbers[j + 1]) {
        int temp = numbers[j];
        numbers[j] = numbers[j + 1];
        numbers[j + 1] = temp;
        swapped = true;
      }
    }
  }

  // record the end clock
  clock_t end = clock();

  for (int i = 0; i < LEN; i++) {
    printf("%d ", numbers[i]);
  }

  long sec = (end - start) / CLOCKS_PER_SEC;
  printf("Sorting %d numbers in %ld seconds.\n", LEN, sec);

  return 0;
}