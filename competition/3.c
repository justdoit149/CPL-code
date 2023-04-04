#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int a[100][10] = {0};
int n,k;
bool YON(int a1,int a2,int a3,int a4,int a5);
int main(){
    scanf("%d%d",&n,&k);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < k; j++){
            scanf("%d",&a[i][j]);
        }
    }
    int num = 0;
    for(int m1 = 0; m1 < n - 4; m1++){
        for(int m2 = m1+1; m2 < n - 3; m2++){
            for(int m3 = m2+1; m3 < n - 2; m3++){
                for(int m4 = m3+1; m4 < n - 1; m4++){
                    for(int m5 = m4+1; m5 < n; m5++){
                        if(YON(m1,m2,m3,m4,m5) == 1){
                            num++;
                        }
                    }
                }
            }
        }
    }
    printf("%d",num);
    return 0;
}

bool YON(int a1,int a2,int a3,int a4,int a5){
    int count = 10;
    int x, y, z;
    x = a1, y = a2, z = a3;
    for(int i = 0; i < k; i++){
        if(a[x][i] == a[y][i] && a[x][i] == a[z][i]){
            continue;
        }else if(a[x][i] != a[y][i] && a[x][i] != a[z][i] & a[y][i] != a[z][i]){
            continue;
        }else{
            count--;
            break;
        }
    }
    x = a1, y = a2, z = a4;
    for(int i = 0; i < k; i++){
        if(a[x][i] == a[y][i] && a[x][i] == a[z][i]){
            continue;
        }else if(a[x][i] != a[y][i] && a[x][i] != a[z][i] & a[y][i] != a[z][i]){
            continue;
        }else{
            count--;
            break;
        }
    }
    x = a1, y = a2, z = a5;
    for(int i = 0; i < k; i++){
        if(a[x][i] == a[y][i] && a[x][i] == a[z][i]){
            continue;
        }else if(a[x][i] != a[y][i] && a[x][i] != a[z][i] & a[y][i] != a[z][i]){
            continue;
        }else{
            count--;
            break;
        }
    }
    x = a1, y = a3, z = a4;
    for(int i = 0; i < k; i++){
        if(a[x][i] == a[y][i] && a[x][i] == a[z][i]){
            continue;
        }else if(a[x][i] != a[y][i] && a[x][i] != a[z][i] & a[y][i] != a[z][i]){
            continue;
        }else{
            count--;
            break;
        }
    }
    x = a1, y = a3, z = a5;
    for(int i = 0; i < k; i++){
        if(a[x][i] == a[y][i] && a[x][i] == a[z][i]){
            continue;
        }else if(a[x][i] != a[y][i] && a[x][i] != a[z][i] & a[y][i] != a[z][i]){
            continue;
        }else{
            count--;
            break;
        }
    }
    x = a1, y = a4, z = a5;
    for(int i = 0; i < k; i++){
        if(a[x][i] == a[y][i] && a[x][i] == a[z][i]){
            continue;
        }else if(a[x][i] != a[y][i] && a[x][i] != a[z][i] & a[y][i] != a[z][i]){
            continue;
        }else{
            count--;
            break;
        }
    }
    x = a2, y = a3, z = a4;
    for(int i = 0; i < k; i++){
        if(a[x][i] == a[y][i] && a[x][i] == a[z][i]){
            continue;
        }else if(a[x][i] != a[y][i] && a[x][i] != a[z][i] & a[y][i] != a[z][i]){
            continue;
        }else{
            count--;
            break;
        }
    }
    x = a2, y = a3, z = a5;
    for(int i = 0; i < k; i++){
        if(a[x][i] == a[y][i] && a[x][i] == a[z][i]){
            continue;
        }else if(a[x][i] != a[y][i] && a[x][i] != a[z][i] & a[y][i] != a[z][i]){
            continue;
        }else{
            count--;
            break;
        }
    }
    x = a2, y = a4, z = a5;
    for(int i = 0; i < k; i++){
        if(a[x][i] == a[y][i] && a[x][i] == a[z][i]){
            continue;
        }else if(a[x][i] != a[y][i] && a[x][i] != a[z][i] & a[y][i] != a[z][i]){
            continue;
        }else{
            count--;
            break;
        }
    }
    x = a3, y = a4, z = a5;
    for(int i = 0; i < k; i++){
        if(a[x][i] == a[y][i] && a[x][i] == a[z][i]){
            continue;
        }else if(a[x][i] != a[y][i] && a[x][i] != a[z][i] & a[y][i] != a[z][i]){
            continue;
        }else{
            count--;
            break;
        }
    }
    if(count >= 2){
        return true;
    }else{
        return false;
    }
}