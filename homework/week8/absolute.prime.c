#include <stdio.h>

int turn(int n);
int prime(int n);

int main(){
    int n,sum = 0;
    scanf("%d",&n);
    
    for(int i = 1; i <= n; i++){//从1到n，是素数则sum++
        sum = sum + ( prime(i) && prime(turn(i)));
    }
    printf("%d",sum);

    return 0;
}

int turn(int n){//由于数字比较小，直接列举来逆序。大的话要循环
    if(n < 10) return 0;
    else if(n < 100) return (n % 10 * 10 + n / 10);
    else return (n % 10 * 100 + n / 10 % 10 * 10 + n / 100);
}
int prime(int n){//判断是否是素数
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0) return 0;//一旦找到因子，直接结束
    }
    if(n == 1) return 0;//由于上面循环只有n>=4才进行，小于4的数里1不是素数，单独讨论
    return 1; 
}