#include <stdio.h>
#include <math.h>
#define _USE_MATH_DEFINES


double f(int n, double d) {
    printf("%p\n", &d);
    return n * d;
}


void g(int n, double* d) {
    printf("%p\n", d);
    *d = n * (*d) + 1;
}


int main() {
    int n = 2;
    double x1 = 0.1 + 0.2;
    printf("%p\n", &x1);
    printf("%.10lf\n", f(n, x1));
    printf("%.10lf\n", x1);
    g(n, &x1);
    printf("%.10lf\n", x1);
    return 0;
}
