#include <stdio.h>

int main()
{
    int money,a[5],i;
    int b[5]={50,20,10,5,1};
    
    scanf("%d",&money);

    for(i=0;i<5;i++){
        a[i]=money/b[i];
        money=money-a[i]*b[i];
    }

    printf("%d\n%d\n%d\n%d\n%d\n",a[0],a[1],a[2],a[3],a[4]);

    return 0;
}