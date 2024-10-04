#include <stdio.h>
#include <stdlib.h>


int** create_matrix(int n, int m) {
    int** matrix = (int**) calloc(n, sizeof(*matrix));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int*) calloc(m, sizeof(**matrix));
    }
    return matrix;
}
void delete_matrix(int** matrix,  int n, int m) {
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
}
void input(int** matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%li", &matrix[i][j]);
        }
    }
}
void print(int** matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%li ", matrix[i][j]);
        }
        printf("\n");
    }
}
int** product(int** A, int** B, int n, int m, int l) {
    int** C = create_matrix(n, l);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < l; j++) {
            for (int k = 0; k < m; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}


int main() {
    system("color 70");
    int n = 2;
    int m = 3;
    int l = 2;

    int** A = create_matrix(n, m);
    int** B = create_matrix(m, l);
    input(A, n, m);
    input(B, m, l);

    int** C = product(A, B, n, m, l);
    print(C, n, l);
    delete_matrix(A, n, m);
    delete_matrix(B, m, l);
    delete_matrix(C, n, l);

    return 0;
}
