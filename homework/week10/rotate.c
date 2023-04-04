#include <stdio.h>

int main(){
    int a,b,c;
    char move[1001];
    for(int i = 0; i < 1001; i++){
        move[i] = '\0';
    }
    scanf("%d%d%d",&a,&b,&c);
    getchar();
    scanf("%s",move);
    int x1 = 0, x2 = a, y1 = 0, y2 = b;

    for(int i = 0; move[i] != '\0'; i++){
        if(move[i] == 'W'){
            x2 = x1;
            x1 = x1 - c;
            a ^= c ^= a ^= c;
        }else if(move[i] == 'S'){
            x1 = x2;
            x2 = x2 + c;
            a ^= c ^= a ^= c;
        }else if(move[i] == 'A'){
            y2 = y1;
            y1 = y1 - c;
            b ^= c ^= b ^= c;
        }else if(move[i] == 'D'){
            y1 = y2;
            y2 = y2 + c;
            b ^= c ^= b ^= c;
        }
    }
    printf("%d %d %d %d",x1,x2,y1,y2);
    return 0;
}