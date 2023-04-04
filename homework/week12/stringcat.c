#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 55
void mystrcat(char*x, char*y);
int main(){
    int T;
    scanf("%d",&T);
    char *a = malloc(LEN * LEN / 2);
    char *b = malloc(LEN * LEN / 2);
    for(int i = 0; i < T; i++){
        scanf("%s%s",a + i * LEN,b + i * LEN);
    }
    //二维数组
    for(int i = 0; i < T; i++){
        mystrcat(a + i * LEN, b + i * LEN);
    }
    
    return 0;
} 

void mystrcat(char*x, char*y){
    int m = strlen(x);
    int n = strlen(y);
    //不要直接把strlen写到循环的条件里，那样会计算很多次strlen，非常慢
    for(int i = (m > n ? m - n : 0); i < m; i++){
        int t = 0;
        for(int j = 0; i + j < m ; j++){
            if(*(x + i + j) != *(y + j)){
                goto fake;
            }
        }
        t = 1;
        fake:
        if(t == 1){
            *(x + i) = '\0';
            printf("%s%s\n",x,y);
            return;
            //通过加入\0来终止字符串
        }
    }
    printf("%s%s\n",x,y);
    return;
}