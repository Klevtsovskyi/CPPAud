#include <stdio.h>
// #include <locale.h>
#include <windows.h>
#include <math.h>


int main() {
    // printf("%s\n", setlocale(LC_ALL, "Ukrainian"));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    //system("chcp 1251");
    printf("¬вед≥ть д≥йсне число: ");
    float x;
    scanf("%f", &x);

    float m, d;
    m = modff(x, &d);
    printf("%f %f\n", d, m);
    printf("%ld %ld %ld\n",
           (int) ceil(x) - 1,
           (int) floor(x) + 1,
           (int) round(x)
           );
    int n;
    n = (int) x;
    d = (float) n;
    m = x - d;
    printf("%f %f\n", d, m);
    printf("%ld %ld %ld\n",
           (m < 0.000001 ? n - 1 : n),
           (m > 0.000001 && x < 0 ? n : n + 1),
           (int) (x > 0 ? (x + 0.5) : (x - 0.5))
           );
    return 0;
}
