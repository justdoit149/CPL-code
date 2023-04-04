#include <stdio.h>
#include <stdbool.h>
//五子棋赢之前不一定是4个，也可能是3+1或2+2，应该直接判断5个
int x,y;
char a[28][30];

bool check(char c);
int checkfive(char a1, char a2, char a3, char a4, char a5, char C);



int main(){
    int T;
    scanf("%d",&T);
    for(int i = 0; i < 28; i++){
        for(int j = 0; j < 28; j++){
            a[i][j] = '+';
        }
    }//棋盘扩展
    for(; T > 0; T--){
        for(int i = 4; i < 24; i++){
            scanf("%s",&a[i][4]);
        }
        if(check('*') == true){
            printf("Lose\n");
            goto finish;
        }else if(check('#') == false){
            printf("Not Sure\n");
            goto finish;
        }else{
            a[x][y] = '*';
            if(check('#') == false){
                printf("Not Sure\n");
                goto finish;  
            }
            printf("Win\n");
            goto finish;
        }
        finish:
    }
    return 0;
}

bool check(char c){
    for(int i = 4; i < 24; i++){
        for(int j = 4; j < 24; j++){
            if(a[i][j] == c){
                int answer = 0;
                for(int k = i-4; k <= i; k++){
                    answer = checkfive(a[k][j],a[k+1][j],a[k+2][j],a[k+3][j],a[k+4][j],c);
                    if(answer > 0){
                        x = k + answer - 1;
                        y = j;
                        return true;
                    }
                }
                for(int k = j-4; k <= j; k++){
                    answer = checkfive(a[i][k],a[i][k+1],a[i][k+2],a[i][k+3],a[i][k+4],c);
                    if(answer > 0){
                        x = i;
                        y = k + answer - 1;
                        return true;
                    }
                }
                for(int k = -4; k <= 0; k++){
                    answer = checkfive(a[i+k][j+k],a[i+k+1][j+k+1],a[i+k+2][j+k+2],a[i+k+3][j+k+3],a[i+k+4][j+k+4],c);
                    if(answer > 0){
                        x = i + k + answer - 1;
                        y = j + k + answer - 1;
                        return true;
                    }
                }
                for(int k = -4; k <= 0; k++){
                    answer = checkfive(a[i+k][j-k],a[i+k+1][j-k-1],a[i+k+2][j-k-2],a[i+k+3][j-k-3],a[i+k+4][j-k-4],c);
                    if(answer > 0){
                        x = i + k + answer - 1;
                        y = j - k - answer + 1;
                        return true;
                    }
                }   
            }
        }
    }
    return false;
}
int checkfive(char a1, char a2, char a3, char a4, char a5, char C){
    int count;
    if(a1==C) count++;
    if(a2==C) count++;
    if(a3==C) count++;
    if(a4==C) count++;
    if(a5==C) count++;
    if(count < 4) return 0;
    if(a1=='_') return 1;
    if(a2=='_') return 2;
    if(a3=='_') return 3;
    if(a4=='_') return 4;
    if(a5=='_') return 5;
    return 0;
}
