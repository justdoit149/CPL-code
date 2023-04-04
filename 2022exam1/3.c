#include <stdio.h>
int num[705][705] = {0};
int ans[500000][2];
int n,m,d;
int Sum(int x);
int Sum2(int x,int y);
int main(){
    int sum = 0, max = -1000000000, count = 0;
    scanf("%d%d%d",&n,&m,&d);
    for(int i = 51; i < n + 51; i++){
        for(int j = 51; j < m + 51; j++){
            scanf("%d",&num[i][j]);
        }
    }
    for(int i = 51; i < n + 51; i++){
        sum = Sum(i);
        if(sum>max){
            max = sum;
            count = 1;
            ans[0][0] = i - 50, ans[0][1] = 1;
        }else if(sum == max){
            ans[count][0] = i - 50, ans[count][1] = 1;
            count++;
        }
        for(int j = 52; j < m + 51; j++){
            sum = sum + Sum2(i,j);
            if(sum<max){
                continue;
            }else if(sum>max){
                max = sum;
                count = 1;
                ans[0][0] = i - 50, ans[0][1] = j - 50;
            }else{
                ans[count][0] = i - 50, ans[count][1] = j - 50;
                count++;
            }
        }
    }
    printf("%d %d\n",max,count);
    for(int i = 0; i < count; i++){
        printf("%d %d\n",ans[i][0],ans[i][1]);
    }
    return 0;
}
int Sum(int x){//x行.51列
    int s = 0;
    for(int i = x-d; i <= x; i++){
        for(int j = 51 + x - d - i; j <= 51 - x + d + i; j++) s = s + num[i][j];
    }
    for(int i = x+1; i <= x+d; i++){
        for(int j = 51 - x - d + i; j <= 51 + x + d - i; j++) s = s + num[i][j];
    }
    return s;
}
int Sum2(int x,int y){//x行.y列
    int s1 = 0,s2 = 0,s3 = 0,s4 = 0;
    int t1 = x + y - d - 1, t2 = y - d - 1 - x, t3 = y + d - x, t4 = x + y + d;
    for(int i = x - d; i <= x; i++) s1 = s1 + num[i][t1 - i];
    for(int i = x + 1; i <= x + d; i++) s2 = s2 + num[i][t2 + i];
    for(int i = x - d; i <= x; i++) s3 = s3 + num[i][t3 + i];
    for(int i = x + 1; i <= x + d; i++) s4 = s4 + num[i][t4 - i];
    return s4 + s3 - s2 - s1; 
}