#include <stdio.h>
#include <math.h>

int main()
{
    double a=4*atan(1.0/5)-atan(1.0/239);
    double b=log(pow(640320,3)+744)/sqrt(163);
    printf("%.15f\n%.15f\n",4*a,b);

    return 0;
}