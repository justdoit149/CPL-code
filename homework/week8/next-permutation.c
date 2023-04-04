#include <stdio.h>

int main(){
    int n, a[2000]={0}, b[2000]={0}, m = 1;
    scanf("%d",&n);

    for(int i = 0; i < n; i++) scanf("%d",&a[i]);
    
    for(int i = n-1; a[i] < a[i-1]; m++,i--);
    
    int p = a[n - 1 - m];
        for(int i = n - m; i < n ; i++){
            if(a[i] > p && a[i + 1] <= p){
                a[n - 1 - m] = a[i];
                a[i] = p;
            }
        }

    for(int i = 0; i < n - m; i++) b[i] = a[i];
    for(int i = n - m; i < n; i++) b[i] = a[2 * n - m - 1 - i];
    for(int i = 0; i < n; i++) printf("%d ",b[i]);
    
    return 0;
}