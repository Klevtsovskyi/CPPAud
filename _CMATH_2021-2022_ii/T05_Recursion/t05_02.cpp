#include <iostream>
#include <cstdio>
using namespace std;

int fiba_rec(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return
        fiba_rec(n - 1) + fiba_rec(n - 2);
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

int fibb(int a) {
    int i;
    int f0, f1, f2;
    f0 = 0;
    f1 = 1;
    for (i = 0; f1 <= a; i++) {
        f2 = f1 + f0;
        f0 = f1;
        f1 = f2;
    }
    return i;
}

int fibc(int a) {
    int i;
    int f0, f1, f2;
    f0 = 0;
    f1 = 1;
    for (i = 0; f0 <= a; i++) {
        f2 = f1 + f0;
        f0 = f1;
        f1 = f2;
    }
    return i;
}

int fibd(int a=1000) {
    int s = 0;
    int f0, f1, f2;
    f0 = 0;
    f1 = 1;
    while (f0 <= a) {
        s += f0;
        f2 = f1 + f0;
        f0 = f1;
        f1 = f2;
    }
    return s;
}


int main() {
    cout << fiba_rec(7) << endl;
    cout << fiba(7) << endl;
    cout << fibb(6) << endl;
    cout << fibc(6) << endl;
    cout << fibd() << endl;

    return 0;
}
