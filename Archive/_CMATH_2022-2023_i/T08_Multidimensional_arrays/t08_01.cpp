#include <iostream>
#include <cstdio>
#define N 3
using namespace std;


void print(int arr[][N], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j] << ends;
        }
        cout << endl;
    }
}


void swap(int arr[][N], int i, int j, int ii, int jj){
    int x = arr[i][j];
    arr[i][j] = arr[ii][jj];
    arr[ii][jj] = x;
}


void replace(int arr[][N], int n, int m, int NN, int MM) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == MM) {
                arr[i][j] = NN;
                return;
            }

        }
    }
}


int main() {
    int arr[N][N] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int NN, MM;
    cin >> NN >> MM;
    replace(arr, N, N, NN, MM);
    print(arr, 3, 3);

    return 0;
}
