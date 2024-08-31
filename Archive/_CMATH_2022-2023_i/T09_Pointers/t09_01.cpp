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


double sum_squares(double* a, int n) {
    double s = 0;
    for (int i = 0; i < n; i++) {
        s += a[i] * a[i];
    }
    return s;
}


int main() {
    int n;
    cin >> n;
    double *a = input(n);
    print(a, n);
    cout << sum_squares(a, n) << endl;

    free(a);
    return 0;
}
