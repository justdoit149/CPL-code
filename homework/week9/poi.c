#include <stdio.h>

int boss(int x);

int a[100001] = {0};
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1; i <= n; i++){
        scanf("%d",&a[i]);
    }

    for(int i = 1; i <= n; i++){
        printf("%d ",boss(i));
    }
    
    return 0;
}

int boss(int x){
    if(a[x] == x) return x;
    return boss(a[x]);
}