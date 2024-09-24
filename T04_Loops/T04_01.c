#include <math.h>
#include <stdio.h>

double f(double x, int n){
    for (int i = 0; i<n; i++) {
        x = sin(x);
    }
    return x;
}

/*
1) y = sin(sin(. . .sin(x). . .)) (n times)
*/
int main() {
    double x;
    x = 3;
    int n;
    n = 5;
    printf("%lf", f(x,n));
    return 0;
}
