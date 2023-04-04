#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <assert.h>

typedef struct token {        
    int type;
    char str[32];
} Token;
//词法分析，并储存token //type == 1:整数 //type == 2:浮点数 //type == 3:运算符 //type == 4:变量 //str：储存token
typedef struct value {
    enum NumberType {
        DOUBLE, INT, ERROR
    } type;
    union {
        double fVal;
        int iVal;
    } val;
} Value;
typedef struct assignment {
    char name[32];
    enum Numbertype {
        DOUBLe, INt
    } type;
    union {
        double fVal;
        int iVal;
    } val;
} Assignment;//用于记录并储存变量的值

Token tokens[1050];
Assignment assignments[130];

bool check_parentheses(int l, int r);//是否是括号表达式
int ascii_num(char n);//把ascii转化为相应的整数(0-9)
long long int INTnum(int n);//求整数
double DOUBLEnum(int n);//求浮点数
int findop(int l,int r);//找主运算符
Value meetvalue(Value v1, Value v2, char op);//转化成相同的类型并求值
Value eval (int l,int r);//表达式求值
Value evalAssign(int l, int r);//是否有等号

int main(){
    char input[1050] = "\0";
    for(int i = 0; i < 1050; i++){
        tokens[i].type = 0;
        for(int j = 0; j < 32; j++){
            tokens[i].str[j] = '\0';
        }
    }
    for(int i = 0; i < 130; i++){
        for(int j = 0; j < 32; j++){
            assignments[i].name[j] = '\0';
        }
    }
    //初始化
    while (gets(input) != NULL){
        int index = 0;
        for (int i = 0; input[i] != '\0';){
            if (input[i] == ' '){
                i++;
            }else{
                int j = i;
                for (; input[j + 1] != ' ' && input[j + 1] != '\0'; j++);
                if(i == j && (input[i] == '+' || input[i] == '-' || input[i] == '*' 
                || input[i] == '/' || input[i] == '=' || input[i] == '(' || input[i] == ')')){
                    tokens[index].type = 3;
                    tokens[index].str[0] = input[i];//运算符                   
                }else if(i == j && input[i] >= '0' && input[i] <= '9'){
                    tokens[index].type = 1;
                    tokens[index].str[0] = input[i];//一位整数
                }else if(i == j && (input[i] == '_' || input[i] >= 'A' && input[i] <= 'Z' || input[i] >= 'a' && input[i] <= 'z')){
                    tokens[index].type = 4;
                    tokens[index].str[0] = input[i];//一位变量
                }else if(i == j){
                    printf("Error\n");
                    goto Error;//非法                    
                }else{
                    int numpoint = 0;
                    int numpoint_index = i;
                    for(int k = i; k <= j; k++){
                        if(input[k] == '.'){
                            numpoint++;
                            numpoint_index = k;
                        }
                    }//统计小数点个数                   
                    if(numpoint > 1){
                        printf("Error\n");
                        goto Error;//非法                       
                    }else if(numpoint == 1){
                        if(numpoint_index == i || numpoint_index == j){
                            printf("Error\n");
                            goto Error;//非法                         
                        }else if(numpoint_index - i >= 2 && input[i] == '0'){
                            printf("Error\n");
                            goto Error;//非法                            
                        }else{
                            int notnumber = 0;
                            for(int k = i; k <= j; k++){
                                if(input[k] > '9' || input[k] < '0'){
                                    notnumber++;
                                }
                            }
                            if(notnumber > 1){
                                printf("Error\n");
                                goto Error;//非法                                
                            }else{
                                tokens[index].type = 2;
                                for(int k = i; k <= j; k++){
                                    tokens[index].str[k-i] = input[k];
                                }
                            }
                        }
                    }else{
                        if(input[i] == '0'){
                            printf("Error\n");
                            goto Error;//非法                            
                        }else{
                            int number = 0, character = 0;
                            for(int k = i; k <= j; k++){
                                if(input[k] <= '9' && input[k] >= '0'){
                                    number++;
                                }
                                if(input[k] == '_' || input[k] >= 'A' && input[k] <= 'Z' || input[k] >= 'a' && input[k] <= 'z' || input[k] <= '9' && input[k] >= '0'){
                                    character++;
                                }
                            }
                            if(number == j - i + 1){
                                tokens[index].type = 1;
                                for(int k = i; k <= j; k++){
                                    tokens[index].str[k-i] = input[k];
                                }
                            }else if(input[i] <= '9' && input[i] >= '0'){
                                printf("Error\n");
                                goto Error;//非法                                
                            }else if(character == j - i + 1){
                                tokens[index].type = 4;
                                for(int k = i; k <= j; k++){
                                    tokens[index].str[k-i] = input[k];
                                }
                            }else{
                                printf("Error\n");
                                goto Error;//非法
                            }
                        }
                    }
                }
                i = j + 1;
                index++;
            }
        }
        //词法分析,这部分大概率没有问题
        Assignment assignments2[130];
        for(int i = 0; i < 130; i++){
            assignments2[i] = assignments[i];
        }

        Value x = evalAssign(0,index-1);
        //语法分析&&表达式求值

        if(x.type == ERROR){
            printf("Error\n");
            for(int i = 0; i < 130; i++){
            assignments[i] = assignments2[i];
            }
        }else if(x.type == INT){
            printf("%d\n",x.val.iVal);
        }else if(x.type == DOUBLE ){
            printf("%f\n",x.val.fVal);
        }
        //输出

Error:  {
        for(int i = 0; input[i] != '\0'; i++){
            input[i] = '\0';
        }
        for(int i = 0; i < index; i++){
            tokens[i].type = 0;
            for(int j = 0; j < 32; j++){
                tokens[i].str[j] = '\0';
            }
        }
        }
        //重置，应该也没有问题
    }
    return 0;
}



