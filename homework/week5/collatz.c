#include <stdio.h>

int main()
{
    int n,max,num;

    scanf("%d",&n);

    max=n;
    num=0;

    for(num=0;n!=1;num++){
        if(n%2==0){
            n=n/2;
        }else{
            n=3*n+1;
            if(n>max){
                max=n;
            }
        }
    }

    printf("%d %d",num,max);

    return 0;
}