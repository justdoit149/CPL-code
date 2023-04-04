#include <stdio.h>

int main(){
    int T,m,n,x,swap;
    int a[1005] = {0};

    scanf("%d",&T);
    for(; T > 0; T--){
        scanf("%d%d",&n,&m);
        for(int i = 0; i < n; i++){
            scanf("%d",&a[i]);
        }
        for(int i = 0; i < m; i++){
            scanf("%d",&x);
            swap = a[x-1];
            for(int j = x-2; j >= 0; j--){
                a[j+1] = a[j];
            }
            a[0] = swap;
        }
        for(int i = 0; i < n-1; i++){
            if(a[i] > a[i+1]){
                printf("mayi is a good teacher\n");
                goto next;
            }
        }
        printf("I love C programming language\n");
        next:
    }

    return 0;
}