#include <stdio.h>

int main()
{
    int n,k,a[100]={0};

    scanf("%d%d",&n,&k);
    for(int i = 1; i <= n; i ++){
        scanf("%d",&a[i]);
    }

    int mid = a[k];
    int l = 1,r = n;
    while(l != r){
        for(; l < r && a[l] < mid; l++);
        for(; r > l && a[r] >= mid; r--);
        if(l == r){
            break;
        }
        int swap = a[l];
        a[l] = a[r];
        a[r] = swap;
    }
    if(a[l] != mid){
        for(int i = 1; i <= n; i++){
            if(a[i] == mid){
                k = i;
            }
        }
        int Swap = a[l];
        a[l] = a[k];
        a[k] = Swap;
    }
    for(int i = 1; i <= n; i++){
        printf("%d ",a[i]);
    }

    return 0;
}