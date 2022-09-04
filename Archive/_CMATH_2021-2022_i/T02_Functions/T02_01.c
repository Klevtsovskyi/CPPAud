#include <math.h>
#include <stdio.h>


double my_cos(double x) {
    return cos(x);
}


int main() {
    double x;
    scanf("%lf", &x);
    printf("%lf\n", my_cos(x));
    return 0;
}
