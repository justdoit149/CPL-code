#include <stdio.h>

int main()
{
    int n;
    char a[102][102],b[102][102];    
    for(int i = 0; i < 102; i++){
        for(int j = 0; j < 102; j++){
            a[i][j] = 'o';
        }
    } 
//初始化棋盘全不为雷

    scanf("%d",&n);
    getchar();

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j ++){
            scanf("%c",&a[i][j]); 
        }
        getchar();
    }
//读取棋盘

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(a[i][j] == '*'){
                b[i][j] = '*';
            }else{
                b[i][j] = (a[i-1][j-1] == '*') +
                          (a[i-1][j] == '*')   +
                          (a[i-1][j+1] == '*') +
                          (a[i][j-1] == '*')   +
                          (a[i][j+1] == '*')   +
                          (a[i+1][j-1] == '*') +
                          (a[i+1][j] == '*')   +
                          (a[i+1][j+1] == '*') + 48;
            }            
        }
    }
//生成新棋盘。注意灵活运用“若一个表达式为真则值为1，假则值为0”，免得写很多if语句。

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            printf("%c",b[i][j]);
        }
        printf("\n");
    }

    return 0;
}