#include <stdio.h>
// #include <locale.h>
// #include <stdlib.h>
#include <windows.h>


int main() {
    // printf("%s\n", setlocale(LC_ALL, "Ukrainian"));
    // system("chcp 65001");
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    double C, F;
    printf("Введіть число градусів цельсія: ");
    scanf("%lf", &C);
    F = 9 * C / 5 + 32;
    printf("%g", F);
    return 0;
}
