#include <iostream>
#include <cstdio>
using namespace std;


double f1(double x, int n) {
    double res, a;
    res = 1.0;
    a = 1.0;
    for (int i = 0; i < n; i++) {
        a *= x;
        res += a;
    }
    return res;
}


double f2(double x, double y, int n) {
    double res, a, b;
    res = 1.0;
    a = x;
    b = 1.0;
    for (int i = 0; i < n; i++) {
        a *= a;
        b *= y;
        res += a * b;
    }
    return res;
}


int main() {
    cout << f1(2, 3) << endl;
    cout << f2(2, 1, 3) << endl;
    return 0;
}
