#include <stdio.h>
#include <math.h>

int a[21] = {0};
int n,p;
double l,r;

double f(double x);
double S(double l,double r);
double sigma(double L,double R,double delta);

int main(){
    scanf("%d%d",&n,&p);
    for(int i = 0; i <= n; i++){
        scanf("%d",&a[i]);
    }
    scanf("%lf%lf",&l,&r);
    printf("%f",sigma(l,r,0.0001));
    return 0;
}

double f(double x){
    double sum = a[0];
    for(int i = n; i > 0; i--){
        sum = sum + a[i] * pow(x,i);
    }
    return pow(sum,p);
}

double S(double l,double r){
    return (4 * f((l+r)/2) + f(l) + f(r)) / 6 * (r - l);
}

double sigma(double L,double R,double delta){
    double mid = (L + R) / 2;
    if(fabs(S(L,mid) + S(mid,R) - S(L,R)) <= 15 * delta){
        return S(L,mid) + S(mid,R) + (S(L,mid) + S(mid,R) - S(L,R)) / 15;
    }
    return sigma(L,mid,delta/2) + sigma(mid,R,delta/2);

}