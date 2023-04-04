#include <stdio.h>

const int X = 100, Y = 100;
int main(){
    int T, line = 0, bmax = 0, amax = 0, Ymax = 0; //line记录当前在第几行
    int a[51] = {0}, b[51] = {0}, c[51] = {0};
    char p[X][Y];    //p means picture
    for(int i = 0; i < X; i++){
        for(int j = 0; j < Y; j++){
            p[i][j] = ' ';
        }
    }
    scanf("%d",&T);
    for(int i = 1; i <= T; i++){
        scanf("%d%d%d",&a[i],&b[i],&c[i]);
    }
    for(int i = 1; i <= T; i++){
        bmax = (b[i] > bmax ? b[i] : bmax);
        amax = (a[i] > amax ? a[i] : amax);
    }
    Ymax = 2 * (bmax + amax);
    

    for(int i = 1; i <= T; i++){
        int topfront = line + 2 * b[i];
        int bottomfront = line + 2 * (b[i] + c[i]);
        int rightfront = 2 * a[i];
        int rightright = 2 * (a[i] + b[i]);
        //找到四条边线 
        for(int j = topfront; j < bottomfront; j = j + 2){
            for(int k = 0; k < rightfront; k = k + 2){
                p[j][k] = '+', p[j][k+2] = '+', p[j+2][k] = '+', p[j+2][k+2] = '+';
                p[j][k+1] = '-', p[j+2][k+1] = '-';
                p[j+1][k] = '|', p[j+1][k+2] = '|';
            }
        }
        for(int j = topfront; j < bottomfront; j = j + 2 + 2 * b[i]){
            for(int k = rightfront; k < rightright; k = k + 2, j = j - 2){
                p[j][k] = '+', p[j][k+2] = '+', p[j+2][k] = '+', p[j-2][k+2] = '+';
                p[j-1][k+1] = '/', p[j+1][k+1] = '/';
                p[j+1][k] = '|', p[j-1][k+2] = '|';
            }
        }
        for(int j = topfront; j > line; j = j - 2){
            for(int k = topfront - j; k < topfront - j + rightfront; k = k + 2){
                p[j][k] = '+', p[j][k+2] = '+', p[j-2][k+2] = '+', p[j-2][k+4] = '+';
                p[j-1][k+1] = '/', p[j-1][k+3] = '/';
                p[j][k+1] = '-', p[j-2][k+3] = '-';
            }
        }
        //依次画正、侧、上面。
        line = bottomfront + 1;
    }

    for(int i = 0; i < line; i++){
        for(int j = 0; j <= Ymax; j++){
            putchar(p[i][j]);
        }
        printf("\n");
    }

    return 0;
}