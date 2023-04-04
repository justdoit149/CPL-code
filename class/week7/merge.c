//merge：归并
//mergesort：归并排序
//merge过程：将两个排好序的数组归并成一个排好序的数组
//思路：l、r分别初始为0，比较a[l]和b[r]，谁小就输出谁然后对应的下标自增再比较
//直到有一个数组遍历完，然后把另一个数组的剩余部分输出

//这个程序只打印排序结果，不存储
#include <stdio.h>
#define LEN_L 5
#define LEN_R 6

int L[LEN_L] = {1, 3, 5, 7, 9};
int R[LEN_R] = {0, 2, 4, 6, 8, 10};

int main(){
    int a[LEN_L + LEN_R]= {0};
    int l = 0, r = 0;

    while( l < LEN_L && r < LEN_R){
      if(L[l]<=R[r]){
        printf("%d ",L[l]);
        l++;
      }else{
        printf("%d ",R[r]);
        r++;
      }
    }
   
    while(r<LEN_R){
        printf("%d ",R[r]);
        r++;
    }
  

    while(l<LEN_L){
        printf("%d ",L[l]);
        l++;
    }
  return 0;
}
