#include <iostream>
#include <cstdio>
#define N 50
using namespace std;


int input(unsigned int arr[]) {
    unsigned int x;
    int i = 0;
    while (true) {
        cin >> x;
        if (x == 0)
            break;
        arr[i++] = x;
    }
    return i;
}


void print(unsigned int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << ends;
    }
    cout << endl;
}


int odd(unsigned int arr[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] & 1)
            count++;
    }
    return count;
}


int even(unsigned int arr[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (!(arr[i] & 1))
            count++;
    }
    return count;
}


int main() {
    unsigned int arr[N];
    int n = input(arr);
    cout << "odd " << odd(arr, n) << endl;
    cout << "even " << even(arr, n) << endl;

    return 0;
}
