#include <stdio.h>

int main()
{
    int n,rest;
    int sum=0;
    int b[30]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    scanf("%d",&n);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            b[i]=(b[i]*j)%10007;
        }
    } 

    for(int i=1;i<=n;i++){
        sum=sum+b[i];
    }

    rest=sum%10007;

    printf("%d",rest);

    return 0;
}