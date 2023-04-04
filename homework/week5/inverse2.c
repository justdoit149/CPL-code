#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);

    int a[10];
    for(int i=0;i<=n;i++){
        a[i]=getchar();
    }

    int k;
    scanf("%d",&k);
    
    for(int i=k;i>0;i--){
        putchar(a[i]);
    }
    for(int i=n;i>k;i--){
        putchar(a[i]);
    }

    return 0;
}