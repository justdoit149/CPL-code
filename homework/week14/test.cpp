#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 100005
struct haxi{
    struct haxi *next;
    char name[];
};
struct haxi *haxis[N];
struct haxi *first[N];
int m,q;
int hash(char *s);
int main(){
    scanf("%d%d",&m,&q);
    for(int i = 0; i < N; i++){
        first[i] = malloc(sizeof(struct haxi) + 16);
        haxis[i] = malloc(sizeof(struct haxi) + 16);
        //结构体中的动态数组对sizeof没有贡献（比如本题中有没有都是8）
        //所以，为了节省内存，可以sizeof + strlen + x(x为一个比较小的常数，本题取了16，留一定空间保证不会越界即可)
        first[i]->next = NULL;
        haxis[i]->next = NULL; 
        
    }
    for(int i = 0; i < m; i++){
        char s[1001];
        int index;
        scanf("%s",s);
        index = hash(s);
        haxis[index] = malloc(sizeof(struct haxi) + strlen(s) + 16);
        strcpy(haxis[index]->name,s);
        haxis[index]->next = first[index];
        first[index] = haxis[index];
    }
    for(int i = 0; i < q; i++){
        char s[1001];
        int index;
        scanf("%s",s);
        index = hash(s);
        for(struct haxi *p = haxis[index]; p->next != NULL; p = p->next){
            if(strcmp(p->name,s) == 0){
                printf("Yes\n");
                goto YES;
            }
        }
        printf("No\n");
        YES:
    }
    return 0;
}
int hash(char *s){
    int len=strlen(s);
    int ret=0;
    for(int i=0;i<len;i++)ret=(ret+s[i]*(i+1))%N;
    return ret;
}