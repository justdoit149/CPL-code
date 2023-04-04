#include <stdio.h>

int main()
{
    int a[100];
    int b[100]={0};
    int n;

    scanf("%d",&n);

    for(int i=0;i<2*n-1;i++){
        scanf("%d",&a[i]);
    }

    for(int i=0;i<2*n-1;i++){
        if(b[a[i]]==0){
            b[a[i]]=a[i];
        }else{
            b[a[i]]=0;
        }
    }

    for(int i=0;i<2*n-1;i++){
        if(b[a[i]]!=0){
            printf("%d",b[a[i]]);
        }
    }

    return 0;
}