bool check_parentheses(int l, int r){
    if(tokens[l].str[0] != '(' || tokens[r].str[0] != ')'){
        return false;
    }else{
        int YON = 0;
        for(int i = l + 1; i < r; i++){
            if(tokens[i].str[0] == '('){
                YON++;
            }else if(tokens[i].str[0] == ')'){
                YON--;
            }
            if(YON < 0){
                return false;
            }
        }
        return true;
        //这里，如果YON > 0，也就是如 （3 + （3 + 3） 这种也被判断为true.
        //这种是肯定语法错误的，应当在eval函数中考虑到这种情况。 
    }
}
//看是不是括号表达式，这部分可能有问题

int ascii_num(char n){
    if(n >= '0' && n <= '9'){
        return (n - '0');
    }else{
        return n;
    }
}
//一个子函数，把单个的char型数字转化为int，应该没问题
long long int INTnum(int n){
    long long int m = ascii_num(tokens[n].str[0]);
    for(int i = 0; tokens[n].str[i+1] != '\0'; i++){
        m = 10 * m + ascii_num(tokens[n].str[i+1]);
    }
    return m;
}
//子函数，把字符串整数转化为int存储，应该没问题(?)
double DOUBLEnum(int n){
    int float_index = 1;//先找浮点
    for(;tokens[n].str[float_index] != '.'; float_index++);
    long long int m_int = ascii_num(tokens[n].str[0]);//再求整数部分
    for(int i = 1; i < float_index; i++){
        m_int = 10 * m_int + ascii_num(tokens[n].str[i]);
    }
    long long int m_double = ascii_num(tokens[n].str[float_index+1]);//然后求小数部分（先用整数表示），并统计小数点后有多少位
    int num_double = 1;
    for(int i = float_index + 2; tokens[n].str[i] != '\0'; i++, num_double++){
        m_double = 10 * m_double + ascii_num(tokens[n].str[i]);
    }
    return (m_int + m_double * 1.0 / pow(10,num_double));
}
//子函数，把字符串浮点数转化为int存储，可能有问题（0.11112222333344445555666677好像符合（不爆double），但是爆int）
//这样得分没提高，可能问题不在此处
int findop(int l,int r){//这个函数不需要考虑有等号的情形
    int kuohao = 0;//统计括号数，遇到左括号则增，右括号则减，若该变量大于0时那一定不是主运算符
                   //小于0无所谓，因为这一定是不合法的，可以在l==r && tokens[l].type == 3处判断。
    int index = l;
    int op = 0;    //0表示还没找到，1表示找到乘除，2表示找到加减
    for(int i = l; i <= r; i++){
        if(tokens[i].type != 3);
        else if(kuohao > 0 && tokens[i].str[0] != ')' && tokens[i].str[0] != '(');
        else{
            if(tokens[i].str[0] == '('){
                kuohao++;
            }else if(tokens[i].str[0] == ')'){
                kuohao--;
            }else{              
                if(op == 0){
                    index = i;
                    if(tokens[i].str[0] == '*' || tokens[i].str[0] == '/'){
                        op = 1;
                    }else{
                        op = 2;
                    }
                }else if(op == 1){
                    int k0 = 0;
                    for(int k = index+1; k <= i; k++){
                        if(tokens[k].str[0] != '+' && tokens[k].str[0] != '-'
                        && tokens[k].str[0] != '*' && tokens[k].str[0] != '/'){
                            k0++;
                        }
                    }
                    if(k0 == 0);
                    else if(tokens[i].str[0] == '*' || tokens[i].str[0] == '/'){
                        index = i;
                    }else{
                        op = 2;
                        index = i;
                    }
                }else{
                    int k0 = 0;
                    for(int k = index+1; k <= i; k++){
                        if(tokens[k].str[0] != '+' && tokens[k].str[0] != '-'
                        && tokens[k].str[0] != '*' && tokens[k].str[0] != '/'){
                            k0=1;
                        }
                    }
                    if(k0 == 0);
                    else if((tokens[i].str[0] == '+' || tokens[i].str[0] == '-') && 
                             tokens[i-1].str[0] != '*' && tokens[i-1].str[0] != '/' &&
                             tokens[i-1].str[0] != '+' && tokens[i-1].str[0] != '-'&& index != l){
                        index = i;
                    }else if(index == l){
                        if((tokens[i].str[0] == '+' || tokens[i].str[0] == '-')){
                            index = i; op = 2;
                        }else if((tokens[i].str[0] == '*' || tokens[i].str[0] == '/')){
                            index = i; op = 1;
                        }
                    }
                    
                }
            }
        }
    }
    return index;
}


