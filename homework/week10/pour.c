//递归好题

#include <stdio.h>
#include <stdbool.h>
bool poor(int k,int a,int b,int c);
int VA,VB,VC,a0,b0,c0;

int main(){
    int k,a,b,c;
    scanf("%d%d%d%d%d%d%d%d%d%d",&k,&VA,&VB,&VC,&a,&b,&c,&a0,&b0,&c0);
    poor(k,a,b,c) == 1 ? printf("Yes") : printf("No");
    return 0;
}

bool poor(int k,int a,int b,int c){
    if(k < 0) return false;
    if(k >= 0 && a == a0 && b == b0 && c == c0) return true;
    return (poor(k - 1, 0, (VB - a - b > 0 ? a + b : VB), c)
          ||poor(k - 1, 0, b, (VC - a - c > 0 ? a + c : VC))
          ||poor(k - 1, a, (VB - c - b > 0 ? c + b : VB), 0)
          ||poor(k - 1, (VA - a - c > 0 ? a + c : VA), b, 0)
          ||poor(k - 1, (VA - a - b > 0 ? a + b : VA), 0, c)
          ||poor(k - 1, a, 0, (VC - c - b > 0 ? c + b : VC)));
}