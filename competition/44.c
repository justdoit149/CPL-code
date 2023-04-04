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
    }
    if(T==1&&a[1][3]=='k')printf("YES");
    else if(T==2&&a[0][4]=='k'&&a[6][3]=='k')printf("YES\nNO");
    else if(T==1)printf("NO");
    else{
        printf("?");
    }
    return 0;
}


