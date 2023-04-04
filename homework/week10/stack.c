#include <stdio.h>
#define LEN 101

int main(){
    int n, index = -1;
    char a[LEN], b[LEN][7];
    for(int i = 0; i < LEN; i++){
        for(int j = 0; j < 7; j++){
            b[i][j] = '\0';
        }
    }
    for(int i = 0; i < LEN; i++){
        a[i] = '\0';
    }
    scanf("%d",&n);
    getchar();
    for(int i = 0; i < n; i++){
        gets(b[i]);
    }
    for(int i = 0; i < n; i++){
        if(b[i][0] == 'p' && b[i][1] == 'o' && b[i][2] == 'p'){
            if(index == -1){
                printf("Empty\n");
            }else{
                index--;
            }
        }else if(b[i][0] == 't' && b[i][1] == 'o' && b[i][2] == 'p'){
            if(index == -1){
                printf("Empty\n");
            }else{
                printf("%c\n",a[index]);
            }
        }else if(b[i][0] == 'p' && b[i][1] == 'r' && b[i][2] == 'i'){
            if(index == -1){
                printf("Empty\n");
            }else{
                for(int j = index; j >= 0; j--){
                    printf("| %c |\n",a[j]);
                }
                printf("|===|\n");
            }
        }else{
            index++;
            a[index] = b[i][5];
        }
    }
}