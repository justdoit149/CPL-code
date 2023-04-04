#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
int len = 8;
int main(){
    char *str = malloc((len + 1) * sizeof(char));
    unsigned int a = 0;
    scanf("%s",str);
    *(str + 8) = 0;
    for(int i = 7; i >= 0 ; i--){
        char x = *(str + i);
        if(x > 57){
            x = x - 87;
        }else{
            x = x - 48;
        }
        a = a + (int)x * pow(16,7 - i);
    }
    float *b = & a;
    printf("%d\n%u\n%f\n%.3e\n",a,a,*b,*b);
    return 0;
}
//理解
//printf里用%f默认是double类型，
//就是如果printf("%f",a)的话，a为32位，double为64位
//会在a前面补32位（0）之后载按照double理解，会是一个很小的数
//而且float和double的指数位的个数不一样，所以不能让它在a后边补32个0
//因此只能用float *b指针指向a。这样*b里边存的是32位的float型。
//然后输出的时候会把float按照一定的规则转换为double型（printf函数来做这件事）。