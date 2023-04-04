#include <stdio.h>
#include <stdlib.h>

#define LEN 4100
int main(){
    char *sentence = malloc(sizeof(char) * LEN);
    for(int i = 0; i < LEN; i++){
        *(sentence + i) = '\0';
    }
    gets(sentence);
    for(int i = 0; *(sentence + i) != 0; i++){
        if(i == 0){
            if(*(sentence + i) > 95){
                *(sentence + i) = *(sentence + i) - 32;
            }
        }else{
            if(*(sentence + i - 1) == ' '){
                if(*(sentence + i) > 95){
                    *(sentence + i) = *(sentence + i) - 32;
                } 
            }else if(*(sentence + i) != ' '){
                if(*(sentence + i) < 95){
                    *(sentence + i) = *(sentence + i) + 32;
                }
            }
        }
    }
    printf("%s",sentence);
    return 0;
}