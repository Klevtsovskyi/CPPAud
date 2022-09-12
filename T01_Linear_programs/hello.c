#include <stdio.h>


int main() {
    printf("Hello, World!\n");

    char d = 65;
    printf("%c %i\n", d, sizeof(d));

    unsigned short a = 0;
    printf("%i\n", sizeof(a));

    long b = 0;
    printf("%i\n", sizeof(b));

    long long c = 0;
    printf("%i\n", sizeof(c));

    float f = 43.5261;
    printf("%i\n", sizeof(f));

    double lf = 0;
    printf("%i\n", sizeof(lf));

    double llf = 1.31;
    printf("%i\n", sizeof(llf));

    scanf("%f\n%lf", &f, &lf);
    printf("%.2lf\n", f);
    printf("%e\n", lf);

    return 0;
}
