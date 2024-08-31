#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;


typedef struct {
    int n;
    double *coefs;
} Poly;


Poly input(int n) {
    Poly poly = {.n = n};
    poly.coefs = (double*) malloc(n * sizeof *poly.coefs);
    for (int i = 0; i < n; i++) {
        cin >> poly.coefs[i];
    }
    return poly;
}


void print(Poly poly) {
    printf("%g", poly.coefs[0]);
    for (int i = 1; i < poly.n; i++) {
        printf(" + %gx^%ld", poly.coefs[i], i);
    }
}


int main() {
    Poly poly;
    int n;
    cin >> n;
    poly = input(n);
    print(poly);

    free(poly.coefs);
    return 0;
}
