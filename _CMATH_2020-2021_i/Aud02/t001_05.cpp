#include <iostream>


using namespace std;


int main()
{
    float A, B, C, a, h;
    scanf("A=7%f, B=7%e, C=7%f", &A, &B, &C);
    a = (A + B + C) / 3;
    h = 1 / (1 / A + 1 / B + 1 / C);
    printf("a = %f\n", a);
    printf("a = %e\n", a);
    printf("h = %f\n", h);
    printf("h = %e\n", h);
    return 0;
}
