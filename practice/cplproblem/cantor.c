#include <stdio.h>

int main()
{
    int N,n1,n2,i,j,i0,j0;
    scanf("%d",&N);
    for(i = 1; i * (2 * i - 1) < N; i++);
    for(j = 1; j * (2 * j + 1) < N; j++);
    i0 = N - (i - 1) * (2 * i - 3);
    j0 = N - (j - 1) * (2 * j - 1);
    n1 = (i0 < 2 * i - 1 ? i0 : 4 * i - 2 - i0);
    n2 = (j0 < 2 * j ? j0 : 4 * j - j0);

    printf("%d/%d",n1,n2);
    return 0;
}