#include <stdio.h>

int a[100005];
int main(){
    int T,n;
    scanf("%d",&T);
    for(int i = 0; i < T; i++){
        scanf("%d",&n);
        for(int j = 0; j < n; j++){
            scanf("%d",&a[j]);
        }
        for(int j = 0; j < n - 1; j++){
            
            if(a[j] > a[n-1]){
                printf("No\n");
                goto finish;
            }
        }
        printf("Yes\n");
        finish:
    }
    return 0;
}