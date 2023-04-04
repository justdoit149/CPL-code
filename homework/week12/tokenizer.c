#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define LEN 10005
int case1 = 0, case2 = 0;
int main(){
    char *reserved = malloc(16 * 10 * sizeof(char));
    char *operator = malloc(11 * 3 * sizeof(char));
    int *output = malloc(LEN * sizeof(int));
//输出，1表示保留字，2表示整数，3表示浮点数，4表示运算符，5表示变量，6换行,-1错误
    for(int i = 0; i < 16 * 10; i++){
        *(reserved + i) = '\0';
    }
    for(int i = 0; i < 11 * 3; i++){
        *(operator + i) = '\0';
    }
    for(int i = 0; i < LEN; i++){
        *(output + i) = 0;
    }
    strcpy(reserved + 0,"const");
    strcpy(reserved + 1 * 10,"int");
    strcpy(reserved + 2 * 10,"float");
    strcpy(reserved + 3 * 10,"double");
    strcpy(reserved + 4 * 10,"long");
    strcpy(reserved + 5 * 10,"static");
    strcpy(reserved + 6 * 10,"void");
    strcpy(reserved + 7 * 10,"char");
    strcpy(reserved + 8 * 10,"extern");
    strcpy(reserved + 9 * 10,"return");
    strcpy(reserved + 10 * 10,"break");
    strcpy(reserved + 11 * 10,"enum");
    strcpy(reserved + 12 * 10,"struct");
    strcpy(reserved + 13 * 10,"typedef");
    strcpy(reserved + 14 * 10,"union");
    strcpy(reserved + 15 * 10,"goto");
    strcpy(operator + 0,"+");
    strcpy(operator + 1 * 3,"-");
    strcpy(operator + 2 * 3,"*");
    strcpy(operator + 3 * 3,"/");
    strcpy(operator + 4 * 3,"=");
    strcpy(operator + 5 * 3,"==");
    strcpy(operator + 6 * 3,"!=");
    strcpy(operator + 7 * 3,">=");
    strcpy(operator + 8 * 3,"<=");
    strcpy(operator + 9 * 3,">");
    strcpy(operator + 10 * 3,"<");
//初始化保留字数组和运算符数组，便于后期比较。
    
    bool YON = 1;//1合法0不合法
    int index = 0;//下标，用于保存输出的数组
    char *s = malloc(100 * sizeof(char));//用于读取并暂时存储数据
    char *s1 = malloc(100 * sizeof(char));
    char *s2 = malloc(100 * sizeof(char));
    for(int i = 0; i < 100; i++){
        *(s + i) = '\0';
        *(s1 + i) = '\0';
        *(s2 + i) = '\0';
    }
    while (scanf("%s", s) != EOF){
        char *position = strchr(s, ';');   // if there's no ';' in s, it returns NULL.
        if (position == NULL){
            start:
            for(int i = 0; i < 16; i++){
                if(strcmp(s,reserved + i * 10) == 0){
                    *(output + index) = 1;
                    index++;
                    goto finish;
                }
            }
            //判断是否是保留字
            for(int i = 0; i < 11; i++){
                if(strcmp(s,operator + i * 3) == 0){
                    *(output + index) = 4;
                    index++;
                    goto finish;
                }
            }
            //判断是否是运算符
            for(int i = 0; *(s + i) != '\0'; i++){
                if(*(s + i) > '9' || *(s + i) < '0'){
                    goto NOTinteger;
                }
            }
            *(output + index) = 2;
            index++;
            goto finish;
            //判断是否是整数
            NOTinteger:
            int numfloat = 0;
            for(int i = 0; *(s + i) != '\0'; i++){
                if(*(s + i) == '.'){
                    numfloat++;
                }else if(*(s + i) > '9' || *(s + i) < '0'){
                    goto NOTfloat;
                }
            }
            if(numfloat == 1){
                *(output + index) = 3;
                index++;
                goto finish;
            }
            //判断是否是浮点数
            NOTfloat:
            if(*s <= '9' && *s >= '0'){
                YON = 0;
                *(output + index) = -1;
                index++;
            }else{
                for(int i = 0; *(s + i) != '\0'; i++){
                    if((*(s + i) != '_') 
                    && (*(s + i) > 'z' || *(s + i) < 'a')
                    && (*(s + i) > 'Z' || *(s + i) < 'A')
                    && (*(s + i) > '9' || *(s + i) < '0')){
                        YON = 0;
                        *(output + index) = -1;
                        index++;
                        goto finish;
                    }
                }
                *(output + index) = 5;
                index++;
            }
            //判断是否是变量。
            finish:
            if(case1 == 1){
                goto Case1;
            }else if(case2 == 2){
                goto Case2;
            }else if(case2 == 1){
                goto Case3;
            }
            
        //process(s);
        }else {
            if(*s == ';'){
                *(output + index) = 6;
                index++;
                //整个词只有一个分号
            }else{
                int place = 0;
                for(int i = 0; ; i++){
                    if(*(s + i) == ';'){
                        place = i;
                        break;
                    }
                }
                if(strlen(s) == place + 1){
                    case1 = 1;
                    *(s + place) = '\0';
                    goto start;
                    Case1:
                    case1 = 0;
                    *(output + index) = 6;
                    index++;
                    //词尾只有一个分号的情况
                }else{
                    case2 = 2;
                    for(int i = 0; i < place; i++){
                        *(s1 + i) = *(s + i); 
                    }
                    for(int i = 0; *(s + place + 1 + i) != '\0'; i++){
                        *(s2 + i) = *(s + place + 1 + i);
                    }
                    strcpy(s,s1);
                    goto start;
                    Case2:
                    *(output + index) = 6;
                    index++;
                    case2 = 1;
                    strcpy(s,s2);
                    goto start;
                    Case3:
                    case2 = 0;
                    //两个词中间只有一个分号的情况
                }
            }
        }
        for(int i = 0; i < 100; i++){
            *(s + i) = '\0';
            *(s1 + i) = '\0';
            *(s2 + i) = '\0';
        }
    }

    if(YON == 0){
        printf("Compile Error");
        return 0;
    }else{
        for(int i = 0; i < index; i++){
            switch(*(output + i)){
                case 1: printf("reserved ");break;
                case 2: printf("integer ");break;
                case 3: printf("float ");break;
                case 4: printf("operator ");break;
                case 5: printf("variable ");break;
                case 6: printf("\n");break;
                default: break;
            }
        }
    }

    return 0;
}