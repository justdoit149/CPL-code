//二分查找(重要！！！)
//即给定一个由小到大排好序的数组，输入某一个数字（该数字在数组中），则输出这个数字是数组中的哪一个。
//可与前面selection-sort(选择排序程序)相结合组成新程序

#include <stdio.h>

#define LEN 10
int dictionary[LEN] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55};

int main() {
  int key = 0;
  scanf("%d", &key);
  //输入待查找的数字

  int low = 0;
  int high = LEN - 1;

  int index = -1;
  while (low <= high) {
    int mid = (low + high) / 2;
    //二分

    if (key > dictionary[mid]) {
      low = mid + 1;
    } else if (key < dictionary[mid]) {
      high = mid - 1;
    } else {
      index = mid;
      break;
    }
    //比较、查找，不相等则将mid赋值给low\high来缩小范围继续查找。
  }

if (index == -1) {
  printf("Not found!\n");
  //输入的数据不在数组内
} else {
  printf("The index of %d is %d.\n", key, index);
  //查找结果
}

  return 0;
}