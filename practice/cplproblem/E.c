#include <stdio.h>

int block[10005] = {0};
int main(){
    int left = 1, right,n,x,len,y,max = 0, sum = 0;
    scanf("%d%d%d",&n,&x,&len);
    getchar();
    for(int i = 0; i < n; i++){
        scanf("%d",&y);
        block[y]++;
    }
    //block数组储存位置x的员工数block[x], 1 <= x <= len
    for(int i = 1; block[i] == 0; i++) left = i + 1;
    right = left + x;
    for(int i = left; i <= right; i++){
        sum = sum + block[i];
    }
    max = sum;
    //初始化max\sum

    for(int i = left; i <= len - x ; i++){
        sum = sum + block[i + x + 1] - block[i];
        if(sum > max && block[i + 1] > 0){        
            max = sum;    
            left = i + 1;
            right = i + x + 1;
        }
    }
    printf("%d %d\n%d",left,right,max);

    return 0;
}