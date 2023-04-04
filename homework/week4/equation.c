#include <stdio.h>
#include <math.h>

int main()
{
    int p,q;
    double x1,n1,n2,x,y;

    scanf("%d %d",&p,&q);

    n1=-q/2.0+sqrt(pow(q*1.0/2,2)+pow(p*1.0/3,3));
    n2=-q/2.0-sqrt(pow(q*1.0/2,2)+pow(p*1.0/3,3));
    if(n1>0){x=pow(n1,1.0/3);}
    else if(n1<0){x=-pow(-n1,1.0/3);}
    else{x=0;}
    if(n2>0){y=pow(n2,1.0/3);}
    else if(n2<0){y=-pow(-n2,1.0/3);}
    else{y=0;}
   
   
    x1=x+y;

    printf("%.3f",x1);

    return 0;
}