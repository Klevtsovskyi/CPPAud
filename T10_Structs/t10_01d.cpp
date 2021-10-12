#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;


typedef struct {
    int n;
    double* coef;
} Poly;


Poly input() {
    Poly a;
    cin >> a.n;
    a.coef = (double*) malloc(a.n * sizeof *a.coef);
    for (int i = 0; i < a.n; i++)
        cin >> a.coef[i];
    return a;
}


void print(Poly a) {
    for (int i = 0; i < a.n - 1; i++) {
        cout << a.coef[i] << "x^" << a.n - i - 1 << " + ";
    }
    cout << a.coef[a.n - 1] << endl;
}


void destroy(Poly a) {
    a.n = 0;
    free(a.coef);
}


int main() {
    Poly p = input();
    print(p);
    destroy(p);
    return 0;
}
