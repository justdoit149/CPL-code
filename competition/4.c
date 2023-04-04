#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int T;
char a[60][10];
int indexs[5][2];

int main(){
    for(int i = 0; i < 60; i++){
        for(int j = 0; j < 10; j++){
            a[i][j] = '\0';
        }
    }
    scanf("%d",&T);
    getchar();
    for(int i = 0; i < 5 * T; i++){
        scanf("%s",a[i]);
    }
    
    for(int i = 0; i < 5*T; i = i + 5){
        int index_x, index_y;
        bool YON = 0;
        for(int j = i; j < i + 3; j++){
            for(int k = 3; k < 6; k++){
                if(a[j][k] == 'k'){
                    index_x = j;
                    index_y = k;
                }
            }
        }
        int counts = 0;
        for(int j = i; j < i + 5; j++){
            for(int k = 0; k < 9; k++){
                if(a[j][k] == 's'){
                    indexs[counts][0] = j;
                    indexs[counts][1] = k;
                    counts++;
                }
            }
        }
        if(counts==1){
            printf("YES\n");
        }else{
            if(index_x==i){
                if(a[i+1][index_y-1] == '#' && a[i+1][index_y+1] == '#'){
                    printf("YES\n");
                }else if(a[i+1][index_y-1] == 's' && a[i+1][index_y+1] == 's'){
                    if(index_y != 4){
                        printf("NO\n");
                    }else{
                        if(counts == 2){
                            printf("YES\n");
                        }else{
                            if(a[i+2][4] != 's' && a[i][2]!='s'&&a[i][6]!='s'){
                                printf("YES\n");
                            }else{
                                printf("NO\n");
                            }
                        }
                    }
                }else{
                   printf("NO\n");
                }
            }else if(index_x==i+2){
                printf("NO\n");
            }else{
                printf("YES\n");
            }
        }
    }
    return 0;
}
//可能的做法：
//枚举？把每一个敌方棋子都走一遍试试，如果不能将则走下一个
//如果能将则把每一个我方棋子走一遍，然后再看看每个敌方棋子能否直接走到老将的位置
//若能则NO，若不能则继续走敌方棋子，直到试完每一个敌方棋子。
//可是具体怎么实现呢？