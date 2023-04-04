#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char *argv){
    int error = 0, index = 0;//如果匹配不上，就把error变为1,把errorx变为匹配不上的字符
    char errorx = '\0';
    char *rule = malloc(128);
    char *name = malloc(128);
    char *s = malloc(128);
    char *s1 = malloc(128);
    char *result = malloc(5000);
    for(int i = 0; i < 128; i++){
        *(rule + i) = '\0';
        *(name + i) = '\0';
        *(s + i) = '\0';
        *(s1 + i) = '\0';
    }
    for(int i = 0; i < 5000; i++){
        *(result + i) = '\0';
    }

    scanf("%s%s",rule,name);
    for(index = 0; *(name + index) != '\0'; index++){
        *(result + index) = *(name + index);
    }
    *(result + index) = '\n';
    index++;
    while(scanf("%s",s) != EOF){//边读取边处理的方法
        if(error == 1) continue;
        if(*s != '-');
        else if(strlen(s) != 2);
        else if((*(s + 1) > 'z' || *(s + 1) < 'a') && (*(s + 1) > 'Z' || *(s + 1) < 'A'));
        else{
            int len = strlen(rule);
            for(int i = 0; i < len; i++){
                if(*(s + 1) == *(rule + i)){
                    if(*(rule + i + 1) != ':'){
                        *(result + index) = *(rule + i);
                        *(result + index + 1) = '\n';
                        index = index + 2;
                        goto finish;
                    }else{
                        *(result + index) = *(rule + i);
                        *(result + index + 1) = '=';
                        index = index + 2;
                        if(scanf("%s",s1) != EOF){
                            for(int j = 0; *(s1 + j) != '\0'; j++){
                                *(result + index) = *(s1 + j);
                                index++; 
                            }
                            *(result + index) = '\n';
                            index++;
                            goto finish;
                            //参数处理
                        }else{
                            printf("%s: option requires an argument -- '%c'",name,*(s + 1));
                            return 0;
                            //某个参数需要值但是缺少了,则一定到了末尾，直接结束。
                        }    
                    }
                }
            }
            error = 1;
            errorx = *(s + 1);
            finish:   
        }
        for(int i = 0; *(s + i) != '\0'; i++){
            *(s + i) = '\0';
            *(s1 + i) = '\0';
        }
    }
    if(error == 1){
        printf("%s: invalid option -- '%c'",name,errorx);
    }else{
        printf("%s",result);
    }
    
    return 0;
}