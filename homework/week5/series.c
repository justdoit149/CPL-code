#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    double x,y;
    double sum=0;
    
    scanf("%lf %d",&x,&n);

    for(int i=0;i<=n;i++){
        sum=sum+pow(-1,i)*pow(x,2*i+1)/(2*i+1);
    }

    y=4*sum;
    
    printf("%.10f",y);

    return 0;
}