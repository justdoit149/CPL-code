#include <stdio.h>
#include <stdbool.h>

int main(){
    int n,m,k,sum = 0;
    int dmg[10000] = {0}, Dmg[10000] = {0};
    bool type[10000] = {0};
    
    scanf("%d%d%d",&n,&m,&k);
    for(int i = 0; i < n; i++){
        scanf("%d%d",&dmg[i],&type[i]);
        Dmg[i] = dmg[i] + type[i] * m * dmg[i];
    }
    for(int i = k; i < n; i++){
        for(int j = 0; j < k; j++){
            if(Dmg[j] < Dmg[i]){
                int temp = Dmg[j];
                Dmg[j] = Dmg[i];
                Dmg[i] = temp;
            }
        }
    }
    for(int i = 0; i < k; i++){
        sum = sum + Dmg[i];
    }
    printf("%d",sum);

    return 0;
}