#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void print(int* a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%li ", a[i]);
    }
    printf("\n");
}


int input(int** a) {
    *a = (int*) malloc(0 * sizeof (**a));
    int n = 0;
    while (n < 100) {
        int x;
        scanf("%li", &x);
        if (x == 0)
            break;
        *a = (int*) realloc(*a, (n + 1) * sizeof (**a));
        if (*a == NULL)
            exit(1);
        (*a)[n++] = x;
    }
    return n;
}


int full_squares(int* a, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (sqrt(a[i]) == (int) sqrt(a[i]))
            count++;
    }
    return count;
}


int main() {
    int* a;
    int n = input(&a);
    print(a, n);
    printf("%li", full_squares(a, n));
    free(a);
    return 0;
}
