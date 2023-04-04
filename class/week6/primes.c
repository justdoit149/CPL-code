//输入一个数，输出小于等于这个数的所有素数。

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main()
{
    int max;
    scanf("%d",&max);
    for(int num = 2;num <= max; num ++){
        _Bool yes = true;
        for(int i=2;i<=sqrt(num);i++){
            if(num % i == false){
                yes = false;
                break;
            }
        }
        if(yes == true){
            printf("%d ",num);
        }
    }

    return 0;
}
//只需要判断到i<=sqrt(n)即可，不需要到n，简化程序。
//也可写做 i * i <= n ,这样不需要调用sqrt函数。