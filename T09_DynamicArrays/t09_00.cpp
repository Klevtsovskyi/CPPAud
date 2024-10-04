#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;


void print(int* a, int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
        // cout << *(a + i) << ' ';
    }
    cout << endl;
}
void input(int* a, int n) {
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

void dynamic_array_c() {
    int n;
    cin >> n;
    // int* a = (int*) malloc(n * sizeof (*a));
    int* a = (int*) calloc(n, sizeof (*a));
    if (a == NULL)
        exit(1);
    print(a, n);
    // input(a, n);
    // print(a, n);
    int* b = (int*) realloc(a, (n + 10) * sizeof (*a));
    if (b == NULL)
        exit(1);
    cout << a << ' ';
    cout << b << ' ';
    // print(b, n + 1);
    free(b);
}
void dynamic_array_cpp() {
    int n;
    cin >> n;
    int* a = new int[n];
    int* x = new int();
    input(a, n);
    print(a, n);
    cout << *x << endl;
    delete[] a;
    delete x;
}

int main() {
    // dynamic_array_c();
    dynamic_array_cpp();
    return 0;
}
