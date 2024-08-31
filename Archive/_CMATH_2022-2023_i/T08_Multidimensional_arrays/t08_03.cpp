#include <iostream>
#include <cstdio>
#define N 20
using namespace std;


void print(int arr[][N], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j] << ends;
        }
        cout << endl;
    }
}


void input(int arr[][N], int n, int m){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("a[%ld][%ld] = ", i, j);
            cin >> arr[i][j];
        }
    }
}


int main() {
    int n, m, arr[N][N];
    cin >> n >> m;
    input(arr, n, m);
    print(arr, n, m);
    return 0;
}
