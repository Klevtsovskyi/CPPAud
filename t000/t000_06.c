#include <stdio.h>


int main()
{
    double F, gamma, m1 ,m2, r;
    gamma = 6.673e-11;
    scanf("%lf %lf %lf", &m1, &m2, &r);
    F = gamma * m1 * m2 / (r * r);
    printf("%3.2e\n", F);
    system("pause");
    return 0;
}
