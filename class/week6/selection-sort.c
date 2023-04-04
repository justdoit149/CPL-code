    //scanf的返回值：
    //成功读入则返回1；若是输入类型与转换说明的类型不匹配，那返回0；若根本没有输入，返回EOF（一般为-1）
    //如%d,输入2返回1，输入a返回0，无则返回EOF
    //ctrl+D来返回EOF，但在本电脑VSC这样写程序会崩溃......


//选择排序（重要！！！），对于n个数，一共需要比较1+2+3+……+（n-1）=n * (n - 1) / 2 次
//二重循环，对第i个数字和第i+1、i+2……、第n个数分别比较，如果第i个数字比后面的大就交换
//(区分冒泡排序，冒泡是比较并交换相邻的)

#include <stdio.h>

#define LEN 20
int numbers[LEN] = {0};

int main() {

  int len = -1;
  while(scanf("%d", &numbers[++len]));    //读取数值，当输入非数值非空字符后表示结束
  for (int i = 0; i < len; i++) {
    printf("%d ", numbers[i]);
  }// 输出正常顺序的数字
  printf("\n");
  
  for (int i = 0; i < len - 1; i++) {
    int min = numbers[i];
    int min_index = i;//先初始假设第i个数是最小的。
    for (int j = i + 1; j < len; j++) {
      if (numbers[j] < min) {
        min = numbers[j];
        min_index = j;
      }
    }
    //将第i+1到第n数依次和第i个数比较，若小于第i个数则更新最小值，这样之后min一定是从第i个到第n个里最小的。

    int temp = numbers[i];
    numbers[i] = numbers[min_index];
    numbers[min_index] = temp;
    //这时将这个最小值赋值给numbers[i]，即排好了第i个，也就是第0个到第i个。
  }
//这个for循环实现选择排序过程。

  for (int i = 0; i < len; i++) {
    printf("%d ", numbers[i]);
  }
//输出排序后的数组结果。

  return 0;
}