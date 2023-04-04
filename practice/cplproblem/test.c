#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node{
    enum{FILE_NODE,DIR_NODE} type;
    struct node *dirents;
    void *content;
    int nrde;
    int size;
    char *name;
} node;
node root;//
int location_now = 0;         //记录路径断点的位置（分为几段）
int location[100] = {0};  //记录路径断点的位置
char *path;            //复制路径字符串
void Path_Analysis(const char *b)
{
    int len = strlen(b);
    path = malloc(len + 5);
    strcpy(path, b);
    location_now = 0;
    for (int i = 0; i < len; i++)
    {
        if (path[i] == '/')
        {
            path[i] = '\0';
            if (path[i + 1] != '/' && i != (len - 1))
            {
                location[location_now] = i + 1;
                location_now++;
            }
        }
    }
}
int build(node *x,int now,char *a){
    if(now == (location_now - 1)){      //恰好是最后一个断点，如果存在则不需创建，不存在则创建
        for (int i = 0;i < x->nrde;i++){
            if(strcmp(a + location[now],x->dirents[i].name) == 0){
                return -1;
            }
        }
        x->dirents = realloc(x->dirents, (x->nrde + 1) * sizeof(node));
        x->dirents[x->nrde].type = DIR_NODE;
        x->dirents[x->nrde].name = malloc(sizeof(char) * (strlen(a + location[now]) + 1));
        strcpy(x->dirents[x->nrde].name, a + location[now]);
        x->dirents[x->nrde].nrde = 0;
        x->nrde = x->nrde + 1;
        return 0;
    }
    else if(now < (location_now - 1)){
        for (int j = 0;j < x->nrde;j++){
            if(strcmp(a + location[now],x->dirents[j].name) == 0){
                return build(x->dirents+j,now+1,a);
            }
        }
        return -1;
    }
}
int rmkdir(const char *pathname)
{
    Path_Analysis(pathname);
    return build(&root,0, path);
}
void init_ramfs()
{
    root.type = DIR_NODE;
    root.nrde = 0;
    root.name = malloc(sizeof(char));
    strcpy(root.name,"/");
}
int main()
{
    init_ramfs();
    printf("%d\n", rmkdir("/dir"));
    
    printf("%d\n", rmkdir("/dir/xx"));
    
}