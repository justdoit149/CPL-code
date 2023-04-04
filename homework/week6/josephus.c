#include <stdio.h>

int main()
{
    int n,k,count = 0, num = 0,live = 1;
    scanf("%d%d",&n,&k);

    _Bool a[501]={0};
    int die = 0;
    
    while(die < n-1){
        while(a[count % n] == 0){                        
            if(num == k - 1){
            a[count % n] = 1;
            die++;
            num = -1;
            }
            count++;
            num++;
        }
        count++;
    }

    for(int i = 1; i < n; i++){
        if(a[i] == 0){
            live = i + 1;            
        }
    }
    printf("%d",live);

    return 0;
}