#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    char *command_name=malloc(1280*sizeof(char));//文件名
    char *rule=malloc(1280*sizeof(char));//解析规则
    char *command=malloc(10240*sizeof(char));//命令
    char *command2=malloc(10240*sizeof(char));
    char *rule_explain1=malloc(1280*sizeof(char));//存规则中的参数
    char *rule_explain2=malloc(1280*sizeof(char));//存规则中的有值的参数
    char *option=malloc(10240*sizeof(char));//存命令中直接解析的参数
    char *result=malloc(10240*sizeof(char));//result存输出的值
    int index=0;//标记是否需要值 index=1是意为需要值
    memset(command_name,0,1280);memset(rule,0,1280);memset(command,0,10240);memset(command2,0,10240);
    memset(rule_explain1,0,1280);memset(rule_explain2,0,1280);memset(option,0,10240);memset(result,0,10240);
    scanf("%s",rule);
    int len_rule=strlen(rule);
    int a=0,b=0;
    for(int i=0;i<len_rule;i++){
        if(*(rule+i+1)!=':'){
            *(rule_explain1+a)=*(rule+i);//len rule_explain1=a
            a++;
        }else{
            *(rule_explain2+b)=*(rule+i);//len rule_explain2=b
            b++; i++;
        }
    }   
    int k=1;
    int m=0,n=0;
    int w=0;//result的下标
    int cc=0;//name的下标
    step:
    memset(command,0,10240);memset(command2,0,10240);


    while(scanf("%s",command)!=EOF){
        if(k==1){
            for(int crazy=0;*(command+crazy)!='\0';crazy++,cc++){
                *(command_name+cc)=*(command+crazy);//储存文件名
            }
            k++;
            goto step;
        }else{
            if(*command=='-'){ 
                *(option+m)=*(command+1);//用option把待解析的参数存起来
                for(int j=0;j<a;j++){ 
                    if(*(option+m)==*(rule_explain1+j)){
                        *(result+w)=*(option+m);
                        *(result+w+1)='\n';
                        w=w+2;
                        m++;
                        goto step;
                    }
                }//跟explain1匹配
                for(int i=0;i<b;i++)//跟explain2匹配
                {
                    if(*(option+m)==*(rule_explain2+i))
                    {
                        *(result+w)=*(option+m);
                        *(result+w+1)='=';
                        w=w+2;
                        if(scanf("%s",command2)!=EOF){
                            for(int sb=0;*(command2+sb)!='\0';sb++)
                            {
                                *(result+w)=*(command2+sb);
                                w++;
                            }
                            *(result+w)='\n';
                            m++;
                            w++;
                            goto step;
                        }else{
                            printf("%s: option requires an argument -- '%c'",command_name,*(option+m));
                            return 0;                            
                        }//需要值的参数没有值
                    }
                }
                printf("%s: invalid option -- '%c'",command_name,*(option+m));//出现规则里未定义的参数
                return 0;
            }else{
                goto step;
            }
        }
        memset(command,0,10240);memset(command2,0,10240);
    }
    printf("%s\n%s",command_name,result);
    return 0;
}