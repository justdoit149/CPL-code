#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define N 1005

int main(){
    int n;
    int a[N] = {0};
    int b[N] = {0};
    int group[N] = {0};
    int numgroup = 0;
    char func[10] = "\0\0\0\0\0\0\0\0\0";
    scanf("%d",&n);
    getchar();
    scanf("%s",func);
    for(int i = 1; i <= n; i++){
        scanf("%d",&a[i]);
    }
    for(int i = 1; i <= n; i++){
        if(a[i] == 0){
            continue;
        }else{
            int j = 0;
            if(a[i] == i){
                numgroup++;
                group[numgroup] = 1;
            }else{
                int k = i;
                for(;a[k] != 0; j++){
                    int temp = a[k];
                    a[k] = 0;
                    k = temp;                    
                }
                numgroup++;
                group[numgroup] = j;                
            }
        }
    }
    for(int i = numgroup; i > 1; i--){
        for(int j = 1; j < i; j++){
            if(group[j]>group[j+1]){
                group[j] ^= group[j+1] ^= group[j] ^= group[j+1];
            }
        }
    }
    if(strcmp(func,"number") == 0){
        printf("%d",numgroup);
    }else{
        for(int i = numgroup; i >= 1; i--){
            printf("%d ",group[i]);
        }
    }
    return 0;
}