#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
#include<assert.h>
typedef struct token{
    int type;
    char str[32];//str从0开始存    tokens也是从0开始存
}Token;//type==1 变量；  type==2 整数；  type==3 运算符；  type==4 浮点数
Token tokens[1024];

typedef struct value {
    enum {
    INT,DOUBLE,ERROR
    } type;
    union {
    int iVal;
    double fVal;
    } val;
} Value;
Value val1,val2;

typedef struct assignment{
    char name[32];
    Value val;
}Assignment;
Assignment assignments[1005];//记录变量和对应的值
int varslen=0;//指示存了多少个变量

int token_analysis(Token tokens[],char shizi[]);//词法分析
bool check_parentheses(int l,int r);//是否为括号表达式
bool check_minus(int l,int r);//是否需要解引用负号
Value eval(int l,int r);//表达式求值
int findop(int l,int r);//寻找主运算符
void printfValue(Value v);//输出函数
Value evalassign(int l,int r);//是否有等号
Value meetvalue(Value v1,Value v2,char op);//转化成相同的类型并且求值
long long int INTnum(int n);//求整数
double DOUBLEnum(int n);//求浮点数


long long int INTnum(int n){
    long long int x=0;
    int s[32];
    char str1[32];
    strcpy(str1,tokens[n].str);
    int len=strlen(str1);
    for(int k=0;k<len;k++){
        s[k]=str1[k]-48;
        x+=pow(10,len-1-k)*s[k];
    }
    return x;
}

double DOUBLEnum(int n){
    double s[32],x=0;
    char str2[32];
    strcpy(str2,tokens[n].str);
    int len=strlen(str2);
    int k=0,index=0;
    while(k<len){
        if(str2[k]=='.'){
            break;
        }
        k++;
        index++;
    }
    int h=0;
    while(h<index){
        x=x*10+((int)str2[h]-48);
        h++;
    }
    h++;
    int j=0;
    while(h<len){
        j--;
        double num=pow(10,j);
        x+=((int)str2[h]-48)*num;
        h++;
    }
    return x;
}

bool check_parentheses(int l, int r){
    if(tokens[l].str[0] != '(' || tokens[r].str[0] != ')'){
        return false;
    }else{
        int check = 0;
        for(int i = l + 1; i < r; i++){
            if(tokens[i].str[0] == '('){
                check++;
            }else if(tokens[i].str[0] == ')'){
                check--;
            }
            if(check < 0){
                return false;
            }
        }
        if(check>=0){
            return true;
        }
    }
}

bool check_minus(int l, int r)
{
    if(tokens[l].str[0]!='-'){
        return false;
    }
    else{
        int kuohao=0;
        int op=0;//0表示没找到 1表示加减 2表示乘除
        int total=0;//判断op==2时括号外是否有加减
        for(int w=l;w<=r;w++){
            if(tokens[w].type!=3){;}//非运算符的token不是主运算符
            else if(tokens[w].str[0]=='('||tokens[w].str[0]==')'||tokens[w].str[0]=='='){;}//括号等号不是主运算符
            else{
                if(tokens[w].str[0]=='('){
                    kuohao++;
                }
                else if(tokens[w].str[0]==')'){
                    kuohao--;
                }
                if(kuohao==0){
                    if(tokens[w].str[0]=='+'){
                    op=1;
                    total=1;
                    }
                    else if(tokens[w].str[0]=='-'&&(w!=l)&&(tokens[w-1].type==1||tokens[w-1].type==2||tokens[w-1].type==4||tokens[w-1].str[0]==')')){
                        //减号和负号互斥 减号有以下两种情况 1.前一个token是数字或变量 2.前一个token是右括号
                        op=1;
                        total=1;
                    }
                    else if(tokens[w].str[0]=='*'||tokens[w].str[0]=='/'){
                    op=2;
                    }
                }   
            }
        }
        if(op!=0){
            return false;
        }
        else{
            return true;
        }

    }
    return false;
}

int findop(int l,int r){
    int kuohao=0;//kuohao为0时碰到的运算符即没有被括号包含的运算符
    int op=0;//0表示没找到 1表示加减 2表示乘除
    int total=0;//判断op==2时括号外是否有加减
    int index1=0;//存op=1时的位置
    int index2=0;//存op=2时的位置
    for(int w=l;w<=r;w++){
        if(tokens[w].type!=3){;}//非运算符的token不是主运算符
        else if(tokens[w].str[0]=='='){;}//等号不是主运算符
        else{
            if(tokens[w].str[0]=='('){
                kuohao++;
            }
            else if(tokens[w].str[0]==')'){
                kuohao--;
            }
            if(kuohao==0){
                if(tokens[w].str[0]=='+'){
                    op=1;
                    total=1;
                    index1=w;
                }
                else if(tokens[w].str[0]=='-'&&(w-1>=l&&(tokens[w-1].str[0]!='+'&&tokens[w-1].str[0]!='-'&&tokens[w-1].str[0]!='*'&& tokens[w-1].str[0]!='/'))){
                    op=1;
                    total=1;
                    index1=w;
                }
                else if(tokens[w].str[0]=='*'||tokens[w].str[0]=='/'){
                    op=2;
                    index2=w;
                }
            }
        }
    }
    if(op==1){
        return index1;
    }
    else if(op==2){
        if(total==1){
            return index1;
        }
        else if(total==0){
            return index2;
        }
    }
    


}

