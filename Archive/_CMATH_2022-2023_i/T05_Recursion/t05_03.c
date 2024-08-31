#include <stdio.h>


int f(int n) {
    int a = n;
    int i = 0;
    for (; a > 1; i++) {
        // printf("%ld %ld\n", i, a);
        if (a % 2 == 0)
            a = a / 2;
        else
            a = 3 * a + 1;
    }
    return i;
}


int main() {
    int maxv = -1;
    int maxn = -1;
    for (int j = 1; j < 1000; j++) {
        int v = f(j);
        if (v > maxv) {
            maxv = v;
            maxn = j;
        }
    }
    printf("%ld\n", maxn);
    printf("%ld\n", maxv);

    return 0;
}
