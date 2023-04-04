//由于因子一般是成对存在的，故奇数个因子只能是完全平方数。意识到这一点可以打表（bushi）
#include <stdio.h>

int main()
{
    _Bool a[2001] = {0};
    
    for(int i = 1; i <= 2000; i++){
        for(int j = 1; j <= i; j++){
            if(i % j == 0){
                if(a[i] == 0){
                    a[i] = 1;
                }
                else{
                    a[i] = 0;
                }
            }
        }
    }

    int n;
    scanf("%d",&n);

    for(int i = 1; i <= n; i++){
        if(a[i] == 1){
            printf("%d ",i);
        }
    }

    return 0;
}