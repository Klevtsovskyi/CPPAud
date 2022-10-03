#include <iostream>
#include <cstdio>
#include <climits>
#define N 10
using namespace std;


void input(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}


int max_array(int arr[], int n) {
    int max = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}


int main() {
    int n = 5;
    int arr[N];
    input(arr, n);
    cout << max_array(arr, n);
    return 0;
}
