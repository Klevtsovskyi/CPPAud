#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;


void print(int* a, int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << ends;
    }
    cout << endl;
}


int input(int** ptr_a) {
    *ptr_a = (int*) malloc(0 * sizeof **ptr_a);
    if (*ptr_a == NULL)
        exit(1);

    int i = 0;
    while (i < 100) {
        int x;
        cin >> x;
        if (x == 0)
            break;

        *ptr_a = (int*) realloc(*ptr_a, (i + 1) * sizeof **ptr_a);
        if (*ptr_a == NULL)
            exit(1);
        (*ptr_a)[i++] = x;
    }
    return i;
}


int full_squares(int* a, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        double sq = sqrt(a[i]);
        if (sq == floor(sq))
            count++;
    }
    return count;
}


int full_cubes(int* a, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        double cb = cbrt(a[i]);
        if (cb == floor(cb))
            count++;
    }
    return count;
}


int main() {
    int* a;
    int n = input(&a);

    print(a, n);
    cout << full_squares(a, n) << endl;
    cout << full_cubes(a, n) << endl;
    free(a);
    return 0;
}
