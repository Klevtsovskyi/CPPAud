#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define N 100


typedef struct {
    double coef;
    int deg;
} Monom;


typedef struct {
    int m;
    Monom monoms[N];
} Poly;


Poly create_poly(double* a, int m) {
    Poly p;
    p.m = 0;
    for (int i = 0; i < m; i++) {
        if (a[i] != 0) {
            Monom monom = {.coef = a[i], .deg = i};
            p.monoms[p.m++] = monom;
        }
    }
    return p;
}


void print_poly(Poly p) {
    int i = 0;
    for (; i < p.m - 1; i++) {
        printf("%gx^%ld + ", p.monoms[i].coef, p.monoms[i].deg);
    }
    printf("%gx^%ld\n", p.monoms[i].coef, p.monoms[i].deg);
}


int main() {
    int n = 4;
    int m = 7;
    double arr[N][N] = {
        {1.0, 2.1, 0.0, 0.0, 0.0, 0.0, -0.1},
        {0.0, -9.2, 0.1, 0.0, 3.6, 0.0, 0.0},
        {0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0},
        {0.0, 6.0, 1.0, 0.0, 0.0, 0.0, 0.0}
    };
    Poly polynoms[N];
    for (int i = 0; i < n; i++) {
        polynoms[i] = create_poly(arr[i], m);
    }
    print_poly(polynoms[0]);

    return 0;
}
