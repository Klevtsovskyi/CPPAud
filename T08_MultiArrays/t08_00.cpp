#include <iostream>
#include <cstdio>  // stdio.h
#define N 10
#define M 5
using namespace std;

void print(int matrix[][M], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%i ", *(*(matrix + i) + j));
        }
        printf("\n");
    }
}

void print_ptr(int matrix[][M], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%p ", &matrix[i][j]);
        }
        printf("\n");
    }
}


void input(int matrix[][M], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%i", &matrix[i][j]);
        }
    }
}


int main() {
    int matrix[N][M] = {
        {1, 2, 3},
        {2, 3, 4},
        {3, 4, 5}
    };
    input(matrix, 3, 3);
    print(matrix, 3, 3);
    return 0;
}