Value evalassign(int l,int r){
    Value x;
    x.type=ERROR;//用于返回error
    int judge=0;
    int flag=0;
    int k=0;//k是assignments的下标
    for(int i=l;i<=r;i++){
        if(tokens[i].str[0]=='='){
            judge=1;
            flag=i;//记录第一个等号出现的位置
            break;
        }
    }

    int indexequal = -1;
        int kuohao=0;
        for(int i=l;i<=r;i++){
            if(tokens[i].str[0]=='(') kuohao++;
            if(tokens[i].str[0]==')') kuohao--;
            if(tokens[i].str[0]=='='&&kuohao == 0){
                indexequal = i;
                break;
            }
        }

    if(judge==0){
        return eval(l,r);
    }
    else if(indexequal==-1){
        return eval(l,r);
    }
    else if(judge==1){//有等号
        if(tokens[flag-1].type==1&&flag==l+1){//感觉这个可以是唯一成立条件
            int yw = 0;
   for (int i = 1; i <= varslen; i++) {
    if (strcmp(assignments[i].name, tokens[flag - 1].str) == 0) {
     yw = 1;
     if (evalassign(flag + 1, r).type != ERROR)
      assignments[i].val = evalassign(flag + 1, r);
     break;
    }
   }
   
   if (yw == 0 && evalassign(flag + 1, r).type != ERROR) {
    varslen++;
    strcpy(assignments[varslen].name,tokens[flag-1].str);//从tokens.str字符串中读出%s格式的数据储存到var.name里
    assignments[varslen].val = evalassign(flag + 1, r);
    
   }
            return evalassign(flag+1,r);
        }
        else{
            return x;
        }
    }
}

Value meetvalue(Value v1,Value v2,char op){
    Value x;
    if(v1.type==ERROR||v2.type==ERROR){//error error
        x.type=ERROR;
        return x;
    }
    if(v1.type!=v2.type){//两个类型不一样，其中某一个需要类型提升 某一个的int转为double
        if(v1.type==INT){//此时v1 int v2 double
            v1.type=DOUBLE;
            v1.val.fVal=v1.val.iVal;
        }
        else if(v1.type==DOUBLE){//此时v1 double v2 int
            v2.type=DOUBLE;
            v2.val.fVal=v2.val.iVal;
        }
    }
    if(v1.type==INT&&v2.type==INT){//两个类型都一样都是int 没有经过类型提升
        x.type=INT;
        switch(op){
            case'+':x.val.iVal=v1.val.iVal+v2.val.iVal;break;
            case'-':x.val.iVal=v1.val.iVal-v2.val.iVal;break;
            case'*':x.val.iVal=v1.val.iVal*v2.val.iVal;break;
            case'/':x.val.iVal=v1.val.iVal/v2.val.iVal;break;
            default:assert(0);
        }
        return x;
    }
    else if(v1.type==DOUBLE&&v2.type==DOUBLE){//两个类型都是double
        x.type=DOUBLE;
        switch(op){
            case'+':x.val.fVal=v1.val.fVal+v2.val.fVal;break;
            case'-':x.val.fVal=v1.val.fVal-v2.val.fVal;break;
            case'*':x.val.fVal=v1.val.fVal*v2.val.fVal;break;
            case'/':x.val.fVal=v1.val.fVal/v2.val.fVal;break;
            default:assert(0);
        }
        return x;
    }
}

Value eval(int l, int r)
{
    Value x;
    if(l>r){//不合法的情况
        x.type=ERROR;
        return x;
    }
    else if(l==r){
        //整数
        if(tokens[l].type==2){
            x.type=INT;
            x.val.iVal=INTnum(l);
        }
        //浮点数
        else if(tokens[l].type==4){
            x.type=DOUBLE;
            x.val.fVal=DOUBLEnum(l);
        }
        //运算符
        else if(tokens[l].type==3){
            x.type=ERROR;
        }
        //变量
        else if(tokens[l].type==1){//例如出现a+2这种情况 查询a是否有被赋值
            for(int i=1; i<=varslen; i++) {
                if(strcmp(assignments[i].name, tokens[l].str) == 0) return assignments[i].val;
                else{
                    x.type=ERROR;
                }
            }
            
        }
        return x;
    }
    else if(check_parentheses(l,r)==true){
        return evalassign(l+1,r-1);
    }
    //处理负号
    else if(check_minus(l,r)){
        Value m=evalassign(l+1,r);
        if(m.type == INT) {
            int temp=m.val.iVal;
            temp=-temp;
            m.val.iVal=temp;
        }
        else if(m.type==DOUBLE){
            double temp=m.val.fVal;
            temp=-temp;
            m.val.fVal=temp;
        }
        return m;
    }
    //寻找主运算符 进行下一个递归
    else{
        int op;
        op=findop(l,r);
        //printf("%d",op);
        Value val1,val2;
        val1=evalassign(l,op-1);
        val2=evalassign(op+1,r);
        
        return meetvalue(val1,val2,tokens[op].str[0]);
        }
}

