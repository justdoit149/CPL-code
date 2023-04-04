#include <stdio.h>
typedef struct{
    char Name[25];
    char name[11][25];
    int score[12][3];
    
}Team;
Team teams[1005];
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        scanf("%s",teams[i].Name);
        for(int j = 0; j < 11; j++){
            scanf("%s%d%d%d",teams[i].name[j],&teams[i].score[j][0],&teams[i].score[j][1],&teams[i].score[j][2]);
        }
        teams[i].score[11][0] = teams[i].score[11][1] = teams[i].score[11][2] = 0;
        for(int j = 0; j < 11; j++){
            teams[i].score[11][0] += teams[i].score[j][0];
            teams[i].score[11][1] += teams[i].score[j][1];
            teams[i].score[11][2] += teams[i].score[j][2];
        }
    }
    for(int i = 0; i < n; i++){
        int index = 0;
        for(int j = 0; j < n; j++){
            if(teams[j].score[11][0] > teams[index].score[11][0]){
                index = j;
            }
        }
        teams[index].score[11][0] = -1;
        printf("%s ",teams[index].Name);
    }
    printf("\n");
    for(int i = 0; i < n; i++){
        int index = 0;
        for(int j = 0; j < n; j++){
            if(teams[j].score[11][1] > teams[index].score[11][1]){
                index = j;
            }
        }
        teams[index].score[11][1] = -1;        
        printf("%s ",teams[index].Name);
    }
    printf("\n");
    for(int i = 0; i < n; i++){
        int index = 0;
        for(int j = 0; j < n; j++){
            if(teams[j].score[11][2] > teams[index].score[11][2]){
                index = j;
            }
        }
        teams[index].score[11][2] = -1;
        printf("%s ",teams[index].Name);
    }
    return 0;
}