//这个函数应该有问题，如果有等号的话主运算符要不要考虑等号呢
Value meetvalue(Value v1, Value v2, char op){
    Value x;
    if (v1.type == ERROR || v2.type == ERROR) {
        x.type = ERROR;
        return x;
    }
    if(v1.type != v2.type){//类型提升
        if(v1.type == INT){
            v1.type = DOUBLE;
            v1.val.fVal = v1.val.iVal;
        }else{
            v2.type = DOUBLE;
            v2.val.fVal = v2.val.iVal;
        }
    }
    if(v1.type == INT){
        x.type = INT;
        if(op == '+')x.val.iVal = v1.val.iVal + v2.val.iVal;
        else if(op == '-')x.val.iVal = v1.val.iVal - v2.val.iVal;
        else if(op == '*')x.val.iVal = v1.val.iVal * v2.val.iVal;
        else if(op == '/' && v2.val.iVal != 0) x.val.iVal = v1.val.iVal / v2.val.iVal;
        else assert(0);
        return x;
    }else{
        x.type = DOUBLE;
        if(op == '+')x.val.fVal = v1.val.fVal + v2.val.fVal;
        else if(op == '-')x.val.fVal = v1.val.fVal - v2.val.fVal;
        else if(op == '*')x.val.fVal = v1.val.fVal * v2.val.fVal;
        else if(op == '/' && v2.val.fVal != 0)x.val.fVal = v1.val.fVal / v2.val.fVal;
        else assert(0);
        return x;
    }
}
//类型转换，这个应该没问题了

Value eval (int l,int r){
    Value x;
    if(l > r){
        x.type = ERROR;
        return x;
        //wrong
    }else if(l == r){
        if(tokens[l].type == 3){//单个一个括号 （如 3+(+4这种，分裂到最后会剩一个单独的‘(’）
            x.type = ERROR;
        }else if(tokens[l].type == 1){//整数
            x.type = INT;
            x.val.iVal = INTnum(l);
        }else if(tokens[l].type == 2){//浮点数
            x.type = DOUBLE;
            x.val.fVal = DOUBLEnum(l);
        }else{//变量,先查表看看这个变量有没有赋值。（变量赋值-->存到表里）
            int location_variable = -1;
            for(int i = 0; assignments[i].name[0] != '\0'; i++){
                if(strcmp(assignments[i].name, tokens[l].str) == 0){
                    location_variable = i;
                    break;
                }
            }
            if(location_variable == -1){
                x.type = ERROR;
            }else{
                if(assignments[location_variable].type == INt){
                    x.type = INT;
                    x.val.iVal = assignments[location_variable].val.iVal;
                }else{
                    x.type = DOUBLE;
                    x.val.fVal = assignments[location_variable].val.fVal;
                }
            }
        }
        return x;
        //single,返回数值或变量的值
    }else if(check_parentheses(l, r) == true){
        return evalAssign(l+1, r-1);
        //是括号表达式的情况
    }else if(tokens[l].str[0] == '-' && findop(l,r) == l){
        x = evalAssign(l+1, r);
        if(x.type == INT) x.val.iVal = - x.val.iVal;
        if(x.type == DOUBLE) x.val.fVal = - x.val.fVal;
        return x;
        // x.type = eval(l+1,l+1).type;
        // if(x.type == INT) x.val.iVal = - eval(l+1,l+1).val.iVal;
        // if(x.type == DOUBLE) x.val.fVal = - eval(l+1,l+1).val.fVal;
        // return x;
        //有负号的情况
    }else{
        int op = findop(l,r);//the position of 主运算符 in the token expression;
        Value val1,val2;
        val1 = evalAssign(l,op-1);
        val2 = evalAssign(op+1,r);
        return meetvalue(val1, val2, tokens[op].str[0]);
    }
}

