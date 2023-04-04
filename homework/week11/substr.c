#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 100005
int main(){
    char *S = malloc(sizeof(char) * LEN);
    char *T = malloc(sizeof(char) * LEN);
    for(int i = 0; i < LEN; i++){
        *(S + i) = '\0';
        *(T + i) = '\0';
    }
    scanf("%s\n%s",S,T);
    for(int i = 0; i <= strlen(S) - strlen(T) ; i++){
        for(int j = 0; j < strlen(T); j++){
            if(*(S + i + j) != *(T + j)){
                goto fake;
            }
        }
        printf("%d ",i);
        fake:
        //goto的用法
        //用 xxx: 作为标签。
    }
    return 0;
}