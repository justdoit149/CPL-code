#include <stdio.h>

int Fibonacci(int n); 

int main(void) {
    int n;
    scanf("%d",&n);
    printf("%d",Fibonacci(n));
    return 0;
}

int Fibonacci(int n){
    if(n <= 1) return 1;
    return (Fibonacci(n-1) + Fibonacci(n-2));
}