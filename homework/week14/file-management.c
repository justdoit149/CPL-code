#include <stdio.h>
#include <string.h>

struct file{
    char name[15];
    char lastname[15];
    struct file *last;
    struct file *next1;
    struct file *next2;
};
struct file files[10005];
char func[505][2][15];
int find(struct file n);
int main(){
    int n,q,index_first,count;
    for(int i = 0; i < 10005; i++){
        files[i].last = files[i].next1 = files[i].next2 = NULL;
    }
 
    scanf("%d%d",&n,&q);
    for(int i = 0; i < n; i++){
        scanf("%s%s",files[i].name,files[i].lastname);
        if(files[i].lastname[0] == '~') index_first = i;
    }
    for(int i = 0; i < n; i++){
        if(i == index_first){
            files[i].last = NULL;
        }else{
            for(int j = 0; j < n; j++){
                if(strcmp(files[i].lastname,files[j].name)==0){
                    files[i].last = &files[j];  //两边都是指针，不能两边都是结构体！！
                    if(files[j].next1 == NULL){
                        files[j].next1 = &files[i];
                    }else{
                        files[j].next2 = &files[i];
                    }
                    break;
                }
            }
        }
    }
    for(int i = 0; i < q; i++){
        scanf("%s%s",func[i][0],func[i][1]);
        if(strcmp(func[i][0],"remove") == 0){
            for(int j = 0; j < n; j++){
                if(strcmp(func[i][1],files[j].name) == 0){
                    if((files[j].last->next1) == &files[j]){
                        files[j].last->next1 = NULL;
                    }else{
                        files[j].last->next2 = NULL;
                    }
                    break;
                }
            }
        }else{
            int index = 0;
            for(int j = 0; j < n; j++){
                if(strcmp(func[i][1],files[j].name) == 0){
                    index = j;
                    break; 
                }
            }
            count = find(files[index]);
            printf("%d\n",count);
        }
    }
    return 0;
}
int find(struct file n){
    if(n.next1 == NULL && n.next2 == NULL){
        return 1;
    }else if(n.next1 == NULL){
        return find(*n.next2) + 1;
    }else if(n.next2 == NULL){
        return find(*n.next1) + 1;
    }else{
        return find(*n.next2) + find(*n.next1) + 1;
    }
}