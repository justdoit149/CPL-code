#include <stdio.h>

int main(){
    int n,q,x;
    int a[1005] = {0};
    scanf("%d%d",&n,&q);
    for(int i = 0; i < n; i++){
        scanf("%d",&a[i]);
    }
    for(int i = 0; i < q; i++){
        int l = 0, r = n-1, mid;
        scanf("%d",&x);
        again:
        mid = (l+r) / 2;
        if(a[mid] == x){
            printf("%d\n",mid);
            goto finish;
        }else if(a[mid] > x){
            if(r < l){
                printf("-1\n");
                goto finish;
            }
            r = mid-1;
            goto again;
        }else{
            if(r < l){
                printf("-1\n");
                goto finish;
            }
            l = mid + 1;
            goto again;
        }



        finish: 
    }

    return 0;
}