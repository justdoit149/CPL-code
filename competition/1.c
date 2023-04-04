#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define LEN 1005
int a[LEN], b[LEN] = {0};
int main(){
    int n, index_2;
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        scanf("%d",&a[i]);
        if(a[i] == 2){
            index_2 = i;
            b[i] = 1;
        }
    }
    //读入，解决1和2
    if(index_2 == n-1){
        ;
    }else if(a[index_2+1] == 0){
        b[index_2+1] = 1;
    }else{
        for(int j = index_2 + 1; j < n-1; j = j + 2){
            if(a[j]==1 && a[j+1]==0){
                b[j+1] = 1;
            }else{
                goto left;
            }
        }
    }
    //向右
    left:
    if(index_2 == 0){
        ;
    }else if(a[index_2-1] == 0){
        b[index_2-1] = 1;
    }else{
        for(int j = index_2 - 1; j > 0; j = j - 2){
            if(a[j]==1 && a[j-1]==0){
                b[j-1] = 1;
            }else{
                goto finish;
            }
        }
    }
    finish:
    for(int i = 0; i < n; i++){
        printf("%d ",b[i]);
    }
    //向左
    return 0;
}