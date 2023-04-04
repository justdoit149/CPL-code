#include <stdio.h>

int main(){
    int n,x,y;
    int a[99][99]={0};
    scanf("%d",&n);
    
    y = (n - 1) / 2; x = 0;

    for(int i = 1; i <= n*n; i++){
        a[x][y] = i;
        if(a[(x+n-1) % n][(y+1) % n] == 0){
            x = (x + n - 1) % n;
            y = (y + 1) % n;
        }else{
            x++;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }

    return 0;
}