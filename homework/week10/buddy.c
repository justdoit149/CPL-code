#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#define LEN 101
int size0(int n);
void fenhua(int K,int Sum);
int n,q,sum = 1;
int id[LEN] = {0}, size[LEN] = {0};
int lian[2 * LEN][2] = {0};
bool doing[LEN] = {0};

int main(){
    scanf("%d%d",&n,&q);
    getchar();
    lian[0][0] = n, lian[0][1] = 0;
    for(int i = 1; i < 2 * LEN; i++){
        lian[i][0] = -1;
    }
    for(int i = 0,j = 0; i < q; i++){
        if(getchar() == 'Q'){
            doing[i] = 1;
        }else{
            scanf("%d%d",&id[j],&size[j]);
            size[j] = size0(size[j]);
            j++;
        }
        getchar();
    }
    //到此为止，获取并存储了所有信息
    //其中，doing数组存储操作。1为Q，0为A
    //对于A操作，用id数组存储id，用size数组存储分配内存的大小（已经用size0函数将其转化为2的幂次数）。
    //lian数组存储链表，第一个参数表示大小(>=0的才是已经分配的,-1未分配)，第二个参数表示id（0表示未用）
    for(int i = 0, k = 0; i < q; i++){
        if(doing[i] == 1){
            printf("%d\n",sum);           
            for(int j = 0; j < sum; j++){
                printf("%d ",lian[j][1]);
            }
            printf("\n");
        }else{
             fenhua(k,sum);
             k++;
        }
    }
    return 0;
}

int size0(int n){
    for(int i = -1; i < 31; i++){
        if(pow(2,i) < n && pow(2,i+1) >= n) return i+1;
    }
}
void fenhua(int K,int Sum){
    for(int i = 0; i < Sum; i++){
        if(lian[i][0] == size[K] && lian[i][1] == 0){
            lian[i][1] = id[K];
            return;
        }
    }
    //如果现存的有大小合适的free状态的，就直接存在这里然后返回
    for(int i = 0; i < Sum; i++){
        if(lian[i][0] > size[K] && lian[i][1] == 0){
            for(int j = Sum - 1; j > i ; j--){
                lian[j+1][0] = lian[j][0];
                lian[j+1][1] = lian[j][1];
            }
            lian[i][0]--;
            lian[i+1][0] = lian[i][0];
            lian[i+1][1] = 0;
            sum++;Sum++;
            fenhua(K,Sum);
            return;
        }
    }
    //若是没有，则先找到最前面、大于size[k]、且free的，然后划分(后面的全往后挪1位，k--,sum++)
}//这个函数完成分划操作