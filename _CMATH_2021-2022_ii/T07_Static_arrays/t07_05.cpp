#include <iostream>
#include <cstdio>
#define N 20
using namespace std;


void input(unsigned int *a, int n) {
    for (int i = 0; i < n; i++)
        cin >> a[i];
}


void print(unsigned int *a, int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << ends;
    cout << endl;
}


unsigned int sum_odd(unsigned int *a, int n) {
    unsigned int s = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] & 1)
            s += a[i];
    }
    return s;
}


unsigned int sum_even(unsigned int *a, int n) {
    unsigned int s = 0;
    for (int i = 0; i < n; i++) {
        if (!(a[i] & 1))
            s += a[i];
    }
    return s;
}


int main() {
    int n;
    cin >> n;
    unsigned int arr[N];
    input(arr, n);
    print(arr, n);
    cout << sum_odd(arr, n) << endl;
    cout << sum_even(arr, n) << endl;
    return 0;
}
