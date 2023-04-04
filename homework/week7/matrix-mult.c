#include <stdio.h>

int main()
{
    int A[100][100] = {0} , B[100][100] = {0} , C[100][100] = {0};
    int m,n,p;

    scanf("%d%d%d",&m,&n,&p);

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            scanf("%d",&A[i][j]);
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < p; j++){
            scanf("%d",&B[i][j]);
        }
    }
//输入A、B

    for(int i = 0; i < m; i++){
        for(int j = 0; j < p; j++){
            int sum = 0;
            for(int k = 0; k < n; k++){
                sum = sum + A[i][k]*B[k][j];
            }
            C[i][j] = sum;
        }
    }
//计算C
    
    for(int i = 0; i < m; i++){
        for(int j = 0; j < p; j++){
            printf("%d ",C[i][j]);
        }
        printf("\n");
    }
//输出C

    return 0;
}