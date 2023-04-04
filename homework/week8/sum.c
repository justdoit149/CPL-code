#include <stdio.h>
#include <math.h>


int main(){
    int n,t,sum;
    scanf("%d%d",&n,&t);
    sum =  ( ( ( pow(10,n + 1) - 10 )/ 9) - n ) / 9 * t;
    printf("%d",sum) ;
    return 0;
}