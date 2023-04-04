#include <stdio.h>

int main()
{
    int a[9][9] = {0};

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            scanf("%d",&a[i][j]);
        }
    }
//数据读取。    
    
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(a[i][j] > 9){
                printf("NO");
                return 0;
            }
        }
    }
//判断数字范围是否合法。 

    for(int i = 0;i < 9;i++){
        for(int j = 0; j < 9; j++){
            for(int k = j + 1; k < 9; k++){
                if(a[i][j] == a[i][k] || a[j][i] == a[k][i]){
                    printf("NO");
                    return 0;
                }
            }
        }    
    }
//判断行、列是否合法。
    
    for(int i = 0; i < 9; i = i + 3){
        for(int j = 0; j < 9; j = j + 3){
            int b[9] = {a[i][j],a[i][j+1],a[i][j+2],
                        a[i+1][j],a[i+1][j+1],a[i+1][j+2],
                        a[i+2][j],a[i+2][j+1],a[i+2][j+2]};
            for(int m = 0; m < 9; m++){
                for(int n = m + 1; n < 9; n++){
                    if(b[m] == b[n]){
                        printf("NO");
                        return 0;
                    }
                }
            }
        }
    }
//判断矩形框是否合法

    printf("YES");
    return 0;
}