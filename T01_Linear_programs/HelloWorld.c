#include <stdio.h>


int main() {
    printf("Hello, World!\n");
    char c;
    short y0;
    unsigned int y1;
    int y2;
    long long y3;
    float x1 = 0.1;
    double x2 = 0.2;
    long double x3;
    scanf("%f\n%lf", &x1, &x2);
    printf("%07.2f %le", x1, x2);
    return 0;
}
