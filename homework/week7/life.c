#include <stdio.h>

int main()
{
    int n;
    char a[1010],b[1010],c[1010];
    for(int i = 0; i < 1010; i++){
        a[i] = '\0';
        b[i] = '\0';
        c[i] = '\0';
    }

    scanf("%d",&n);
    getchar();
    scanf("%s",a);

    for(int i = 0; a[i] != '\0'; i++){
        b[i + 3] = a[i];
    }
    
    for(int i = 0; i < n; i++){//n次操作
        for(int j = 3; b[j] != '\0'; j++){//某一次操作
            int countA = 0, countB = 0;
            for(int x = j - 3; x <= j + 3; x++){
                        countA = countA + (b[x] == 'A' && x != j);
                        countB = countB + (b[x] == 'B' && x != j);
            }
            if(b[j] != '.'){//有生命
                if(b[j]=='A' && countB==0 && countA>=2 && countA<=4) c[j] = 'A';
                else if(b[j]=='B' && countA==0 && countB>=2 && countB<=4) c[j] = 'B';
                else c[j] = '.';      
            }else{//无生命
                if(countB==0&&countA>=2&&countA<=4) c[j] = 'A';
                else if(countA==0&&countB>=2&&countB<=4) c[j] = 'B';
                else c[j] = '.';
            }
        }
        for(int j = 3; c[j] != '\0'; j++) b[j] = c[j];
    }

    for(int i = 3; b[i] != '\0'; i++) printf("%c",b[i]);

    return 0;
}