//合法的表达式不可能把括号拆成一左一右，一定会在某一步通过check函数去掉括号，所以括号不用分裂，最后检查有没有括号，有直接不合法



Value evalAssign(int l, int r){
    int numeq = 0;
    int indexequal = 0;
    for(int i = l; i <= r; i++){
        if(tokens[i].str[0] == '='){
            numeq++;
            indexequal = i;
            break;
        }
    }
    if(numeq == 0){
        return eval(l,r);
    }else{
        int indexequal = -1;
        int kuohao = 0;
        for(int i = l; i <= r; i++){
            if(tokens[i].str[0] == '(') kuohao++;
            if(tokens[i].str[0] == ')') kuohao--;
            if(tokens[i].str[0] == '=' && kuohao == 0){
                indexequal = i;
                break;
            }
        }
        if(indexequal == -1) return eval(l,r);
        Value x = evalAssign(indexequal+1,r);
        if(x.type == ERROR){
            return x;//只关心类型是ERROR
        }else if(tokens[indexequal-1].type != 4 && tokens[indexequal-1].str[0] != ')'){
            x.type = ERROR;
            return x;
        }else if(tokens[indexequal-1].str[0] != ')'){
            if(indexequal != l + 1 || tokens[l].type != 4){
                x.type = ERROR;
                return x;
            }           
            int indexassi = 0;
            for(; assignments[indexassi].name[0] != '\0' && strcmp(assignments[indexassi].name,tokens[indexequal-1].str) != 0; indexassi++);
            strcpy(assignments[indexassi].name,tokens[indexequal-1].str);
            if(x.type == INT){
                assignments[indexassi].type = INt;
                assignments[indexassi].val.iVal = x.val.iVal;
                return x;
            }else{
                assignments[indexassi].type = DOUBLe;
                assignments[indexassi].val.fVal = x.val.fVal;
                return x;
            }
        }else{
            while(check_parentheses(l,indexequal-1) == true){
                l++;indexequal--;
            }
            if(indexequal != l + 1 || tokens[l].type != 4){
                x.type = ERROR;
                return x;
            }
            int indexassi = 0;
            for(; assignments[indexassi].name[0] != '\0' && strcmp(assignments[indexassi].name,tokens[indexequal-1].str) != 0; indexassi++);
            strcpy(assignments[indexassi].name,tokens[indexequal-1].str);
            if(x.type == INT){
                assignments[indexassi].type = INt;
                assignments[indexassi].val.iVal = x.val.iVal;
                return x;
            }else{
                assignments[indexassi].type = DOUBLe;
                assignments[indexassi].val.fVal = x.val.fVal;
                return x;
            }
        }
    }
}


//目前发现的问题：
//1.分母为0（已改正，但是好像测试点没有？）
//2.( 3 - 4 ) - - ( 2 * 3 ), 这个会显示ERROR, - ( 3 )也显示ERROR,应该是同一种问题
//    （但是单把这个改了还是87,估计是相关的这些测试点比较复杂，改动一两个地方没影响）
//3.含有赋值运算符的式子，单赋值运算符如（ a = 3 ）显示ERROR, 以及这个括号前面加个负号
//     多赋值运算符，目前只能处理a = b = c  = 1这种，不能处理带括号的（如a = (b = 1)）
//     更无法处理 a = 3 + 2 * ( c = 3 ) 这种，
//     对于某些不合法的（如 1 + 1 = a = 3）这种，虽然返回了error，但是a仍然被赋值为了3
//总结，目前没发现因为浮点数引起的bug, 不含赋值运算符、不含负号的情况下暂时未发现bug
//      故bug测试点应该主要是负号和赋值，尤其是负号与括号、复杂赋值。

//修改思路：
//    1：负号：一是第一个符号是负号，二是遇见两个连续的符号，按照前面的符号分裂，就可以转化为情况一

//目前这些bug已修正