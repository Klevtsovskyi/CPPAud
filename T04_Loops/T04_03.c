
#include <stdio.h>
double f(double x, int n){
    int a = 1,s = 1;
    for (int i = 0; i<n; i++){
        a *= x;
        s += a;
    }
    return s;
}

double g(double x, double y, int n){
    int b = 1, a = 1,s = 1;
    for (int i = 0; i<n; i++){
        a *= x*x;
        b *= y;
        s += a * b;

    }
    return s;
}
int main() {
    double x, y;
    int n;
    scanf("%ld %lf %lf", &n, &x, &y);
    printf("%ld %lf\n", n, x);
    printf("%lf %lf\n", f(x,n), g(x, y,n));
    return 0;
}
