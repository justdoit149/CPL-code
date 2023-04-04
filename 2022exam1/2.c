#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char a[100005],b[200005];
int c[105]; 
int main(){
    int T,n,count;
    scanf("%d",&T);
    for(int i = 0; i < T; i++){
        scanf("%d%s%s",&n,a,b);
        int index = 0;
        count = 0;
        for(int j = 0; j < 105; j++){
            c[j] = 0;
        }
        for(int j = 0; j < n; j++){
            if(a[j]=='?' && a[n-1-j]!='?'){
                a[j] = a[n-1-j];
            }
            if(a[j]=='?' && a[n-1-j]=='?'){
                count++;
            }
        }
        int len = strlen(b);
        if(len!=count+n){
            printf("Wrong Answer!\n");
            goto finish;
        }
        for(int j = 0; j < n; j++){
            if(a[j]!='?'){
                if(a[j] != b[index] || a[n-1-j] != b[len-1-index]){
                    printf("Wrong Answer!\n");
                    goto finish;
                }
                index++;
            }else{
                if(b[index]!=b[len-1-index]||b[index+1]!=b[len-2-index]){
                    printf("Wrong Answer!\n");
                    goto finish;
                }else if(b[index]>'9'||b[index]<'0'||b[index+1]>'9'||b[index+1]<'0'){
                    printf("Wrong Answer!\n");
                    goto finish;
                }
                int t = (b[index] - '0') * 10 + (b[index+1] - '0');
                if(c[t]==4){
                    printf("Wrong Answer!\n");
                    goto finish;
                }else if(c[t]==2&&(t==0||t==11||t==22||t==33||t==44||t==55||t==66||t==77||t==88||t==99)){
                    printf("Wrong Answer!\n");
                    goto finish;
                }
                c[t]++;
                index = index + 2;
            }
        }
        printf("Correct.\n");
        finish:
    }
    return 0;
}








