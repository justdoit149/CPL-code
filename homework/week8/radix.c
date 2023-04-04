#include <stdio.h>

int turn(int n,int N);
int max(int n);
int Max(int a,int b,int c);

int main(){
    int p,q,r,M;
    scanf("%d%d%d",&p,&q,&r);
    M = Max(max(p),max(q),max(r)) + 1;//从M进制开始判断，避免出现无意义情况

    for(int i = M; i <= 40; i++){
        if(turn(p,i) * turn(q,i) == turn(r,i)){
            printf("%d",i);
            return 0;//从小到大找，找到直接结束程序
        }    
    }
    printf("0");//只有没找到才会执行这个语句输出0
    return 0;
}

int turn(int n,int N){//n为N进制数，转换为十进制
    return (n / 10 * N + n % 10);
}
int max(int n){//n这个数字个位、十位上的最大数，进制必须大于它
    return ((n % 10) > (n / 10) ? (n % 10) : (n / 10));
}
int Max(int a,int b,int c){//找p,q,r最大进制
    int m = a;
    if(b > a) m = b;
    if(c > m) m = c;
    return m;
}