int token_analysis(Token tokens[],char shizi[]){
    int index=0,i=0,j=0;//token的长度是i-j;
        //处理
        analysis:
        while(shizi[i]!='\0'){
            for(;shizi[j+1]!=' '&&shizi[j+1]!='\0';j++);
            if(i==j){//运算符(不包含括号)
                if(shizi[i]=='+'||shizi[i]=='-'||shizi[i]=='*'||shizi[i]=='/'||shizi[i]=='('||shizi[i]==')'||shizi[i]=='='){
                    tokens[index].type=3;
                    tokens[index].str[0]=shizi[i];
                }else if((shizi[i]>='A'&&shizi[i]<='Z')||(shizi[i]>='a'&&shizi[i]<='z')||shizi[i]=='_'){//一位变量
                    tokens[index].type=1;
                    tokens[index].str[0]=shizi[i];
                }else if(shizi[i]>='0'&&shizi[i]<='9'){//一位整数
                    tokens[index].type=2;
                    tokens[index].str[0]=shizi[i];
                }else{
                    printf("Error\n");
                    return 0;
                }
                index++;
                i=i+2;
                j=i;
                goto analysis;
            }else if(shizi[i]<='9'&&shizi[i]>='0'){//浮点数、整数
                int count=0;
                for(int w=i;w<=j;w++){
                    if(shizi[w]=='.'){
                        count++;
                    }
                }
                if(count==0){
                    int counterror = 0;
                    for(int w=i;w<=j;w++){
                        if(shizi[w]<'0'||shizi[w]>'9') counterror++;
                    }
                    if(counterror==0&&shizi[i]!='0'){
                        tokens[index].type=2;
                        for(int w=i;w<=j;w++){    
                            tokens[index].str[w-i]=shizi[w];
                        }
                    }else{
                        printf("Error\n");
                        return 0;
                    }
                }else if(count==1 && shizi[i]!='.' && shizi[j]!='.'){
                    if(shizi[i+1]!='.'){
                        if(shizi[i]=='0'){
                            printf("Error\n");
                            return 0;
                        }
                    }
                    int counterror = 0;
                    for(int w=i;w<=j;w++){
                        if(shizi[w]<'0'||shizi[w]>'9') counterror++;
                    }
                    if(counterror==1){
                        tokens[index].type=4;
                        for(int w=i;w<=j;w++){    
                            tokens[index].str[w-i]=shizi[w];
                        }
                    }else{
                        printf("Error\n");
                        return 0;
                    }
                }else{
                    printf("Error\n");
                    return 0;
                }
                index++;
                i=j+2;
                j=i;
                goto analysis;
            }else if(((shizi[i]>='A'&&shizi[i]<='Z')||(shizi[i]>='a'&&shizi[i]<='z')||shizi[i]=='_')){//变量
                for(int w=i;w<=j;w++){
                    if((shizi[w]>='A'&&shizi[w]<='Z')||(shizi[w]>='a'&&shizi[w]<='z')||shizi[w]=='_'||(shizi[w]>='0'&&shizi[w]<='9')){;}
                    else{
                        printf("Error\n");
                        return 0;
                    }
                }
                for(int w=i;w<=j;w++){
                    tokens[index].type=1;
                    tokens[index].str[w-i]=shizi[w];
                }
                index++;
                i=j+2;
                j=i;
                goto analysis;
            }else{
                printf("Error\n");
                return 0;
            } 
        }
        return index;
}

void printfValue(Value v){
    if(v.type==ERROR){
        printf("Error\n");
    }
    else if(v.type==INT){
        printf("%d\n",v.val.iVal);
    }
    else if(v.type==DOUBLE){
        printf("%.6lf\n",v.val.fVal);
    }
}

int main()
{
    char shizi[10000];
    for(int i = 0; i < 10000; i++){
        shizi[i] = '\0';
    }
    for(int i = 0; i < 1024; i++){
        tokens[i].type = 0;
        for(int j = 0; j < 32; j++){
            tokens[i].str[j] = '\0';
        }
    }
    while(gets(shizi)!=NULL)
    {
        int len=token_analysis(tokens,shizi);
        //词法分析，返回len为一行中tokens的数目（如 2 + a - 3.4 返回5），具体token的内容已经存入了tokens结构体数组
        
        // for(int i=0;i<len;i++){
        //     printf("%d %s\n",tokens[i].type,tokens[i].str);
        // }（词法分析测试用）

        //语法分析、表达式求值
        if(len==0){//词法错误
            return 0;
        }
        Value v=evalassign(0,len-1);
        printfValue(v);

        //一行处理完后，清空shizi和tokens
        for(int i = 0; shizi[i] != '\0'; i++){
            shizi[i] = '\0';
        }
        for(int i = 0; tokens[i].type != 0; i++){
            tokens[i].type = 0;
            for(int j = 0; j < 32; j++){
                tokens[i].str[j] = '\0';
            }
        }
    }
    return 0;
}