#include <stdio.h>

int main(){
    int n, max = 0, sum = 0;
    int a[101] = {0}, b[101] = {0};
    scanf("%d",&n);
    for(int i = 1; i <= n; i++){
        scanf("%d",&a[i]);
        max = ((a[i] - a[i - 1] > max && i != 1)? a[i] - a[i - 1] : max);
    }
    for(int i = 1; i <= n; i++){
        b[i] = a[1] + (i - 1) * max;
    }
    sum = b[n] - a[n];

    printf("%d\n",sum);
    for(int i = 1; i <= n; i++){
        printf("%d ",b[i]);
    }
    
    return 0;
}