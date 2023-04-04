//思路：逐个符号读入字符串（push），能配对则弹出（pop），最终若栈为空则合法，若非空则不合法。
#include <stdio.h>
#include <stdbool.h>
#define LEN 30
#define WIDE 101

int main(){
    int T;
    bool a[30] = {0};
    char b[LEN][WIDE], c[LEN][WIDE];
    scanf("%d",&T);
    getchar();
    for(int i = 0; i < LEN; i++){
        for(int j = 0; j < WIDE; j++){
            b[i][j] = '\0';
            c[i][j] = '\0';
        }
    }
    for(int i = 0; i < T; i++){
        gets(b[i]);
    }
    for(int i = 0; i < T; i++){
        int index = -1;
        for(int j = 0; b[i][j] != '\0'; j++){
            if((b[i][j] == ')' && c[i][index] == '(')
             ||(b[i][j] == ']' && c[i][index] == '[')
             ||(b[i][j] == '}' && c[i][index] == '{')){
                index--;
            }else{
                index++;
                c[i][index] = b[i][j];
            }
        }
        if(index == -1){
            a[i] = 1;
        }
    }
    for(int i = 0; i < T; i++){
        if(a[i] == 0){
            printf("False\n");
        }else{
            printf("True\n");
        }
    }
    return 0;
}