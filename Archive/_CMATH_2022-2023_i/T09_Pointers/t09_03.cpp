#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;


double* input(int n) {
    double *a = (double*) malloc(n * sizeof (*a));
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    return a;
}


void print(double* a, int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << ends;
    }
    cout << endl;
}


double* substract(double* a, double* b, int n) {
    double *c = (double*) calloc(n, sizeof *c);
    for (int i = 0; i < n; i ++) {
        c[i] = a[i] - b[i];
    }
    return c;
}


int main() {
    int n;
    cin >> n;
    double *a = input(n);
    double *b = input(n);
    double *c = substract(a, b, n);
    print(c, n);

    free(a);
    free(b);
    free(c);
    return 0;
}
