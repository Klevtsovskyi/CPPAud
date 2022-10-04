#include <iostream>
#include <cstdio>
#define N 25
using namespace std;


void print(double arr[][N], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << ends;
        }
        cout << endl;
    }
}


void input(double arr[][N], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
}


void transpose(double arr[][N], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            double x = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = x;
        }
    }

}


int main() {
    int n;
    double arr[N][N];
    cin >> n;
    input(arr, n);
    transpose(arr, n);
    print(arr, n);
    return 0;
}
