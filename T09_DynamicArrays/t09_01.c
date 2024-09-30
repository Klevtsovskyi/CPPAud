#include <stdio.h>
#include <stdlib.h>


void print(int* a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%li ", a[i]);
    }
    printf("\n");
}
void input(int* a, int n) {
    for (int i = 0; i < n; i++) {
        scanf("%li", &a[i]);
    }
}
int solve(int* a, int n) {
    int res = 0;
    for (int i = 0; i < n; i++)
        res += a[i] * a[i];
    return res;
}

int main() {
    int n;
    scanf("%li", &n);
    int* a = (int*) malloc(n * sizeof (*a));
    input(a, n);
    print(a, n);
    printf("%li\n", solve(a, n));
    free(a);
    return 0;
}
