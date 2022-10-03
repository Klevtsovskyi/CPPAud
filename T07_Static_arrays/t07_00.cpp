#include <iostream>
#include <cstdio>
#define N 10
using namespace std;


void input(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}


void print(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << ends;
        // cout << &arr[i] << endl;
    }
    cout << endl;
}


int main() {
    int n = 3;
    int arr[N];
    input(arr, n);
    print(arr, n);
    // cout << arr << endl;
    return 0;
}
