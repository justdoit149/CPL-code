//double pointers(双重指针)，即指针指向的对象是一个指针

//char *str[]:str数组，数组里的元素是指向char的指针，
//可以让这个指针数组里的每一个指针元素指向一个字符串，相当于实现了一个字符串数组
//arr+i表示arr数组里第i个元素的地址，arr[i]表示arr数组里的第i个元素
//所以，*(arr+i)(间接寻址)表示arr[i],**(arr+i)表示arr[i]这个指针元素指向的内容（字符/字符串）


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LEN 10

void Swap(char **left, char **right);
void Print(char *arr[], int len);
void SelectionSort(char *arr[], int len);

int main() {
  char * musicians[10] = {
    "Luo Dayou",
    "Cui Jian",
    "Dou Wei",
    "Zhang Chu",
    "Yao",
    "Wan Qing",
    "ZuoXiao",
    "ErShou Rose",
    "Hu Mage",
    "Li Zhi",
  };

  Print(musicians, LEN);
  SelectionSort(musicians, LEN);
  Print(musicians, LEN);
}

// char arr[]: char *arr
void Print(char *arr[], int len) {
  printf("\n");
  for (int i = 0; i < len; i++) {
    // *(arr + i)
    printf("%s\n", arr[i]);
  }
  printf("\n");
}

void SelectionSort(char *arr[], int len) {
  for (int i = 0; i < len; i++) {
    // find the minimum of numbers[i .. len - 1]
    char *min = arr[i];
    int min_index = i;
    for (int j = i + 1; j < len; j++) {
      if (strcmp(min, arr[j]) > 0) {
        min = arr[j];
        min_index = j;
      }
    }

    // swap arr[i] and arr[min_index]
    Swap(arr + i, arr + min_index);
  }
}

void Swap(char **left, char **right) {
  char *temp = *left;
  *left = *right;
  *right = temp;
}

// "Luo Dayou",
// "Cui Jian",
// "Dou Wei",
// "Zhang Chu",
// "Yao"
// "Wan Qing",
// "ZuoXiao",
// "ErShou Rose"
// "Hu Mage",
// "Li Zhi",