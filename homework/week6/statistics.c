#include <stdio.h>

int main()
{
    int n=0,max=0,num=0;
    char a[1005]={' '};
    short b[150]={0};
    char c[100]={' '};
    int d[100]={0};
    //a:输入字符串   b:对对应ASCII码的字符计数   c:重新排序为最后一行要输出的格式    d:重新排序计数
    scanf("%d",&n);
    getchar();
    scanf("%s",a);

    for(int i = 0; i < n; i++){
        for(int ascii = 65; ascii < 123; ascii ++){
            if(ascii == a[i]){
                b[ascii]++;
                break;
            }
        }
    }
    //计数

    for(int i = 65,count = 0; i < 123; i++){
        if(b[i] > max){
            max = b[i];
        }
        if(b[i] != 0){
            count ++; 
        }
    }
    //统计行数与非空字符数

    for(int i = 97; i < 123; i++){
        _Bool YORN = 0;
        if(b[i] != 0){
            c[num] = i;
            d[num] = b[i];
            num++;
            YORN = 1;
        }
        if(b[i-32] != 0){
            c[num] = i - 32;
            d[num] = b[i - 32];
            num++;
            YORN = 1;
        }
        if(YORN == 1){
            num++;
        }
    }
    //完成最后一行格式化的记录。共num-1列。

    for(int i = max; i > 0; i--){
        for(int j = 0; j < 90; j++){
            if(d[j] >= max){
                printf("=");
            }else{
                printf(" ");
            }
        }
        max--;
        printf("\n");
    }
    //输出表格,i表示行,j表示列
    for(int i=1; i < num; i++){
        printf("-");
    }
    printf("\n");

    for(int i = 0; i < 100; i++){
        if(c[i] != 0){
            putchar(c[i]);
        }else{
            printf(" ");
        }
    }

    return 0;
}