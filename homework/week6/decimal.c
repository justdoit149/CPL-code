#include <stdio.h>
#include <math.h>

//本程序为进制转换器，输入格式为：先输入数字位数，空格后输入整数N表示N进制（N<=16），然后回车后输入N进制数。
int main()
{
    int len,N,count=0,sum,SUM=0;
    char s[31];
    char a[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

    scanf("%d%d",&len,&N);
    getchar();
    scanf("%s",s);

    for(int i = 0; i < len; i++){
        for(int j = 0; j < N;j++){
            if(s[i]!=a[j]){
                count++;
            }
        }
    }
    sum = len * (N - 1);
    if(count != sum){
        printf("Error");
    }else{
        for(int i = 0;i < len; i++){
            for(int j = 0; j < N; j++){
                if(s[i] == a[j]){
                    SUM = SUM + j * pow(N,len - i - 1);
                } 
            }
        }
        printf("%d",SUM);
    }

    return 0;
}