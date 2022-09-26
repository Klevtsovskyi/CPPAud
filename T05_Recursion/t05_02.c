#include <stdio.h>


int fact(int n) {
    int f = 1;
    for (int k = 1; k <= n; k++) {
        f = k * f;
    }
    return f;
}


int factr(int n) {
    if (n == 0)
        return 1;
    else
        return n * factr(n - 1);
}


int fiba(int n) {
    int f0, f1, f2;
    f0 = 0;
    f1 = 1;
    for (int i = 0; i < n; i++) {
        f2 = f1 + f0;
        f0 = f1;
        f1 = f2;
    }
    return f0;
}


int fibr(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fibr(n - 1) + fibr(n - 2);
}


int fibb(double a) {
    int f0, f1, f2;
    f0 = 0;
    f1 = 1;
    int i = 0;
    for (; f1 < a; i++) {
        f2 = f1 + f0;
        f0 = f1;
        f1 = f2;
    }
    return i;
}


int fibc(double a) {
    int f0, f1, f2;
    f0 = 0;
    f1 = 1;
    int i = 0;
    for (; f0 <= a; i++) {
        f2 = f1 + f0;
        f0 = f1;
        f1 = f2;
    }

    return i;
}


int fibd() {
    int f0, f1, f2, s;
    s = 0;
    f0 = 0;
    f1 = 1;
    for (int i = 0; f1 < 1000; i++) {
        f2 = f1 + f0;
        f0 = f1;
        f1 = f2;
        s += f0;
        // printf("%ld\n", f0);
    }
    return s;
}


int main() {
    printf("%ld\n", fibd());
    return 0;
}
