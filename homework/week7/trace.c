#include <stdio.h>

int main()
{
    int n,m,x0,y0, count = 0;
    char a[52][52];
    for(int i = 0; i < 52; i++){
        for(int j = 0; j < 52; j++){
            a[i][j] = '_';
        }
    }
    scanf("%d%d%d%d",&n,&m,&x0,&y0);
    getchar();

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            a[i][j] = getchar();
            count = count + (a[i][j] == '#');
        }
        getchar();
    }
    printf("%d\n",count);

    while(count > 0){
        printf("%d %d\n",x0,y0);    //输出当前所在点
        a[x0][y0] = '_';            //重置当前所在点
        if(a[x0+1][y0] == '#') x0 = x0 + 1;
        else if(a[x0-1][y0] == '#') x0 = x0 - 1;
        else if(a[x0][y0+1] == '#') y0 = y0 + 1;
        else if(a[x0][y0-1] == '#') y0 = y0 - 1; //移动
        count--;    //计步
    }
    
    return 0;
}