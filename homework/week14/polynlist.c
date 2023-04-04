#include <stdio.h>
#define max(a,b) (a > b ? a : b)
#define min(a,b) (a > b ? b : a)
void print(int a[], int n);
char variable[15];
int p1, p2;
int a[10005] = {0}, b[10005] = {0};
int add[10005] = {0}, sub[10005] = {0}, multi[20005] = {0};
int main(){
    scanf("%d%d%s",&p1,&p2,variable);
    for(int i = p1; i >= 0; i--){
        scanf("%d",&a[i]);
    }
    for(int i = p2; i >= 0; i--){
        scanf("%d",&b[i]);
    }
    for(int i = max(p1,p2); i >= 0; i--){
        add[i] = a[i] + b[i];
        sub[i] = a[i] - b[i];
    }
    for(int i = p1 + p2; i >= 0; i--){
        for(int j = min(i,p1); j >= 0 && (i-j) <= p2; j--){
            multi[i] = multi[i] + a[j] * b[i-j];
        }
    }
    print(add,max(p1,p2)); printf("\n");
    print(sub,max(p1,p2)); printf("\n");
    print(multi,p1+p2); printf("\n");
    return 0;
}
void print(int a[], int n){
    for(int i = n; i >= 0; i--){
        if(a[i]==0) continue;
        else if((a[i]==1||a[i]==-1) && i!=0){
            if(i!=1) printf("%s^%d",variable,i);
            else printf("%s",variable);
        }else{
            if(i!=0&&i!=1) printf("%d%s^%d",a[i],variable,i);
            else if(i==1) printf("%d%s",a[i],variable);
            else{
                printf("%d",a[0]);
                return;
            }
        }
        for(;a[i-1]==0&&i>0;i--);
        if(i==0) return;
        if(a[i-1]>0) printf("+");
        else if(a[i-1]==-1&&i!=1) printf("-");
    }
}
