#include <stdio.h>
#include <math.h>
#define LEN 4
char a[LEN+1][2*LEN+2];

void write(int n,int x,int y);

int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1;i <= LEN + 1; i++){
        for(int j = 1; j <= 2*LEN + 1; j++){
            a[i][j] = ' ';
        }
    }
    write(n,1,pow(2,n));
    for(int i = 1;i <= LEN; i++){
        for(int j = 1; j <= 2*LEN; j++){
            putchar(a[i][j]);
        }
        printf("\n");
    }

    return 0;
}

void write(int n,int x,int y){
    if(n == 1){
        a[x][y] = '/'; 
        a[x][y+1] = '\\';
        a[x+1][y-1] = '/';
        a[x+1][y] = '_';
        a[x+1][y+1] = '_';
        a[x+1][y+2] = '\\';
        return ;
    }
    write(n-1,x,y); 
    write(n-1,x+pow(2,n-1),y-pow(2,n-1));
    write(n-1,x+pow(2,n-1),y+pow(2,n-1));
    
}