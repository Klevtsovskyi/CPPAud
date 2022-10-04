#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;


int main() {
    int n = 5;
    int* a = (int*) malloc(n * sizeof(*a));
    int* b = (int*) calloc(n, sizeof(*a));

    cout << b << endl;
    for (int i = 0; i < n; i++) {
        b[i] = i + 1;
        cout << b[i] << ends;
    }
    cout << endl;

    b = (int*) realloc(b, (n + 1) * sizeof(*b));
    cout << b << endl;
    for (int i = 0; i < n + 1; i++) {
        cout << b[i] << ends;
    }
    cout << endl;

    free(a);
    free(b);

    printf("%p", nullptr);
    return 0;
}
