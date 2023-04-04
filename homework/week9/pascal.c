#include <stdio.h>

int sum(int x,int y);

int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    int c = sum(a-1,b-1);
    printf("%d",c);
    return 0;
}

int sum(int x,int y){
    if(y == 0 || y == x) return 1;
    if(y == 1 || y == x - 1) return (sum(x-1,y-1) + sum(x-1,y));
    return (sum(x-2,y-2) + 2 * sum(x-2,y-1) + sum(x-2,y));
}