#include <stdio.h>

int main(){
    int n,L;
    int money = 0, V = 0, index = 0; 
    //money统计钱数，V统计体积,index为最贵的的下标
    int v[10008] = {0},w[10008] = {0};
    scanf("%d%d",&n,&L);
    for(int i = 0; i < n; i++){
        scanf("%d",&v[i]); 
    }
    for(int i = 0; i < n; i++){
        scanf("%d",&w[i]);
    }
    while(L > 0){
        for(int i = 0; i < n; i++){
            if(v[i] >= v[index]){
                index = i;
            }
        }
        if(L - w[index] > 0){
            money = money + v[index] * w[index];
            L = L - w[index];
            v[index] = 0;
        }else{
            money = money + v[index] * L;
            printf("%d",money);
            return 0;
        }
    }
}