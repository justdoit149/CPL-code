#include <stdio.h>

int main()
{
    char a[1000000];
    int sum = 0;
    for(int i = 0; i < 1000000 && (a[i] = getchar()) != '\n'; i++){
        sum = sum + a[i] - 48;
    }
    printf("%d",sum % 9);
    return 0;
}