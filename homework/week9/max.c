#include <stdio.h>

int max(int l,int r);
int qujian(int X,int Y);
int a[100001] = {0},L[100001] = {0}, R[100001] = {0};

int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1; i <= n; i++){
        scanf("%d",&a[i]);
    }
    int l = 1, r = n;
    qujian(l,r);
    for(int i = 1; i <= n; i++){
        printf("%d %d\n",L[i],R[i]);
    }
    return 0;
}

int max(int x,int y){
    if(x == y) return x;
    int m = x;
    for(int i = x; i < y; i++){
        m = (a[i+1] > a[m] ? i+1 : m);
    }
    return m;
}

int qujian(int X,int Y){
    if(X > Y) return 0;
    L[max(X,Y)] = X;
    R[max(X,Y)] = Y;
    qujian(X,max(X,Y)-1);
    qujian(max(X,Y)+1,Y);
}