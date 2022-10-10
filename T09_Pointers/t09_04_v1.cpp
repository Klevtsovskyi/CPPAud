#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;


double** create_matrix(int n) {
    double **a = (double**) calloc(n, sizeof *a);
    if (a == NULL)
        exit(1);
    for (int i = 0; i < n; i++) {
        a[i] = (double*) calloc(n, sizeof *a[i]);
        if (a[i] == NULL)
            exit(1);
    }
    return a;
}


void delete_matrix(double** a, int n) {
    for (int i = 0; i < n; i++) {
        free(a[i]);
    }
    free(a);
}


double** input_matrix(int n) {
    double **a = create_matrix(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    return a;
}


void print_matrix(double** a, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << ends;
        }
        cout << endl;
    }
    cout << endl;
}


double** product(double** a, double** b, int n) {
    double **c = create_matrix(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return c;
}


int main() {
    int n;
    cin >> n;
    double **a = input_matrix(n);
    double **b = input_matrix(n);
    double **c = product(a, b, n);
    print_matrix(c, n);

    delete_matrix(a, n);
    delete_matrix(b, n);
    delete_matrix(c, n);
    return 0;
}
