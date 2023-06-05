#include <stdio.h>

int l,n,q;
int nums[10000005];

int find(int q){
    int L = 1, R = l;
    int mid;
    while(L!=R){
        mid = (L+R) / 2;
        if(nums[mid] >= q){
            R = mid;
        }else{
            L = mid+1;
        }
    }
    return L;
}

int main(int argc, char const *argv[])
{
    scanf("%d",&l);
    for(int i = 1; i <= l; i++){
        scanf("%d",&nums[i]);
    }
    scanf("%d",&n);
    for(int i = 1; i <= n; i++){
        scanf("%d",&q);
        printf("%d\n",find(q)-1);
    }


    return 0;
}