#include <stdio.h>

int main()
{
    int n,left,right;
    char a[100]={' '};
    int b[100]={0};

    for(int i = 0,j = 0; i < 100; i ++){
        if(j >= 100){
            j = j - 89;
            b[i] = j - 10;  
            continue;  
        }else{
            b[i] = j;
            j = j + 10;
        }
    }
//逆序操作

//(这段的初衷是给b数组赋值乘0到100每一个数翻转后的结果，但完全没有必要，直接在输出阶段对原数翻转即可得到要输出的数)

    scanf("%d",&n);
    getchar();
    scanf("%s",a);

    for(left = 0,right = n-1; left < right; left++, right--){
        if(a[left]!=a[right]){
            if(a[left] != '?' && a[right] == '?'){
                a[right] = a[left];
            }else if(a[left] == '?' && a[right] != '?'){
                a[left] = a[right];
            }
        }
    }

    int count = 0;
    if(n % 2 == 0){
        for(int i = 0; i < n / 2; i++){
            if(a[i] != '?'){
                putchar(a[i]);
            }else{
                printf("%.2d",count);
                count++;
            }
        }
        for(int i = n / 2; i < n ; i++){
            if(a[i] != '?'){
                putchar(a[i]);
            }else{
                printf("%.2d",b[count - 1]);
                count--;
            }
        }
    }else{
        for(int i = 0; i <= (n - 1) / 2; i++){
            if(a[i] != '?'){
                putchar(a[i]);
            }else{
                printf("%.2d",count);
                count++;
            }
        }
        for(int i = (n + 1) / 2; i < n ; i++){
            if(a[i] != '?'){
                putchar(a[i]);
            }else{
                printf("%.2d",b[count - 1]);
                count--;
            }
        }
    }

    return 0;
}