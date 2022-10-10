#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;


double* create_matrix(int n) {
    double *a = (double*) calloc(n * n, sizeof *a);
    return a;
}


double* input_matrix(int n) {
    double *a = create_matrix(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i * n + j];
        }
    }
    return a;
}


void print_matrix(double* a, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i * n + j] << ends;
        }
        cout << endl;
    }
    cout << endl;
}


double* product(double* a, double* b, int n) {
    double *c = create_matrix(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                c[i * n + j] += a[i * n + k] * b[k * n + j];
            }
        }
    }
    return c;
}


int main() {
    int n;
    cin >> n;
    double *a = input_matrix(n);
    double *b = input_matrix(n);
    double *c = product(a, b, n);
    print_matrix(c, n);

    free(a);
    free(b);
    free(c);
    return 0;
}
