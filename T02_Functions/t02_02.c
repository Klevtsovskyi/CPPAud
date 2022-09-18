#include <stdio.h>
#include <math.h>


double my_hypot(double a, double b) {
    double c = sqrt(pow(a, 2) + pow(b, 2));
    return c;
}


int main() {
    double a, b;
    scanf("%lf %lf", &a, &b);
    printf("%lf\n", my_hypot(a, b));
    printf("%lf\n", hypot(a, b));
    return 0;
}
